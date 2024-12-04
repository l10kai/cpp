
#include <iostream>

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countAlmostPrimes(int n) {
    int count = 0;
    for (int i = 5; i <= n; ++i) {
        int primeFactors = 0;
        for (int j = 2; j <= i / 2; ++j) {
            if (isPrime(j) && i % j == 0) {
                primeFactors++;
                if (primeFactors > 2) {
                    break;
                }
            }
        }
        if (primeFactors == 2) {
            count++;
        }
    }
    return count;
}

int main() {
    int r;
    std::cin >> r;

    if (r <= 4) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << countAlmostPrimes(r) << std::endl;
    }

    return 0;
}
