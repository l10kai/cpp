#include <stdio.h>

int main() {
    int num, digit, sum;
    
    for (num = 100; num <= 999; num++) {
        int originalNum = num;
        sum = 0;

        while (num > 0) {
            digit = num % 10;
            sum += digit * digit * digit;
            num /= 10;
        }

        if (sum == originalNum) {
            printf("%d ", originalNum);
        }
    }

    printf("\n");

    return 0;
}
