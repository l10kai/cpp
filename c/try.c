#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    int m[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);  // 使用正确的索引 i 而不是 n
    }

    int max = 0;
    int num = 2;
    for (int j = 2; j <= 1000; j++) {  // 迭代范围应包括 1000
        int temp = 0;
        for (int k = 0; k < n; k++) {
            if (m[k] % j == 0) {
                temp++;
            }
        }
        if (temp > max) {
            max = temp;
            num = j;
        }
    }
    printf("%d\n", num);

    return 0;
}
