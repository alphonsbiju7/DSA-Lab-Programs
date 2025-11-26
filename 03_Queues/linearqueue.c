#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear == -1) {
        front = rear = 0;
        queue[rear] = val;
        printf("Enqueued %d\n", val);
    }
    else if (rear < MAX - 1) {
        rear++;
        queue[rear] = val;
        printf("Enqueued %d\n", val);
    }
    else {
        printf("Queue Overflow! Cannot enqueue %d\n", val);
    }
}

int dequeue() {
    int val;
    if (front > -1 && front <= rear) {
        val = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return val;
    }
    else {
        printf("Queue Underflow!\n");
        return -1;
    }
}

void printQueue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Queue Operations Menu ---\n");

        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                val = dequeue();
                if (val != -1)
                    printf("Dequeued: %d\n", val);
                break;

            case 3:
                printQueue();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
