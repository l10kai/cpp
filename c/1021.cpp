#include <iostream>

using namespace std;

int main() {
    for (int i = 100; i < 1000; ++i) {
        int digit1 = i % 10;
        int digit2 = (i / 10) % 10;
        int digit3 = i / 100;

        int sum = digit1 * digit1 * digit1 + digit2 * digit2 * digit2 + digit3 * digit3 * digit3;

        if (sum == i) {
            cout << i << " ";
        }
    }

    return 0;
}
