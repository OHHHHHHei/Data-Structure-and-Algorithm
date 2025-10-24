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
    // 1. ������ǰ���ڵ�
    BTNode* head;
    head = (BTNode*)malloc(sizeof(BTNode));

    // 2. �����һ��Ԫ�ؾ��Ǹ��ڵ��ֵ
    head->data = pre[0];
    head->left = head->right = NULL;

    // 3. ������������ҵ����ڵ��λ��
    //    ��������ȷ�����������ķ�Χ
    int index = 0;
    while(in[index] != head->data)
    {
        index++;  // index ����ָ����ڵ��������е�λ��
    }
    
    // 4. �������������Ĵ�С
    int len_left = index;              // �������ڵ���
    int len_right = n - len_left - 1;  // �������ڵ��� (���� - ������ - ���ڵ�)

    // 5. �ݹ鴴��������
    if (len_left > 0)
    {
        // pre + 1: �������ڵ�,����������������㿪ʼ
        // in: �����ͷ��ʼ����������
        // len_left: �������ĳ���
        head->left = CreateBT(pre + 1, in, len_left);
    }
    
    // 6. �ݹ鴴��������
    if (len_right > 0)
    {
        // pre + len_left + 1: �������ڵ�(+1)������������(+len_left)
        // in + len_left + 1: �����������͸��ڵ�
        // len_right: �������ĳ���
        head->right = CreateBT(pre + len_left + 1, in + len_left + 1, len_right);
    }

    // 7. ���ع����õ��������ڵ�
    return head;
}



int main()
{
    char pre[100];
    char in[100];
    BTNode* tree;
    //ʹ�� fgets ��ȡ
    if (fgets(pre, sizeof(pre), stdin) == NULL) {
        printf("��ȡʧ��\n");
        return 1;
    }
    if (fgets(in, sizeof(in), stdin) == NULL) {
        printf("��ȡʧ��\n");
        return 1;
    }
    
    // �Ƴ����з�(��Ҫ!)
    pre[strcspn(pre, "\n")] = '\0';
    in[strcspn(in, "\n")] = '\0';

    int len_in = strlen(in);

    tree = CreateBT(pre, in, len_in);

    DispBTree(tree);

    return 0;
}

