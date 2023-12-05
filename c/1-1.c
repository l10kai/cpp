#include <stdio.h>
#include <string.h>

int main() {
    char str[3][100]; // 假设每个字符串的最大长度不超过100个字符

    // 输入三个字符串
    for (int i = 0; i < 3; i++) {
        scanf("%s", str[i]);
    }

    // 使用冒泡排序按照字典序排序字符串数组
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (strcmp(str[j], str[j + 1]) > 0) {
                char temp[100];
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }

    // 输出排序后的字符串
    for (int i = 0; i < 3; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}
    