#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int leftmark = low + 1;
    int rightmark = high;

    while (1)
    {
        while (leftmark <= rightmark && arr[leftmark] <= pivot)
            leftmark++;

        while (leftmark <= rightmark && arr[rightmark] >= pivot)
            rightmark--;

        if (leftmark < rightmark)
            swap(&arr[leftmark], &arr[rightmark]);
        else
            break;
    }

    swap(&arr[low], &arr[rightmark]);

    return rightmark;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    quickSort(arr, 0, n - 1);

    printf("\n\nAfter sorting:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}