 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_SIZE 100

// Node structure for a webpage
typedef struct Node {
    char url[URL_SIZE];
    struct Node* prev;
    struct Node* next;
} Node;

// Function to visit a new page
Node* visitNewPage(Node* current, char url[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return current;
    }

    strcpy(newNode->url, url);
    newNode->prev = current;
    newNode->next = NULL;

    // Free forward history if it exists
    if (current != NULL && current->next != NULL) {
        Node* temp = current->next;
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        current->next = NULL;
    }

    if (current != NULL) {
        current->next = newNode;
    }

    printf("Visited: %s\n", newNode->url);
    return newNode;
}

// Go back to previous page
Node* goBack(Node* current) {
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back!\n");
        return current;
    }
    current = current->prev;
    printf("Moved back to: %s\n", current->url);
    return current;
}

// Go forward to next page
Node* goForward(Node* current) {
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward!\n");
        return current;
    }
    current = current->next;
    printf("Moved forward to: %s\n", current->url);
    return current;
}

// Display current page
void displayCurrentPage(Node* current) {
    if (current == NULL) {
        printf("No page visited yet\n");
    } else {
        printf("Current Page: %s\n", current->url);
    }
}

// Free all nodes
void freeAll(Node* current) {
    if (current == NULL) return;

    // Go to head
    while (current->prev != NULL)
        current = current->prev;

    // Free all nodes
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Main function
int main() {
    Node* current = NULL;
    int choice;
    char url[URL_SIZE];

    while (1) {
        printf("\n--- Browser Navigation Menu ---\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                current = visitNewPage(current, url);
                break;
            case 2:
                current = goBack(current);
                break;
            case 3:
                current = goForward(current);
                break;
            case 4:
                displayCurrentPage(current);
                break;
            case 5:
                printf("Exiting Browser Simulation...\n");
                freeAll(current);
                return 0;
            default:
                printf("Invalid choice! Please select 1-5.\n");
        }
    }
    return 0;
}
