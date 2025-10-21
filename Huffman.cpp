#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_CHARS 256
#define MAX_CODE_LEN 256

// ���������ڵ�ṹ
typedef struct HuffmanNode {
    int weight;             // Ȩ��
    int parent;             // ���ڵ�����
    int lchild;             // ��������
    int rchild;             // �Һ�������
} HuffmanNode;

// ��������
void initHuffmanTree(HuffmanNode tree[], int weights[], int n);
void buildHuffmanTree(HuffmanNode tree[], int n);
void printHuffmanTree(HuffmanNode tree[], int n);

int main() {
    int n;
    int weights[MAX_CHARS];
    
    printf("=== ������������ϵͳ ===\n\n");
    printf("������Ҷ�ӽڵ������ n (2-%d): ", MAX_CHARS);
    scanf("%d", &n);
    
    if (n < 2 || n > MAX_CHARS) {
        printf("�������ʹ��Ĭ�ϲ�������: n=5\n");
        n = 5;
        weights[0] = 5;
        weights[1] = 29;
        weights[2] = 7;
        weights[3] = 8;
        weights[4] = 14;
    } else {
        printf("������ %d ��Ҷ�ӽڵ��Ȩ�أ��ÿո�ָ���: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &weights[i]);
        }
    }
    
    printf("\nҶ�ӽڵ�Ȩ��:\n");
    for (int i = 0; i < n; i++) {
        printf("  �ڵ�[%d]: Ȩ�� = %d\n", i, weights[i]);
    }
    printf("\n");
    
    // ����������������Ҫ 2n-1 ���ڵ㣩
    int nodeCount = 2 * n - 1;
    HuffmanNode* huffmanTree = (HuffmanNode*)malloc(nodeCount * sizeof(HuffmanNode));
    
    // ��ʼ����������
    initHuffmanTree(huffmanTree, weights, n);
    
    // ������������
    buildHuffmanTree(huffmanTree, n);
    
    printf("���������������!\n");
    printHuffmanTree(huffmanTree, nodeCount);
    
    printf("\n��֤��ʾ: ������ṹ�Ƿ���ȷ\n");
    printf("  - Ҷ�ӽڵ�Ӧ��û�����Һ��� (left=-1, right=-1)\n");
    printf("  - �ڲ��ڵ�Ӧ�������Һ��Ӻ�Ȩ�أ�Ȩ��=���Һ���Ȩ��֮�ͣ�\n");
    printf("  - ���ڵ�Ӧ��û�и��ڵ� (parent=-1)\n");
    
    // �����Ȩ·������ WPL
    int wpl = 0;
    for (int i = 0; i < n; i++) {
        int depth = 0;
        int current = i;
        while (huffmanTree[current].parent != -1) {
            depth++;
            current = huffmanTree[current].parent;
        }
        wpl += weights[i] * depth;
        printf("  Ҷ�ӽڵ�[%d] Ȩ��=%d, ���=%d\n", i, weights[i], depth);
    }
    printf("\n���������Ĵ�Ȩ·������ WPL = %d\n", wpl);
    
    // �ͷ��ڴ�
    free(huffmanTree);
    
    return 0;
}

// ��ʼ��������������ʼ��Ҷ�ӽڵ㣩
void initHuffmanTree(HuffmanNode tree[], int weights[], int n) {
    // ��ʼ�����нڵ�
    for (int i = 0; i < 2 * n - 1; i++) {
        tree[i].weight = 0;
        tree[i].parent = -1;
        tree[i].lchild = -1;
        tree[i].rchild = -1;
    }
    
    // ��ʼ��Ҷ�ӽڵ㣨ǰn���ڵ㣩
    for (int i = 0; i < n; i++) {
        tree[i].weight = weights[i];
    }
}

// ������������
void buildHuffmanTree(HuffmanNode tree[], int n) {
    /******************************************
     * TODO: ������ʵ�ֹ��������Ĺ����㷨
     * 
     * ��ʾ��
     * 1. ��Ҫ���� n-1 �κϲ�����
     * 2. ÿ��ѡ������Ȩ����С��û�и��ڵ�Ľڵ�
     * 3. �����½ڵ���Ϊ�������ڵ�ĸ��ڵ�
     * 4. �½ڵ��Ȩ�� = �����ӽڵ�Ȩ��֮��
     * 5. �½ڵ������� n ��ʼ������Ϊ n, n+1, ..., 2n-2
     * 
     * �ο����裺
     * for (int i = n; i < 2*n-1; i++) {
     *     // �ҵ�����Ȩ����С���޸��ڵ�Ľڵ� min1 �� min2
     *     // ���� min1 �� min2 �ĸ��ڵ�Ϊ i
     *     // ���ýڵ� i �����Һ���Ϊ min1 �� min2
     *     // ���ýڵ� i ��Ȩ��Ϊ min1 �� min2 ��Ȩ��֮��
     * }
     ******************************************/
    
    // �������д��Ĵ���
    for (int i = n; i < 2 * n - 1; i++)
    {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int index1 = -1;
        int index2 = -1;

        //�ҵ�������С�Ľ��
        for (int j = 0; j < i; j++)
        {
            //ֻ����û�и����Ľ��
            if (tree[j].parent == -1)
            {
                //�ҵ���Сmin1
                if (tree[j].weight < min1)
                {
                    min2 = min1;
                    index2 = index1;
                    min1 = tree[j].weight;
                    index1 = j;
                } else if (tree[j].weight < min2)//�ҵ��ڶ�Сmin2
                {
                    min2 = tree[j].weight;
                    index2 = j;
                }
            }
        }
        //�����½�㣬���Ӹ����
        tree[index1].parent = i;
        tree[index2].parent = i;
        tree[i].lchild = index1;
        tree[i].rchild = index2;
        tree[i].weight = min1 + min2;
    }
}

// ��ӡ���������ṹ
void printHuffmanTree(HuffmanNode tree[], int n) {
    printf("\n�ڵ���Ϣ (����: Ȩ��, ���ڵ�, ����, �Һ���):\n");
    for (int i = 0; i < n; i++) {
        printf("  [%2d]: Ȩ��=%3d, parent=%2d, left=%2d, right=%2d", 
               i, tree[i].weight, tree[i].parent, tree[i].lchild, tree[i].rchild);
        
        // ��ʶ�ڵ�����
        if (tree[i].lchild == -1 && tree[i].rchild == -1) {
            printf(" (Ҷ��)");
        } else if (tree[i].parent == -1) {
            printf(" (��)");
        } else {
            printf(" (�ڲ�)");
        }
        printf("\n");
    }
}

