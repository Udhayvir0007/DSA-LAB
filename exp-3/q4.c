#include <stdio.h>
#include <stdbool.h>

void eqm(int arr[], int n) {
    int total_sum = 0;
    int left_sum = 0;
    bool is_found = false;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }
    for (int i = 0; i < n; i++) {
    int right_sum = total_sum - left_sum - arr[i];
    if (left_sum == right_sum) {
            printf("%d ", i);
            is_found= true;
        }
        left_sum += arr[i];
    }

    if (!is_found) {
        printf("not found..");
    }
    printf("\n");
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    eqm(arr, n);

    return 0;
}

