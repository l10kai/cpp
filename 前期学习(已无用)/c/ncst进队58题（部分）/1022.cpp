#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int num = 2; num <= N; ++num) {
        int sum = 1;  // 1是所有数的因子，所以初始化为1

        // 找出因子并计算和
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                sum += i;
            }
        }

        // 判断是否为完数并输出
        if (sum == num) {
            cout << num << " its factors are 1 ";
            for (int i = 2; i <= num / 2; ++i) {
                if (num % i == 0) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
