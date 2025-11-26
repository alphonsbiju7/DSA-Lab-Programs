#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == MAX-1) || (front == rear+1));
}

int isEmpty() {
    return (front == -1);
}

void insertRear(int val) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at rear.\n", val);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX-1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = val;
    printf("Inserted %d at rear.\n", val);
}

void insertFront(int val) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at front.\n", val);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX-1;
    } else {
        front--;
    }
    deque[front] = val;
    printf("Inserted %d at front.\n", val);
}

void deleteFront(){
    if(isEmpty()){
        printf("Deque Underflow! Cannot delete from front.\n");
        return;
    }
    printf("Deleted %d from front.\n", deque[front]);
    if(front == rear ){
        front = rear = -1;
    }
    else if(front==MAX-1){
        front = 0;
    }
    else{
        front++;
    }
}
void deleteRear(){
    if(isEmpty()){
        printf("Deque Underflow! Cannot delete from rear.\n");
        return;
    }
    printf("Deleted %d from front.\n",deque[rear]);
    if(front == rear) {
        front = rear = -1;
    }
    else if(rear == 0){
        rear = MAX-1;
    }
    else{
        rear--;
    }
}
void display(){
    if(isEmpty()){
        printf("Deque is Empty.\n");
        return;

    }
    printf("Deque Elements:");
    int i = front;
    while(1){
        printf("%d ",deque[i]);
        if(i==rear)
        break;
        i = (i+1)%MAX;
    }
    printf("\n");
}  

int main() {
    int choice, val;

    printf("\n--- Doubly Ended Queue Menu ---\n");
    printf("1. Insert at Rear\n");
    printf("2. Insert at Front\n");
    printf("3. Delete from Front\n");
    printf("4. Delete from Rear\n");
    printf("5. Display Queue\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 2:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

