#include <stdlib.h>
#include <stdio.h>

/* 1.0을 중심으로 한 반복 기준점의 상한과 하한 */
static double const eps1m01 = 1.0 - 0x1P-01;
static double const eps1p01 = 1.0 + 0x1P-01;
static double const eps1m24 = 1.0 - 0x1P-24;
static double const eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) { // 커맨드 라인 인수를 처리한다.
        double const a = strtod(argv[i], 0); //　arg -> double
        double x = 1.0;
        for (;;) { // 2의 제곱
            double prod = a * x;
            if (prod < eps1m01) {
                x *= 2.0;
            } else if (eps1p01 < prod) {
                x *= 0.5;
            } else {
                break;
            }
        }
        for (;;) {
            double prod = a * x;
            if ((prod < eps1m24) || (eps1p24 < prod)) {
            x *= (2.0 - prod);
            } else {
                break;
            }
        }
        printf("heron: a=%.5e, \tx=%.5e, \ta*x=%.12f\n", a, x, a*x);
    }

    return EXIT_SUCCESS;
}
