#include <stdio.h>
#include <string.h>

int op(char c) {

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void pro(char *ly) {
    int length = strlen(ly);

    for (int i = 0; i < length; i++) {
        if (op(ly[i])) {

            ly[i] = to(ly[i]);
        } else {

            ly[i] = to(ly[i]);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        char lyrics[51];
        scanf("%s", ly);
        pro(lyrics);
        printf("%s\n", ly);
    }

    return 0;
}