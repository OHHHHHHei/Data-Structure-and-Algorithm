#include <stdio.h>
#include <malloc.h>

struct node//����ṹ��
{
    int data;
    struct node* next;
};

struct node* create_node()//��������
{
    struct node* dummy;//����ͷ
    dummy = (struct node*)malloc(sizeof(struct node));
    dummy->next = NULL;
    struct node* tail = dummy;//βָ��

    //ѭ����������
    while (1)
    {
        int input;
        scanf("%i", &input);

        if (input != -1)//��������
        {
            struct node *now_node = (struct node*)malloc(sizeof(struct node));
            now_node->data = input;
            now_node->next = NULL;
            tail->next = now_node;
            tail = now_node;
        }else
        {
            break;
        }

    }

    return dummy->next;
};

struct node* merge_list(struct node* t1,struct node* t2)//�ϲ�����
{
    struct node* tail1 = t1->next;
    struct node* tail2 = t2;
    struct node* now_node = t1;
    //ѭ����������
    while (1)
    {
            now_node->next = tail2;
            tail2 = tail1;
            now_node = now_node->next;
            if (now_node->next == NULL)
            {
                now_node->next = tail2;
                break;
            }
            else
            {
                tail1 = now_node->next;
            }

    }

    return t1;
};

void print_list(struct node* t)
{
    struct node* now_node = t;
    while(now_node->next != NULL)
    {
        printf("%i", now_node->data);
        printf("    ");
        now_node = now_node->next;
    }
   printf("%i", now_node->data);
}


int main()
{
    struct node* list1;
    struct node* list2;
    struct node* list3;

    printf("��������������X��Ԫ��ֵ��������-1Ϊ��ֹ��������\n");
    list1 = create_node();
    print_list(list1);

    printf("��������������Y��Ԫ��ֵ��������-1Ϊ��ֹ��������\n");
    list2 = create_node();
    print_list(list2);


    list3 = merge_list(list1, list2);
    printf("����Z��");
    print_list(list3);

    return 0;
}
