#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int push(int stack[], int top, int value) {
    stack[top + 1] = value;
    return top + 1;
}
int pop(int stack[], int top) {
    if (top == -1) {
        return -1; // Stack is empty
    }
    return stack[top];
}

void DFS(int graph[MAX][MAX], int visited[MAX], int start, int n) {
    int stack[MAX];
    int top = -1;
    top = push(stack, top, start);
    printf("DFS Traversal: ");
    while (top != -1) {
        int current = pop(stack, top); 
        top--;
        if (!visited[current]) {
            visited[current] = 1; 
            printf("%d ", current);
            for (int i = n - 1; i >= 0; i--) {
                if (graph[current][i] == 1 && !visited[i]) {
                    top = push(stack, top, i);
                }
            }
        }
    }
}

int main() {
    int n;
    int a[MAX][MAX] ;
    int visited[MAX] = {0};
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (space-separated rows):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    DFS(a, visited, start, n);
}
