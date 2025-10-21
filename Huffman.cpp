#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_CHARS 256
#define MAX_CODE_LEN 256

// 哈夫曼树节点结构
typedef struct HuffmanNode {
    int weight;             // 权重
    int parent;             // 父节点索引
    int lchild;             // 左孩子索引
    int rchild;             // 右孩子索引
} HuffmanNode;

// 函数声明
void initHuffmanTree(HuffmanNode tree[], int weights[], int n);
void buildHuffmanTree(HuffmanNode tree[], int n);
void printHuffmanTree(HuffmanNode tree[], int n);

int main() {
    int n;
    int weights[MAX_CHARS];
    
    printf("=== 哈夫曼树构建系统 ===\n\n");
    printf("请输入叶子节点的数量 n (2-%d): ", MAX_CHARS);
    scanf("%d", &n);
    
    if (n < 2 || n > MAX_CHARS) {
        printf("输入错误！使用默认测试数据: n=5\n");
        n = 5;
        weights[0] = 5;
        weights[1] = 29;
        weights[2] = 7;
        weights[3] = 8;
        weights[4] = 14;
    } else {
        printf("请输入 %d 个叶子节点的权重（用空格分隔）: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &weights[i]);
        }
    }
    
    printf("\n叶子节点权重:\n");
    for (int i = 0; i < n; i++) {
        printf("  节点[%d]: 权重 = %d\n", i, weights[i]);
    }
    printf("\n");
    
    // 创建哈夫曼树（需要 2n-1 个节点）
    int nodeCount = 2 * n - 1;
    HuffmanNode* huffmanTree = (HuffmanNode*)malloc(nodeCount * sizeof(HuffmanNode));
    
    // 初始化哈夫曼树
    initHuffmanTree(huffmanTree, weights, n);
    
    // 构建哈夫曼树
    buildHuffmanTree(huffmanTree, n);
    
    printf("哈夫曼树构建完成!\n");
    printHuffmanTree(huffmanTree, nodeCount);
    
    printf("\n验证提示: 检查树结构是否正确\n");
    printf("  - 叶子节点应该没有左右孩子 (left=-1, right=-1)\n");
    printf("  - 内部节点应该有左右孩子和权重（权重=左右孩子权重之和）\n");
    printf("  - 根节点应该没有父节点 (parent=-1)\n");
    
    // 计算带权路径长度 WPL
    int wpl = 0;
    for (int i = 0; i < n; i++) {
        int depth = 0;
        int current = i;
        while (huffmanTree[current].parent != -1) {
            depth++;
            current = huffmanTree[current].parent;
        }
        wpl += weights[i] * depth;
        printf("  叶子节点[%d] 权重=%d, 深度=%d\n", i, weights[i], depth);
    }
    printf("\n哈夫曼树的带权路径长度 WPL = %d\n", wpl);
    
    // 释放内存
    free(huffmanTree);
    
    return 0;
}

// 初始化哈夫曼树（初始化叶子节点）
void initHuffmanTree(HuffmanNode tree[], int weights[], int n) {
    // 初始化所有节点
    for (int i = 0; i < 2 * n - 1; i++) {
        tree[i].weight = 0;
        tree[i].parent = -1;
        tree[i].lchild = -1;
        tree[i].rchild = -1;
    }
    
    // 初始化叶子节点（前n个节点）
    for (int i = 0; i < n; i++) {
        tree[i].weight = weights[i];
    }
}

// 构建哈夫曼树
void buildHuffmanTree(HuffmanNode tree[], int n) {
    /******************************************
     * TODO: 在这里实现哈夫曼树的构建算法
     * 
     * 提示：
     * 1. 需要进行 n-1 次合并操作
     * 2. 每次选择两个权重最小且没有父节点的节点
     * 3. 创建新节点作为这两个节点的父节点
     * 4. 新节点的权重 = 两个子节点权重之和
     * 5. 新节点索引从 n 开始，依次为 n, n+1, ..., 2n-2
     * 
     * 参考步骤：
     * for (int i = n; i < 2*n-1; i++) {
     *     // 找到两个权重最小的无父节点的节点 min1 和 min2
     *     // 设置 min1 和 min2 的父节点为 i
     *     // 设置节点 i 的左右孩子为 min1 和 min2
     *     // 设置节点 i 的权重为 min1 和 min2 的权重之和
     * }
     ******************************************/
    
    // 在这里编写你的代码
    for (int i = n; i < 2 * n - 1; i++)
    {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int index1 = -1;
        int index2 = -1;

        //找到两个最小的结点
        for (int j = 0; j < i; j++)
        {
            //只考虑没有父结点的结点
            if (tree[j].parent == -1)
            {
                //找到最小min1
                if (tree[j].weight < min1)
                {
                    min2 = min1;
                    index2 = index1;
                    min1 = tree[j].weight;
                    index1 = j;
                } else if (tree[j].weight < min2)//找到第二小min2
                {
                    min2 = tree[j].weight;
                    index2 = j;
                }
            }
        }
        //生成新结点，连接父结点
        tree[index1].parent = i;
        tree[index2].parent = i;
        tree[i].lchild = index1;
        tree[i].rchild = index2;
        tree[i].weight = min1 + min2;
    }
}

// 打印哈夫曼树结构
void printHuffmanTree(HuffmanNode tree[], int n) {
    printf("\n节点信息 (索引: 权重, 父节点, 左孩子, 右孩子):\n");
    for (int i = 0; i < n; i++) {
        printf("  [%2d]: 权重=%3d, parent=%2d, left=%2d, right=%2d", 
               i, tree[i].weight, tree[i].parent, tree[i].lchild, tree[i].rchild);
        
        // 标识节点类型
        if (tree[i].lchild == -1 && tree[i].rchild == -1) {
            printf(" (叶子)");
        } else if (tree[i].parent == -1) {
            printf(" (根)");
        } else {
            printf(" (内部)");
        }
        printf("\n");
    }
}

