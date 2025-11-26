#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int b[], int low, int mid, int high)
{
    int x = low;
    int y = mid + 1;
    int i = low;

    while (x <= mid && y <= high)
    {
        if (A[x] <= A[y])
        {
            b[i] = A[x];
            x = x + 1;
        }
        else
        {
            b[i] = A[y];
            y = y + 1;
        }
        i = i + 1;
    }

    while (x <= mid)
    {
        b[i] = A[x];
        x = x + 1;
        i = i + 1;
    }

    while (y <= high)
    {
        b[i] = A[y];
        y = y + 1;
        i = i + 1;
    }

    for (int k = low; k <= high; k = k + 1)
        A[k] = b[k];
}

void mergeSort(int A[], int b[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, b, low, mid);
        mergeSort(A, b, mid + 1, high);
        merge(A, b, low, mid, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *A = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    mergeSort(A, b, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
    free(b);

    return 0;
}

