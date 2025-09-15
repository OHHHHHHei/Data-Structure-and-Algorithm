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
        printf(¡°%ld %5.1f\n¡±, p->num, p->score);
        p = p->next;
    }
}

int main()
{


    printf("Please input the student number and score (a zero number indicates the end of input):");
    scanf("%ld %f", &student->num, &student->score);







}
