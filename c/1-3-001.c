#include <stdio.h>

int main() {
    int a[11] = {0}; // 初始化等待人数数组
    int f[11] = {0}; // 初始化目的地人数数组
    int b = 0; // 电梯内人数
    int e = 0; // 电梯运行时间
    int c, g, h;

    do {
        // 电梯下行过程
        for (c = 1; c < 10; c++, e++) {
            b = b - f[c];
            f[c] = 0;

            if (b + a[c] <= 4) {
                b = b + a[c];
                h = h + a[c];
                a[c] = 0;

                for (h = h; h > 0; h--) {
                    printf("To F");
                    scanf("%d", &g);
                    f[g]++;
                }
                printf("%d %d %d\n", c, e, b);
            } else {
                a[c] = a[c] + b - 4;
                h = h + 4 - b;
                b = 4;

                for (h = h; h > 0; h--) {
                    printf("To F");
                    scanf("%d", &g);
                    f[g]++;
                }
                printf("%d %d %d\n", c, e, b);
            }
        }

        // 电梯上行过程
        for (c = 10; c > 1; c--, e++) {
            b = b - f[c];
            f[c] = 0;

            if (b + a[c] <= 4) {
                b = b + a[c];
                h = h + a[c];
                a[c] = 0;

                for (h = h; h > 0; h--) {
                    printf("To F");
                    scanf("%d", &g);
                    f[g]++;
                }
                printf("%d %d %d\n", c, e, b);
            } else {
                a[c] = a[c] + b - 4;
                h = h + 4 - b;
                b = 4;

                for (h = h; h > 0; h--) {
                    printf("To F");
                    scanf("%d", &g);
                    f[g]++;
                }
                printf("%d %d %d\n", c, e, b);
            }
        }

        // 用户输入每层等待人数
        for (c = 1; c <= 10; c++) {
            printf("From F%d?\n", c);
            scanf("%d", &a[c]);
        }

    } while (a[1] != 0 || a[2] != 0 || a[3] != 0 || a[4] != 0 || a[5] != 0 || a[6] != 0 || a[7] != 0 || a[8] != 0 || a[9] != 0 || a[10] != 0);

    return 0;
}

