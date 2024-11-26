#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 定义一个字符串表示七种颜色
    string colors = "ROYGBIV";

    // 输出前面7个颜色
    for (int i = 0; i < 7; i++) {
        cout << colors[i];
        n--;
    }

    // 输出额外的颜色，按照循环的方式
    for (int i = 0; n > 0; i++) {
        cout << colors[i % 4 + 3]; // 使用循环来选择颜色
        n--;
    }

    cout << endl;

    return 0;
}
