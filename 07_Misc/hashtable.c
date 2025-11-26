#include <stdio.h>

#define SIZE 10

int main()
{
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    int n, key, index;
    printf("Enter number of elements to insert (<=10): ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        index = key % SIZE;

        while (hashTable[index] != -1) 
            index = (index + 1) % SIZE;

        hashTable[index] = key;
    }

    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d: %d\n", i, hashTable[i]);

    return 0;
}

