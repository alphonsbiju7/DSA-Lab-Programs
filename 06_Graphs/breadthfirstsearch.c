#include <stdio.h>
#define MAX 10  

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;  
}

int dequeue() {
    return queue[front++];  
}

int isEmpty() {
    return front == rear;
}

void bfs(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    int adj[MAX][MAX];

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0-based): ");
    scanf("%d", &start);

    bfs(adj, n, start);

    return 0;
}


