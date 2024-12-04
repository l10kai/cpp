#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    double sum1 = 0.0;
    double sum2 = 0.0;
    double sum3 = 0.0;

    // 计算第一个数列的和
    for (int i = 1; i <= a; ++i) {
        sum1 += i;
    }

    // 计算第二个数列的和
    for (int i = 1; i <= b; ++i) {
        sum2 += i * i;
    }

    // 计算第三个数列的和
    for (int i = 1; i <= c; ++i) {
        sum3 += 1.0 / i;
    }

    // 计算总和，并保留两位小数输出
    double result = sum1 + sum2 + sum3;
    //cout << fixed << setprecision(2) << result << endl;
    printf("%.2lf\n",result);
    return 0;
}
