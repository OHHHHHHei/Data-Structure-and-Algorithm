#include <stdlib.h>
#include <stdio.h>
#include "graph.cpp"

int main()
{
    //Input 1
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

    // // Input 2 - alternative
    // int vertex = 14;
    // int edge = 19;
    // int A[MAXV][MAXV];
    
    // int r, c;
    // for(r = 0; r < vertex; r++) {
    //     for(c = 0; c < vertex; c++) {
    //         A[r][c] = 0;
    //     }
    // }
    // A[0][1] = 1;
    // A[1][2] = 1; A[4][2] = 1; A[5][2] = 1;
    // A[2][3] = 1;
    // A[0][4] = 1;
    // A[0][5] = 1;
    // A[3][6] = 1; A[5][6] = 1;
    // A[6][7] = 1;
    // A[7][8] = 1;
    // A[8][9] = 1;
    // A[5][10] = 1;
    // A[9][11] = 1; A[10][11] = 1;
    // A[11][12] = 1;
    // A[11][13] = 1; A[12][13] = 1;

    AdjGraph *G;
    CreateAdj(G, A, vertex, edge);
    DispAdj(G);
    printf("\nThe DFS sequence produced by a non-recursive algorithm is:\n");
    DFS1(G, 0);
    printf("\n");
    printf("The topologival sequence is:\n");
    dfs_topological(G);
}