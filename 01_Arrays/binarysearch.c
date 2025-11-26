 #include <stdio.h>

int binarySearch(int ar[], int n, int key) {
    int s = 0, e = n - 1, m;
    while (s <= e) {
        m = (s + e) / 2;
        if (key > ar[m])
            s = m + 1;
        else if (key < ar[m])
            e = m - 1;
        else
            return m;
    }
    return -1;
}

int main() {
    int n, key, i, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int ar[n];
    printf("Enter %d sorted integers (ascending): ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &ar[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    pos = binarySearch(ar, n, key);

    if (pos == -1)
        printf("Key %d not found\n", key);
    else
        printf("Key %d found at index %d (position %d)\n", key, pos, pos + 1);

    printf("Time Complexity: O(log n)\n");
    printf("Space Complexity: O(1)\n");

    return 0;
}
