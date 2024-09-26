#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
private:
	string Name;
	// string OwnerName;
	int SubscribersCount;
	list<string> PublishedVideoTitles;
protected:
	string OwnerName;
public:
	YouTubeChannel(string name, string ownerName) {
		Name = name;
		OwnerName = ownerName;
		SubscribersCount = 0;
	}
    void GetInfo() {
		cout << "Name: " << Name << endl;
		cout << "OwnerName: " << OwnerName << endl;
		cout << "SubscribersCount: " << SubscribersCount << endl;
		cout << "Videos: " << endl;
		for (string videoTitle : PublishedVideoTitles) {
			cout << videoTitle << endl;
		}
	}
	void Subscribe() {
		SubscribersCount++;
	}
	void Unsubscribe() {
		if (SubscribersCount > 0)
			SubscribersCount--;
	}
	void PublishVideo(string title) {
		PublishedVideoTitles.push_back(title);
	}
};

class CookingYoutubeChannel:public YouTubeChannel{
public:
    CookingYoutubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName){
    }
	void practice(){
		cout << OwnerName << "is practicing cooking, learning new recipes, experimenting with spices...." << endl;
	}

};


int main(){
    CookingYoutubeChannel ytChannel("Hoon's kitchen", "Hoon");
	ytChannel.PublishVideo("Apple pie");
	ytChannel.PublishVideo("Chocolate cake");
	ytChannel.Subscribe();
	ytChannel.Subscribe();
    ytChannel.GetInfo();
	ytChannel.practice();


    system("pause>0");
}