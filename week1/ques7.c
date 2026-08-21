#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6, k = 2;
    int i, j, temp;

    k = k % n;

    for (i = 0; i < k; i++) {
        temp = arr[n - 1];

        for (j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }

        arr[0] = temp;
    }

    printf("Output: ");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
