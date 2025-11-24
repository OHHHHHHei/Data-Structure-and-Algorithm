#include <stdio.h>
#include <stdlib.h>
#define MAXNODE 100
#define MAXV 100

//边节点
typedef struct ArcNode
{
    int adjvex;
    int info;
    ArcNode *nextarc;
}ArcNode;

//头节点
typedef struct VNode
{
    int data;
    ArcNode *firstarc;
}VNode, AdjList[MAXNODE];

//图结构
typedef struct graph
{
    AdjList adjlist;
    int vexnum;
    int arcnum;
}AdjGraph;

//创建邻接表
void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)
{
    ArcNode *p;
    ArcNode *tail;

    //初始化图结构
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    G->vexnum = n;
    G->arcnum = e;

    for (int i = 0; i < n; i++)
    {
        //初始化头结点
        G->adjlist[i].data = i;
        G->adjlist[i].firstarc = NULL;
        tail = NULL;

        for (int j = 0; j < n; j++)
        {
            if (A[i][j])
            {
                //创建边界点
                p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->info = A[i][j];
                p->nextarc = NULL;

                if (G->adjlist[i].firstarc == NULL)
                {
                    G->adjlist[i].firstarc = p;
                }
                else
                {
                    tail->nextarc = p;
                }
                tail = p;
            }
        }
    }
}

void DispAdj(AdjGraph *G)
{
     printf("The corresponding adjacency lists of the graph are:\n");
    
    for (int i = 0; i < G->vexnum; i++)
    {
        // 打印头节点
        printf("%d: ", i);
        
        // 遍历该顶点的邻接表
        ArcNode *p = G->adjlist[i].firstarc;
        while (p != NULL)
        {
            printf("%d[%d] -> ", p->adjvex, p->info);
            p = p->nextarc;
        }
        
        // 打印结束符号
        printf("^\n");
    }
}

//深度优先搜索
void DFS1(AdjGraph *G, int v)
{
    int visited[MAXV] = {0};
    int stack[MAXV];
    int stack_top = -1;

    //起始点入栈
    stack[++stack_top] = v;
    visited[v] = 1;
    printf("%d ", v);

    //当栈非空的时候，重复以下循环
    while (stack_top >= 0)
    {
        //查看栈顶节点的邻接点
        int curr = stack[stack_top];
        ArcNode* p = G->adjlist[curr].firstarc;

        //标志本次查找是否有发现未访问过的结点
        int found = 0;
        //有邻接点时
        while (p != NULL)
        {
            //若该点没有被访问过，则入栈并访问
            if (!visited[p->adjvex])
            {
                stack[++stack_top] = p->adjvex;
                visited[p->adjvex] = 1;
                printf("%d ", p->adjvex);
                found = 1;
                break;
            }
            p = p->nextarc;
        }
        //若该点的所有邻接节点都被访问过了，那么该节点出栈
        if (!found)
        {
            stack_top--;
        }

    }
}

