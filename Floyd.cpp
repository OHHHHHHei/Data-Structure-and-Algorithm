#include <stdio.h>
#include <stdlib.h>
#include "graph.cpp"

#define INF 0x3f3f3f3f  // 定义无穷大

void floyd(int graph[][MAXV], int n)
{
    int i, j, k;
    // 三重循环
    for (k = 0; k < n; k++)         // 第一层：k (中间节点)
    {
        for (i = 0; i < n; i++)     // 第二层：i (起点)
        {
            for (j = 0; j < n; j++) // 第三层：j (终点)
            {
                if (graph[i][k] != INF && graph[k][j] != INF)
                {
                    if (graph[i][k] + graph[k][j] < graph[i][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}

int calculate_dist(int graph[][MAXV], int num, int students[])
{
    int minTotal = INF;
    int bestVillage = 0;
    for (int i = 0; i < num; i++)
    {
        int total = 0;
        for (int j = 0; j < num; j++)
        {
            if (graph[j][i] != INF)  // 只累加可达的距离
            {
                // 距离 * 学生数
                total += graph[j][i] * students[j];
            }
        }
        printf("If the school is located at village %d, the total length is %d stu.mile\n", i, total);
        if (total < minTotal)
        {
            minTotal = total;
            bestVillage = i;
        }
    }
    printf("\nTherefore, the optimal location is village %d with a minimum total length: %d stu.mile.\n", bestVillage, minTotal);
    
    return bestVillage;
}



int main(void)
{
    int num;
    printf("Input the village number:");
    scanf("%d", &num);
    printf("Input the road lengths row by row(0 for a non-existing road):\n");

    int A[MAXV][MAXV];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
           scanf("%d", &A[i][j]);
            // 将0转换为INF,对角线设为0
            if (i == j)
                A[i][j] = 0;
            else if (A[i][j] == 0)
                A[i][j] = INF;
        }
    }

    // 输入每个村庄的学生数
    int students[MAXV];
    printf("Input the student number of each village:\n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &students[i]);
    }

    floyd(A, num);
    calculate_dist(A, num, students);
    
    return 0;
}