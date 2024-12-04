#include <iostream>

bool digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum==10;
}

int main() {
    int k;
    std::cin >> k;

    int count = 0;
    int num = 1;

    while (count < k) {
        if (digitSum(num)) {
            count++;
        }
        num++;
    }

    std::cout << num - 1 << std::endl;

    return 0;
}
