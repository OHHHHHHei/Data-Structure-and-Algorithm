#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
}Node;

Node* createLinklistByTail(int n) {
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    Node *tail = head;

    for (int i = 0; i < n; i++)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->next = NULL;

        scanf("%d", &newNode->data); // 填入数据

        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

Node* createLinklistByHead(int n) {
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    for (int i = 0; i < n; i++)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));

        scanf("%d", &newNode->data); // 填入数据

        newNode->next = head->next;
        head->next = newNode;
    }
    return head;
}
