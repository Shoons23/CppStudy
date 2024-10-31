// SFML(https://www.sfml-dev.org/)은 
// 멀티미디어 응용 프로그램을 위한 오픈 소스 라이브러리
#include <SFML/Audio.hpp>
#include <mpg123.h> // libmpg123 install for mp3 file
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <dirent.h>
#include <algorithm>
using namespace std;

// 필요한 데이터 멤버를 가지는 구조체 정의 

template <typename T>
struct cir_list_node
{
    T* data;
    cir_list_node* next;
    cir_list_node* prev;


    cir_list_node(T* data = nullptr, cir_list_node* next = nullptr, cir_list_node* prev = nullptr) 
        : data(data), next(next), prev(prev) {}
    // node가 소멸될 때 메모리 해제
    ~cir_list_node(){
        delete data;
    } 
};

// 원형 리스트 
template <typename T>
struct cir_list
{
public:
    using node = cir_list_node<T>;
    using node_ptr = node*;

    // 기본 생성자
    cir_list() : n(0){
        head = new node (NULL, NULL, NULL); //  head가 리스트의 시작과 끝을 가르킴
        head->data = nullptr; // 데이터 초기화 x
        head->next = head;
        head->prev = head;
    }
    // 소멸자
    ~cir_list() {
        clear();
        delete head; // head 노드 삭제
    }


    void insert(const T& value) {
        node_ptr newNode = new node();
        newNode->data = new T(value);
        newNode->next = head;
        newNode->prev = head->prev;

        head->prev->next = newNode;
        head->prev = newNode;
        n++;
    }

    void erase(const T& value) {
        node_ptr current = head->next;
        while (current != head) {
            if (*(current->data) == value) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                n--;
                return;
            }
            current = current->next;
        }
    }

    void clear() {
        node_ptr current = head->next;
        while (current != head) {
            node_ptr toDelete = current;
            current = current->next;
            delete toDelete;
        }
        n = 0; // 크기 초기화
        head->next = head; // 리스트 비우기
        head->prev = head;
    }

    class Iterator {
    public:
        Iterator(node_ptr ptr) : current(ptr) {}

        T& operator*() { return *(current->data); }
        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    private:
        node_ptr current;
    };

    Iterator begin() {
        return Iterator(head->next);
    }

    Iterator end() {
        return Iterator(head); // end()는 head 노드를 가리킴
    }
    
    size_t size() const{
        return n;
    }

private:
    node_ptr head; // 순환리스트 구조 
    size_t n;
};


// MP3Stream 클래스 정의
class MP3Stream : public sf::SoundStream {
public:
    MP3Stream() : mh(nullptr), bufferSize(4096), buffer(bufferSize) {}

    bool openFromFile(const std::string& filename) {
        if (mpg123_init() != MPG123_OK || (mh = mpg123_new(nullptr, &err)) == nullptr) {
            std::cerr << "mpg123 초기화 실패: " << mpg123_plain_strerror(err) << std::endl;
            return false;
        }

        if (mpg123_open(mh, filename.c_str()) != MPG123_OK || mpg123_getformat(mh, &rate, &channels, &encoding) != MPG123_OK) {
            std::cerr << "MP3 파일 열기 실패: " << filename << std::endl;
            return false;
        }

        initialize(channels, rate);
        return true;
    }

    ~MP3Stream() {
        if (mh != nullptr) {
            mpg123_close(mh);
            mpg123_delete(mh);
            mpg123_exit();
        }
    }

protected:
    virtual bool onGetData(Chunk& data) override {
        size_t bytesRead;
        if (mpg123_read(mh, buffer.data(), bufferSize, &bytesRead) == MPG123_OK) {
            data.samples = buffer.data();
            data.sampleCount = bytesRead / sizeof(short);
            return true;
        }
        return false;
    }

    virtual void onSeek(sf::Time timeOffset) override {
        mpg123_seek(mh, rate * timeOffset.asSeconds(), SEEK_SET);
    }

private:
    mpg123_handle* mh;
    int err;
    long rate;
    int channels, encoding;
    const size_t bufferSize;
    std::vector<short> buffer;
};

// playlist 구조체 정의
struct playlist {
    cir_list<string> songs; 

    void insert(const string& song) { songs.insert(song); }
    void erase(const string& song) { songs.erase(song); }

    // 파일 확장자를 기반으로 재생
    void playAll() {
        size_t size = songs.size();
        auto it = songs.begin(); // 반복자 초기화


        for (size_t i = 0; i<size; ++i) {
            const auto& song = *it;
            
            // 파일 확장자 검사
            if (song.size() >= 4 && song.substr(song.size() - 4) == ".wav") {
                sf::Music music;
                if (!music.openFromFile(song)) {
                    cout << "WAV 파일을 열 수 없습니다: " << song << endl;
                    continue;
                }
                cout << "재생 중 (WAV): " << song << endl;
                music.play();

                while (music.getStatus() == sf::Music::Playing) {
                    sf::sleep(sf::milliseconds(100));
                }
            }
            else if (song.size() >= 4 && song.substr(song.size() - 4) == ".mp3") {
                MP3Stream mp3;
                if (!mp3.openFromFile(song)) {
                    cout << "MP3 파일을 열 수 없습니다: " << song << endl;
                    continue;
                }
                cout << "재생 중 (MP3): " << song << endl;
                mp3.play();

                while (mp3.getStatus() == sf::SoundStream::Playing) {
                    sf::sleep(sf::milliseconds(100));
                }
            }
        }
    }
};

// 디렉토리에서 WAV 및 MP3 파일 가져와 정렬
vector<string> getAudioFiles(const string& directory) {
    vector<string> audioFiles;
    struct dirent* entry;
    DIR* dp = opendir(directory.c_str());

    if (dp == nullptr) {
        cerr << "디렉토리를 열 수 없습니다: " << directory << std::endl;
        return audioFiles;
    }

    while ((entry = readdir(dp))) {
        string fileName = entry->d_name;
        if ((fileName.size() > 4 && (fileName.substr(fileName.size() - 4) == ".wav" ||
                                     fileName.substr(fileName.size() - 4) == ".mp3"))) {
            audioFiles.push_back(directory + "/" + fileName);
        }
    }
    closedir(dp);

    // sort(audioFiles.begin(), audioFiles.end());
    return audioFiles;
}


int main() {
    playlist pl;
    string directory = "./miniProject/musicPlay/music/"; // WAV 파일이 있는 디렉토리

    // 디렉토리에서 WAV 파일을 가져와 재생 목록에 추가
    vector<string> autoFiles = getAudioFiles(directory);
    for (const auto& file : autoFiles) {
        pl.insert(file);
    }

    cout << "재생 목록:" << endl;
    pl.playAll();

    return 0;
}


/* build

g++ ./miniProject/musicPlay/musicPlayer.cpp -o ./miniProject/musicPlay/music-player -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lmpg123

run 

./miniProject/musicPlay/music-player

*/