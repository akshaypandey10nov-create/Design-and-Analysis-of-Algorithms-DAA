#include <stdio.h>
#include <time.h>

unsigned long long factorialIterative(int n)
{
    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

unsigned long long factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main()
{
    int n;
    unsigned long long result1, result2;
    clock_t start, end;
    double timeIterative, timeRecursive;

    printf("Enter a number: ");
    scanf("%d", &n);

    start = clock();
    result1 = factorialIterative(n);
    end = clock();

    timeIterative = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    result2 = factorialRecursive(n);
    end = clock();

    timeRecursive = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nFactorial using Iteration = %llu", result1);
    printf("\nFactorial using Recursion = %llu", result2);

    printf("\n\nTime taken by Iterative Method = %f seconds", timeIterative);
    printf("\nTime taken by Recursive Method = %f seconds", timeRecursive);

    return 0;
}
