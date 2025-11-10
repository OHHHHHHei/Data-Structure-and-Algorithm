#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXSIZE 100

typedef struct {
    int data;
    int weight;
    int parent = -1;
    int left_child = -1;
    int right_child = -1;

} huffman_node;

typedef struct {
    int start;
    int code;
} huffman_code;

void build_huffman_tree(huffman_node tree[],int n)
{
    int full = 2 * n - 1;

    while (n < full)
    {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int index1;
        int index2;
         //找到两个最小
        for (int i = 0; i < n; i++)
        {
            //只查看没有父节点的节点
            if (tree[i].parent == -1)
            {
                 if (min1 > tree[i].weight)
                {
                    min2 = min1;
                    index2 = index1;
                    min1 = tree[i].weight;
                    index1 = i;
                } else if (min2 > tree[i].weight)
                {
                    min2 = tree[i].weight;
                    index2 = i;
                }
            }

        }

        //链接父节点
        tree[index1].parent = n;
        tree[index2].parent = n;
        tree[n].weight = min1 + min2;
        tree[n].left_child = index1;
        tree[n].right_child = index2;
        n++;
    }
}


int main()
{
    int character_num;
    scanf("%i", &character_num);

    huffman_node tree[MAXSIZE];

    build_huffman_tree(tree, character_num);







}
