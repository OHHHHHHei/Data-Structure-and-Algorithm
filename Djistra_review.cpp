#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXV 100

typedef struct Graph
{
    int data;
    int arc[MAXV][MAXV];
    int vertexnum;
}Graph;


void djistra(Graph G, int v0, int dist[], int path[]) {
    int visited[MAXV];
    // Init
    for (int i = 0; i < G.vertexnum; i++)
    {
        visited[i] = 0;
        dist[i] = G.arc[v0][i];
        path[i] = (dist[i] < INT_MAX) ? v0 : -1;
    }

    dist[v0] = 0;
    visited[v0] = 1;

    for (int i = 0; i < G.vertexnum; i++)
    {
        int min = INT_MAX;
        int k = -1;//记录最近的下标

        //找到距离当前距离最近的未访问点
        for (int j = 0; j < G.vertexnum; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }

        if (k == -1) break;
        visited[k] = 1;

        for (int j = 0; j < G.vertexnum; j++)
        {
            if (!visited[j] && G.arc[k][j] < INT_MAX)
            {
                if (dist[k] + G.arc[k][j] < dist[j])
                {
                    dist[j] = dist[k] + G.arc[k][j];
                    path[j] = k;
                }
            }
        }
    }
}