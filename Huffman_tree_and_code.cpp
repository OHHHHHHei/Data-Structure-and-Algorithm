#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXSIZE 100

typedef char elemtype;
typedef struct {
    elemtype data;
    int weight;
    int parent;
    int lchild;
    int rchild;
} huffman_node;

typedef struct {
    char cd[MAXSIZE];
    int start;
} huffman_code;

void build_huffman_tree(huffman_node ht[], int n) {
    for (int j = n; j < 2 * n - 1; j++)
    {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int index1 = -1;
        int index2 = -1;
        //找到两个最小
        for (int i = 0; i < j; i++)
        {
            //只查看没有父节点的节点
            if (ht[i].parent == -1)
            {
                if (min1 > ht[i].weight)
                {
                    min2 = min1;
                    index2 = index1;
                    min1 = ht[i].weight;
                    index1 = i;
                } else if (min2 > ht[i].weight)
                {
                    min2 = ht[i].weight;
                    index2 = i;
                }
            }
        }
        //连接父结点
        ht[index1].parent = j;
        ht[index2].parent = j;
        ht[j].lchild = index1;
        ht[j].rchild = index2;
        ht[j].weight = min1 + min2;
    }
}

void init_huffmantree(huffman_node ht[], int n) {
    for (int i = 0; i < 2 * n - 1; i++)
    {
        ht[i].parent = -1;
        ht[i].lchild = -1;
        ht[i].rchild = -1;
    }
    
}

void build_huffmancode(huffman_node ht[], huffman_code hcd[], int n) {
    //遍历每个字符并且编码
    for (int j = 0; j < n; j++)
    {
        //添加字符串结束符
        hcd[j].cd[MAXSIZE - 1] = '\0';

        //j表示当前编码字符
        int now_node = j;
        //i为从下往上寻找的次数
        int i = 0;
        while (ht[now_node].parent != -1)
        {
            if (ht[ht[now_node].parent].lchild == now_node)
            {
                hcd[j].cd[MAXSIZE - i - 2] = '0';
            } else {
                hcd[j].cd[MAXSIZE - i - 2] = '1';
            }
            now_node = ht[now_node].parent;
            i++;
        }
        hcd[j].start = MAXSIZE - i - 1;
    }
}

void print_huffmancode(huffman_node ht[], huffman_code hcd[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%c: %s\n", ht[i].data, &hcd[i].cd[hcd[i].start]);
    }
    
}

int main()
{
    int num;
    printf("Please input the number of character to be encode:\n");
    scanf("%i", &num);

    huffman_node* ht = (huffman_node*)malloc((2 * num - 1) * sizeof(huffman_node));

    //初始化哈夫曼树
    init_huffmantree(ht, num);

    //输入权重
    printf("Please input the weights:");
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&ht[i].weight);
    }
    
    //输入字符
    printf("Please input the characters:");
    for (int i = 0; i < num; i++)
    {
        scanf(" %c", &ht[i].data);
    }
    
    //构建哈夫曼树
    build_huffman_tree(ht, num);

    huffman_code* hcd = (huffman_code*)malloc(num * sizeof(huffman_code));
    //进行哈夫曼编码
    build_huffmancode(ht, hcd, num);

    print_huffmancode(ht, hcd, num);

    free(ht);
    free(hcd);

    return 0;
}