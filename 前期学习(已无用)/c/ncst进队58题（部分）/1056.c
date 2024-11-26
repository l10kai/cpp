#include <stdio.h>

int huan(int n) {
    int all[100];
    for (int i = 0; i < n; i++) {
        all[i] = 1;
    }

    int count = 0;
    int less = n;
    int t = 0;

    while (less > 1) {
        if (all[t] == 1) {
            count++;
            }
            if (count == 3) {
                all[t] = 0;
                less--;
                count = 0;
            }
                    t = (t + 1) % n;
        }


    for (int i = 0; i < n; i++) {
        if (all[i] == 1) {
            return i + 1; 
        }
    }

}


int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", huan(n));
    return 0;
}
