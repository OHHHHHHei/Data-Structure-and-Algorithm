#include <stdio.h>
#include <stdlib.h>

#define MAXV 100

typedef struct Graph
{
    int data;
    int arc[MAXV][MAXV];
    int vertexnum;
}Graph;

void floyd(Graph G) {
    int A[MAXV][MAXV];
    int path[MAXV][MAXV];

    for (int i = 0; i < G.vertexnum; i++)
    {
        for (int j = 0; j < G.vertexnum; j++)
        {
            A[i][j] = G.arc[i][j];
            path[i][j] = -1;
        }
    }

    for (int k = 0; k < G.vertexnum; k++)
    {
        for (int i = 0; i < G.vertexnum; i++)
        {
            for (int j = 0; j < G.vertexnum; j++)
            {   
                if (A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                } 
            }
        }
    }
}