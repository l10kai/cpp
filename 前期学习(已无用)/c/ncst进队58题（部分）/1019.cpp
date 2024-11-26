
#include <iostream>

using namespace std;

using i64 = long long;

i64 factorial(i64 num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main() {
    int n;
    cin >> n;

    i64 sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += factorial(i);
    }

    cout << sum << endl;

    return 0;
}
