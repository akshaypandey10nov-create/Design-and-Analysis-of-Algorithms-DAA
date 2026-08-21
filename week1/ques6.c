#include <stdio.h>

int main() {
    int arr[] = {2, 7, 4, 5, 1, 3};
    int n = 6, target = 6;
    int i, j;

    printf("Pairs whose sum is %d:\n", target);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("(%d, %d) ", arr[i], arr[j]);
            }
        }
    }

    return 0;
}
