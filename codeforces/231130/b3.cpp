#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;  // 读取测试用例数量

    while (t--) {
        int n;
        cin >> n;  // 读取蛋糕层数

        int cream[200000];  // 最大可能的数组大小
        for (int i = 0; i < n; ++i) {
            cin >> cream[i];  // 读取每层蛋糕上的奶油量
        }

        int result[200000] = {0};  // 初始化结果数组，初始值为0

        int maxCream = 0;
        for (int i = n - 1; i >= 0; --i) {
            maxCream = max(maxCream, cream[i]);  // 更新最大奶油量
            if (maxCream > 0) {
                result[i] = 1;  // 如果有奶油剩余，标记该层被淋湿
                maxCream--;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";  // 打印结果
        }
        cout << endl;
    }

    return 0;
}
