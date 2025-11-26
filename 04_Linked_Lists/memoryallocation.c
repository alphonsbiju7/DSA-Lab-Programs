#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int id;
    int size;
    int free;
    struct Block *prev, *next;
} Block;

Block *head = NULL;
int nextId = 1;

Block* createBlock(int size, int free) {
    Block* b = malloc(sizeof(Block));
    b->id = free ? -1 : nextId++;
    b->size = size;
    b->free = free;
    b->prev = b->next = NULL;
    return b;
}

void initializeMemory(int size) {
    head = createBlock(size, 1);
}

void allocateBlock(int size) {
    Block *curr = head;
    while (curr) {
        if (curr->free && curr->size >= size) {
            if (curr->size > size) {
                Block *newBlock = createBlock(curr->size - size, 1);
                newBlock->next = curr->next;
                newBlock->prev = curr;
                if (curr->next) curr->next->prev = newBlock;
                curr->next = newBlock;
            }
            curr->size = size;
            curr->free = 0;
            curr->id = nextId++;
            printf("Allocated ID:%d Size:%d\n", curr->id, curr->size);
            return;
        }
        curr = curr->next;
    }
    printf("Allocation failed for size %d\n", size);
}

void freeBlock(int id) {
    Block *curr = head;
    while (curr) {
        if (!curr->free && curr->id == id) {
            curr->free = 1;
            curr->id = -1;
            printf("Freed block ID:%d\n", id);
            return;
        }
        curr = curr->next;
    }
    printf("Block ID %d not found\n", id);
}

void garbageCollect() {
    Block *curr = head;
    while (curr && curr->next) {
        if (curr->free && curr->next->free) {
            curr->size += curr->next->size;
            Block *temp = curr->next;
            curr->next = temp->next;
            if (temp->next) temp->next->prev = curr;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
    printf("Garbage collection done\n");
}

void display() {
    Block *curr = head;
    printf("Memory Blocks:\n");
    while (curr) {
        if (curr->free) printf("[FREE, Size:%d] ", curr->size);
        else printf("[ID:%d, Size:%d] ", curr->id, curr->size);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter total memory size: ");
    scanf("%d", &n);

    initializeMemory(n);

    int choice, size, id;

    // Print menu only once
    printf("\nMenu:\n");
    printf("1. Allocate\n");
    printf("2. Free\n");
    printf("3. Garbage Collect\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter size to allocate: ");
            scanf("%d", &size);
            allocateBlock(size);
        } 
        else if (choice == 2) {
            printf("Enter block ID to free: ");
            scanf("%d", &id);
            freeBlock(id);
        } 
        else if (choice == 3) {
            garbageCollect();
        } 
        else if (choice == 4) {
            display();
        } 
        else if (choice == 5) {
            break;
        } 
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

