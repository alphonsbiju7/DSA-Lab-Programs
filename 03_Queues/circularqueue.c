#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
    return front == -1;
}

// Check if queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}

// Enqueue operation
void enqueue(int val) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", val);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = val;
    printf("Enqueued %d\n", val);
}

// Dequeue operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return val;
}

// Display queue elements
void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Invalid choice! Try again.\n");
        }
    }
}#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
    return front == -1;
}

// Check if queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}

// Enqueue operation
void enqueue(int val) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", val);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = val;
    printf("Enqueued %d\n", val);
}

// Dequeue operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return val;
}

// Display queue elements
void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Invalid choice! Try again.\n");
        }
    }
}#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
    return front == -1;
}

// Check if queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}

// Enqueue operation
void enqueue(int val) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", val);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = val;
    printf("Enqueued %d\n", val);
}

// Dequeue operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return val;
}

// Display queue elements
void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Invalid choice! Try again.\n");
        }
    }
}
