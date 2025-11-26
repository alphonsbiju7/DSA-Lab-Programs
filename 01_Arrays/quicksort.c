#include <stdio.h>

int partition(int A[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = low;

    while (i < j)
    {
        while (i < high && A[i] <= A[pivot])
            i++;

        while (A[j] > A[pivot])
            j--;

        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[pivot];
    A[pivot] = A[j];
    A[j] = temp;

    return j;
}

void quicksort(int A[], int low, int high)
{
    if (low < high)
    {
        int j = partition(A, low, high);
        quicksort(A, low, j - 1);
        quicksort(A, j + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    quicksort(A, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}

