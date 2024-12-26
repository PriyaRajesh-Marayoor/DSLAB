#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) 
            front = 0;
        queue[++rear] = value;
    }
}
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        return queue[front++];
    }
}
void bfs(int n, int adj[MAX][MAX], int start) {
    int visited[MAX] = {0}; 
    printf("BFS Traversal: ");
    enqueue(start);
    visited[start] = 1;
    while (front <= rear) { 
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i]==0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
void main() {
    int n, start;
    int adj[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (%dx%d)\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] : ",i,j);
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    bfs(n, adj, start);
}
