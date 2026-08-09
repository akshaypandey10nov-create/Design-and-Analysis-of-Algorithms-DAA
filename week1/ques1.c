//write a c program to find the second-largest distinct elemnt in an array without sorting the array.
#include <stdio.h>
int main()
{
    int i,n, largest, second_largest;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    largest = arr[0];
    second_largest = arr[0];
    for(i=0; i<n; i++)
    {
        if(arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }
    printf("The second-largest distinct element in the array is: %d", second_largest);
    return 0;
}
