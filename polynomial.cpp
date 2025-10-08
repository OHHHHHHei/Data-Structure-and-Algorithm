#include <stdio.h>
#include <malloc.h>
#include <math.h>

//����ʽ���
struct polynomial
{
    float coef;
    int exp;
    struct polynomial* next;
};

polynomial* create_list()
{
    //ͷָ��
    struct polynomial* head;
    head = (struct polynomial*)malloc(sizeof(polynomial));
    head->next = NULL;
    //βָ��
    struct polynomial* tail_node = head;

    while (1)
    {
        float coef;
        int exp;
        scanf("%f %i", &coef, &exp);
        //�ж��Ƿ����
        if (coef == 0)
        {
            break;
        }
        //�����½��
        struct polynomial* new_node = (struct polynomial*)malloc(sizeof(polynomial));
        new_node->next = NULL;
        //����
        tail_node->next = new_node;
        tail_node = new_node;
        //д������
        tail_node->coef = coef;
        tail_node->exp = exp;
    }

    struct polynomial* result = head->next;
    free(head);  // �ͷ�ͷ�ڵ�
    return result;
}

void print_list(struct polynomial* node)
{
    struct polynomial* tail_node = node;
    while (tail_node != NULL)
    {
        printf("%f, %i\n", tail_node->coef, tail_node->exp);
        tail_node = tail_node->next;
    }
}

void merge_polynomial(struct polynomial** list1, struct polynomial* list2)
{
    struct polynomial* tail1 = *list1;
    struct polynomial* tail2 = list2;
    struct polynomial* prev1 = NULL;

    while (tail1 != NULL && tail2 != NULL)
    {
        //ָ����ȣ�ϵ��ֱ�����
        if (tail1->exp == tail2->exp)
        {
            tail1->coef += tail2->coef;
            struct polynomial* temp = tail2;
            tail2 = tail2->next;
            free(temp);

           if (tail1->coef == 0)
            {
                // ɾ�� tail1 �ڵ�
                struct polynomial* temp = tail1;
                if (prev1 == NULL)
                {
                    // ɾ�����ǵ�һ���ڵ�,����ͷָ��
                    *list1 = tail1->next;
                }
                else
                {
                    prev1->next = tail1->next;
                }
                tail1 = tail1->next;
                free(temp);
            }
            else
            {
                prev1 = tail1;
                tail1 = tail1->next;
            }

        }
        //1С��2��1�����
        else if (tail1->exp < tail2->exp)
        {
            prev1 = tail1;
            tail1 = tail1->next;
        }
        //2С��1������
        else
        {
            struct polynomial* temp = tail2;
            tail2 = tail2->next;

            if (prev1 == NULL)
            {
                // ���뵽��һ���ڵ�֮ǰ,����ͷָ��
                temp->next = tail1;
                *list1 = temp;
                prev1 = temp;
            }
            else
            {
                prev1->next = temp;
                temp->next = tail1;
                prev1 = temp;
            }
        }
    }

    if (tail2 != NULL)
    {
       if (prev1 == NULL)
        {
            // list1 Ϊ�ջ����нڵ㶼��ɾ��
            *list1 = tail2;
        }
        else
        {
            prev1->next = tail2;
        }
    }

}

float calculate(float x, struct polynomial* list1)
{
    float result = 0;
    struct polynomial* tail_node = list1;
    while (tail_node != NULL)
    {
        result += tail_node->coef * pow(x, tail_node->exp);
        tail_node = tail_node->next;
    }
    return result;
}


int main(void)
{
    printf("�밴ָ�������������ʽA�ĸ��ϵ����ǰ��ָ���ں�ϵ��Ϊ0��ʾ�����������\n");
    struct polynomial* list1 = create_list();
    printf("������Ķ���ʽA�ĸ���Ϊ��\n");
    print_list(list1);
    printf("\n");

    printf("�밴ָ�������������ʽB�ĸ��ϵ����ǰ��ָ���ں�ϵ��Ϊ0��ʾ�����������\n");
    struct polynomial* list2 = create_list();
    printf("������Ķ���ʽB�ĸ���Ϊ��\n");
    print_list(list2);
    printf("\n");
    
    merge_polynomial(&list1, list2);

    printf("�Ͷ���ʽ�ĸ���Ϊ��\n");
    print_list(list1);
    printf("\n");

    printf("������x:");
    float x;
    scanf("%f", &x);
    float result = calculate(x, list1);
    printf("�Ͷ���ʽ��ֵΪ%f", result);
    return 0;
}
