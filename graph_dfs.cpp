#include <stdio.h>
#include <stdlib.h>
#include "graph.cpp"


int main()
{
    int vertex;
    int edge;
    printf("Plaese input the vertex number:");
    scanf("%d", &vertex);
    printf("and the edge number:");
    scanf("%d", &edge);

    int A[MAXV][MAXV];

    printf("Please input the adjacency matrix row by row.Input 0 for a non-existing edge:\n");
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    AdjGraph *G;
    CreateAdj(G, A, vertex, edge);
    DispAdj(G);
    printf("\nDFS traversal starting from vertex 0:\n");
    DFS1(G, 0);

    return 0;
}