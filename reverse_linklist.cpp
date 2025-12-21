#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    node *next;
};

void reverseList(node *head, node *first)
{
    
}

int main()
{
    struct node *head = NULL , *tail = NULL, *p;
    char data;
    int length;
    printf("链表长度为：");
    scanf("%d", &length);

    printf("输入元素");
    for (int i = 0; i < length; i++)
    {
        scanf("%c ", &data);
        p = (struct node *)malloc(sizeof(node));
        p->data = data;
        p->next = NULL;
        
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }



}