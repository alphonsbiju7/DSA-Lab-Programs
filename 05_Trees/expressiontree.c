#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

typedef struct {
    Node* arr[100];
    int top;
} Stack;

void push(Stack *s, Node* n) {
 s->arr[++s->top] = n;
 }
Node* pop(Stack *s) {
 return s->arr[s->top--];
 }

Node* newNode(char c) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = c;
    n->left = n->right = NULL;
    return n;
}

Node* buildTree(char postfix[]) {
    Stack s; s.top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            push(&s, newNode(c));
        } else {
            Node* op = newNode(c);
            Node* r = pop(&s);
            Node* l = pop(&s);
            op->right = r;
            op->left = l;
            push(&s, op);
        }
    }
    return pop(&s);
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
void preorder(Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    Node* root = buildTree(postfix);
    printf("Infix   : "); inorder(root); printf("\n");
    printf("Prefix  : "); preorder(root); printf("\n");
    printf("Postfix : "); postorder(root); printf("\n");
    return 0;
}

