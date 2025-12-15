#include <stdio.h>
#include <malloc.h>

struct node//定义结构体
{
    int data;
    struct node* next;
};

struct node* create_node()//创建链表
{
    struct node* dummy;//傀儡头
    dummy = (struct node*)malloc(sizeof(struct node));
    dummy->next = NULL;
    struct node* tail = dummy;//尾指针

    //循环创建链表
    while (1)
    {
        int input;
        scanf("%i", &input);

        if (input != -1)//连接链表
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

struct node* merge_list(struct node* t1,struct node* t2)//合并链表
{
    struct node* tail1 = t1->next;
    struct node* tail2 = t2;
    struct node* now_node = t1;
    //循环创建链表
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

    printf("请依次输入链表X的元素值(设输入-1为终止条件):\n");
    list1 = create_node();
    print_list(list1);

    printf("请依次输入链表Y的元素值(设输入-1为终止条件):\n");
    list2 = create_node();
    print_list(list2);


    list3 = merge_list(list1, list2);
    printf("链表Z:");
    print_list(list3);

    return 0;
}
