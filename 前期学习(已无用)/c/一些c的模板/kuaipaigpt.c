#include <stdio.h>

void quicksort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }

    int key = a[left];
    int l = left;
    int r = right;

    while (l != r) {
        while (a[r] >= key && l < r) {
            r--;
        }
        while (a[l] <= key && l < r) {
            l++;
        }
        if (l != r) {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
    }

    a[left] = a[l];
    a[l] = key;

    quicksort(a, left, l - 1);
    quicksort(a, l + 1, right);
}

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
