
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int vertex, int numVertices);
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex, int numVertices);


void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int vertex, int numVertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, visited, i, numVertices);
        }
    }
}

void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex, int numVertices) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;
    front++;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int numVertices, edges, startVertex, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        int from, to;
        printf("Enter edge (from to): ");
        scanf("%d %d", &from, &to);
        graph[from][to] = 1;
    }

    printf("Adjacency Matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    int visited[MAX_VERTICES] = {0};
    printf("DFS Traversal starting from vertex 0:\n");
    DFS(graph, visited, 0, numVertices);
    printf("\n");

    printf("BFS Traversal starting from vertex 0:\n");
    BFS(graph, 0, numVertices);
    printf("\n");

    return 0;
}

