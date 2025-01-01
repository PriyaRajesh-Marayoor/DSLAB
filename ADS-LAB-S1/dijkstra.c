#include <stdio.h>
#include <stdlib.h>

void dijkstra(int num_nodes, int graph[num_nodes][num_nodes], int visited[num_nodes], int distance[num_nodes], int start_node, int current_node)
{
    visited[start_node] = 1;
    visited[current_node] = 1;
    distance[start_node] = 0;

    for (int i = 0; i < num_nodes; i++)
    {
        if (graph[current_node][i] != 0) // cost of current_node
        {
            // Update distance if a shorter path is found
            if ((distance[current_node] + graph[current_node][i]) < distance[i])
            {
                distance[i] = distance[current_node] + graph[current_node][i];
            }
        }
    }

    // Find the unvisited node with the minimum distance
    int min_distance = 999;
    int next_node = -1;

    for (int i = 0; i < num_nodes; i++)
    {
        if (visited[i] == 0 && distance[i] < min_distance)
        {
            min_distance = distance[i];
            next_node = i;
        }
    }

    // If there's an unvisited node, recursively call the function
    if (next_node != -1)
    {
        dijkstra(num_nodes, graph, visited, distance, start_node, next_node);
    }
}

int main()
{
    int num_nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    int graph[num_nodes][num_nodes];
    int visited[num_nodes], distance[num_nodes];
    int start_node;

    // Initialize visited and distance arrays
    for (int i = 0; i < num_nodes; i++)
    {
        visited[i] = 0;
        distance[i] = 999;
    }

    // Input the cost adjacency matrix of the graph
    printf("Enter the cost adjacency matrix of the graph: ");
    for (int i = 0; i < num_nodes; i++)
    {
        for (int j = 0; j < num_nodes; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the starting node
    printf("Enter the starting node: ");
    scanf("%d", &start_node);

    // Perform Dijkstra's algorithm
    dijkstra(num_nodes, graph, visited, distance, start_node, start_node);

    // Print the final distance array
    printf("Shortest distances from node %d to all other nodes:\n", start_node);
    printf("Node\t\tdistance form node %d\n",start_node);
    for (int i = 0; i < num_nodes; i++)
    {
        printf("%d\t\t  %d\n",i, distance[i]);
    }

    return 0;
}