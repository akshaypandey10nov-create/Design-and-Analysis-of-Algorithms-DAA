#include <stdio.h>

int main() {
    int n, bit;
    int ones = 0, zeros = 0;
    int consecutive = 0, maxConsecutive = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == 0) {
        zeros = 1;
    }

    while (n > 0) {
        bit = n % 2;

        if (bit == 1) {
            ones++;
            consecutive++;

            if (consecutive > maxConsecutive)
                maxConsecutive = consecutive;
        } else {
            zeros++;
            consecutive = 0;
        }

        n = n / 2;
    }

    printf("Number of 1s = %d\n", ones);
    printf("Number of 0s = %d\n", zeros);
    printf("Maximum consecutive 1s = %d\n", maxConsecutive);

    return 0;
}
