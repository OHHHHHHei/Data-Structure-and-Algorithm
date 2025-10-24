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
    BTNode* head;
    BTNode* help;
    head = (BTNode*)malloc(sizeof(BTNode));

    head->data = pre[0];
    head->left = head->right = NULL;

    //中序中找到根节点
    int index = 0;
    while(in[index] != head->data)
    {
        index++;
    }
    //左子树大小
    int len_left = index;
    //右子树大小
    int len_right = n - len_left - 1;

    if (len_left > 0)
    {
        //创建左子树
        head->left = CreateBT(pre + 1, in, len_left);
    }
    if (len_right > 0)
    {
        //创建右子树
        head->right = CreateBT(pre + len_left + 1, in + len_left + 1, len_right);
    }

    //返回根节点
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

