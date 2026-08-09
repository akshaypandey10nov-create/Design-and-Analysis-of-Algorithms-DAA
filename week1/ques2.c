//write a program to count the frequency of each distinct element in an array.
#include <stdio.h>
int main()
{
    int n, i, j, count;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Frequency of each distinct element:\n");
    for(i = 0; i < n; i++) {
        count = 1;
        if(arr[i] != -1) { 
            for(j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1;
                }
            }
            printf("%d occurs %d times\n", arr[i], count);
        }
    }
    
    return 0;
}
