#include <stdio.h>

void rearrange(int arr[], int n) {
    int idx = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            idx++;
        if (i != idx) {
            int a = arr[i];
        for (int j = i; j > idx; j--) {
            arr[j] = arr[j - 1];
            }
        arr[idx] = a;
        }
    }
    }
}

int main() {

    int arr[] = {12, -7, 5, -3, -1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
