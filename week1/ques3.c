//write a program to merge two sorted arrays into a single sorted array without using any built-in sorting function.
#include <stdio.h>
int main()
{
    int n1, n2, i, j, k;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter the elements in the first array:\n");
    for(i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter the elements in the second array:\n");
    for(i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int n = n1 + n2;
    int arr[n];
    i = 0,j = 0,k = 0;
    while(i < n1 && j < n2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    printf("Merged array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
