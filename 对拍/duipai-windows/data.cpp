#include <bits/stdc++.h>

#define cin  fin
#define cout fout
std::ofstream fout("E:/Cpp/duipai/in.txt");

// 用于生成随机数的函数，范围在[min, max]之间
int generateRandomInt(int min, int max) {
    return min + std::rand() % (max - min + 1);
}

using namespace std;

void generateRandomTestCases() {
    // 设置随机数种子
    std::srand(std::time(0));

    // 需要改写部分 ---------------------------------------

    int t = generateRandomInt(1, 1000);  // 生成t，1 ≤ t ≤ 1000
    cout << t << std::endl;

    int totalMonths = 0;
    for (int i = 0; i < t; ++i) {
        int m = generateRandomInt(1, 50);         // 生成m，1 ≤ m ≤ 50
        int x = generateRandomInt(1, 100000000);  // 生成x，1 ≤ x ≤ 10^8

        totalMonths += m;
        if (totalMonths > 100000) {
            // 如果超过限制，调整最后一个测试用例的m使其符合条件
            m -= (totalMonths - 100000);
            totalMonths = 100000;
        }

        cout << m << " " << x << std::endl;

        for (int j = 0; j < m; ++j) {
            int ci = generateRandomInt(0, 100000000);  // 生成ci，0 ≤ ci ≤ 10^8
            int hi = generateRandomInt(1, 1000);  // 生成hi，1 ≤ hi ≤ 1000

            cout << ci << " " << hi << std::endl;
        }

        if (totalMonths == 100000)
            break;  // 达到限制时停止生成测试用例
    }

    //----------------------------------------------------------
}

int main() {
    generateRandomTestCases();
    fout.close();
    return 0;
}
