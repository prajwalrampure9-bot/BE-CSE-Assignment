#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, i;
    int max, min, sum = 0;
    float average;
    int search, count = 0;
    int temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("\nMaximum = %d", max);
    printf("\nMinimum = %d", min);

    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    printf("\nSum = %d", sum);

    average = (float)sum / n;

    printf("\nAverage = %.2f", average);

    printf("\nEnter element to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            printf("Found at index %d\n", i);
            count++;
        }
    }

    if (count == 0)
        printf("Element not found\n");

    printf("Frequency = %d", count);


    for (i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("\nReversed array: ");

    for (i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}