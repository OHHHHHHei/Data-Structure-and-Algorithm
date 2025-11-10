#include <stdio.h>
#include <string.h>
#include <malloc.h>


typedef struct BTNode
{
    char data;
    BTNode* left;
    BTNode* right;
}BTNode;


void DispBTree(BTNode *b)
{
    if (b != NULL)
    {
        printf("%c", b->data);
        if (b->left != NULL || b->right != NULL)
        {
            printf("(");
            DispBTree(b->left);
            printf(",");
            DispBTree(b->right);
            printf(")");
        }

    }
}

BTNode* CreateBT(char *pre, char *in, int n)
{
    // 1. 创建当前根节点
    BTNode* head;
    head = (BTNode*)malloc(sizeof(BTNode));

    // 2. 先序第一个元素就是根节点的值
    head->data = pre[0];
    head->left = head->right = NULL;
 
    // 3. 在中序遍历中找到根节点的位置
    //    这样可以确定左右子树的范围
    int index = 0;
    while(in[index] != head->data)
    {
        index++;  // index 最终指向根节点在中序中的位置
    }
    
    // 4. 计算左右子树的大小
    int len_left = index;              // 左子树节点数
    int len_right = n - len_left - 1;  // 右子树节点数 (总数 - 左子树 - 根节点)

    // 5. 递归创建左子树
    if (len_left > 0)
    {
        // pre + 1: 跳过根节点,从左子树的先序起点开始
        // in: 中序从头开始就是左子树
        // len_left: 左子树的长度
        head->left = CreateBT(pre + 1, in, len_left);
    }
    
    // 6. 递归创建右子树
    if (len_right > 0)
    {
        // pre + len_left + 1: 跳过根节点(+1)和整个左子树(+len_left)
        // in + len_left + 1: 跳过左子树和根节点
        // len_right: 右子树的长度
        head->right = CreateBT(pre + len_left + 1, in + len_left + 1, len_right);
    }

    // 7. 返回构建好的子树根节点
    return head;
}



int main()
{
    char pre[100];
    char in[100];
    BTNode* tree;
    //使用 fgets 读取
    if (fgets(pre, sizeof(pre), stdin) == NULL) {
        printf("读取失败\n");
        return 1;
    }
    if (fgets(in, sizeof(in), stdin) == NULL) {
        printf("读取失败\n");
        return 1;
    }
    
    // 移除换行符(重要!)
    pre[strcspn(pre, "\n")] = '\0';
    in[strcspn(in, "\n")] = '\0';

    int len_in = strlen(in);

    tree = CreateBT(pre, in, len_in);

    DispBTree(tree);

    return 0;
}

