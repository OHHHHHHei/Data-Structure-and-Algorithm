#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    long num;
    float score;
    struct student *next;
};


void print(struct student *head)
{
    struct student *p = head;
    p = head;
    while (p != NULL)
    {
        printf("%ld %5.1f\n", p->num, p->score);
        p = p->next;
    }
}

int main()
{
    struct student *head = NULL, *tail = NULL, *p;
    long num;
    float score;

    printf("Please input the student number and score (a zero number indicates the end of input):\n");
    
    while (1)
    {
        scanf("%ld %f", &num, &score);
        
        // ????0?????
        if (num == 0)
            break;
        
        // ?????
        p = (struct student *)malloc(sizeof(struct student));
        p->num = num;
        p->score = score;
        p->next = NULL;
        
        // ????????
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else  // ???????
        {
            tail->next = p;
            tail = p;
        }
    }
    
    // ????
    printf("\nStudent information:\n");
    print(head);
    
    // ????
    p = head;
    while (p != NULL)
    {
        struct student *temp = p;
        p = p->next;
        free(temp);
    }
    
    return 0;
}
