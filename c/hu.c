#include <stdio.h>

void countCharacters(char *str) {
    int letterCount = 0;
    int digitCount = 0;
    int spaceCount = 0;
    int otherCount = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            letterCount++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            digitCount++;
        } else if (str[i] == ' ') {
            spaceCount++;
        } else {
            otherCount++;
        }
    }

    printf("%d %d %d %d\n", letterCount, digitCount, spaceCount, otherCount);
}

int main() {
    char input[1000];
    scanf("%[^\n]", input);

    countCharacters(input);

    return 0;
}
