#include <stdio.h>
#include <string.h>

struct student {
    int num;
    char name[100];
    int s1, s2, s3;
};

int main() {
    int n;
    scanf("%d", &n);
    struct student S[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %d %d", &S[i].num, S[i].name, &S[i].s1, &S[i].s2, &S[i].s3);
    }

    for (int i = 0; i < n; i++) {
        printf("%d,%s,%d,%d,%d\n", S[i].num, S[i].name, S[i].s1, S[i].s2, S[i].s3);
    }

    return 0;
}