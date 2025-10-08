#include <stdio.h>
#include <malloc.h>
#include <math.h>

//多项式结点
struct polynomial
{
    float coef;
    int exp;
    struct polynomial* next;
};

polynomial* create_list()
{
    //头指针
    struct polynomial* head;
    head = (struct polynomial*)malloc(sizeof(polynomial));
    head->next = NULL;
    //尾指针
    struct polynomial* tail_node = head;

    while (1)
    {
        float coef;
        int exp;
        scanf("%f %i", &coef, &exp);
        //判断是否继续
        if (coef == 0)
        {
            break;
        }
        //创建新结点
        struct polynomial* new_node = (struct polynomial*)malloc(sizeof(polynomial));
        new_node->next = NULL;
        //连接
        tail_node->next = new_node;
        tail_node = new_node;
        //写入数据
        tail_node->coef = coef;
        tail_node->exp = exp;
    }

    struct polynomial* result = head->next;
    free(head);  // 释放头节点
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
        //指数相等，系数直接相加
        if (tail1->exp == tail2->exp)
        {
            tail1->coef += tail2->coef;
            struct polynomial* temp = tail2;
            tail2 = tail2->next;
            free(temp);

           if (tail1->coef == 0)
            {
                // 删除 tail1 节点
                struct polynomial* temp = tail1;
                if (prev1 == NULL)
                {
                    // 删除的是第一个节点,更新头指针
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
        //1小于2，1向后移
        else if (tail1->exp < tail2->exp)
        {
            prev1 = tail1;
            tail1 = tail1->next;
        }
        //2小于1，插入
        else
        {
            struct polynomial* temp = tail2;
            tail2 = tail2->next;

            if (prev1 == NULL)
            {
                // 插入到第一个节点之前,更新头指针
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
            // list1 为空或所有节点都已删除
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
    printf("请按指数升序输入多项式A的各项（系数在前，指数在后。系数为0表示输入结束）：\n");
    struct polynomial* list1 = create_list();
    printf("您输入的多项式A的各项为：\n");
    print_list(list1);
    printf("\n");

    printf("请按指数升序输入多项式B的各项（系数在前，指数在后。系数为0表示输入结束）：\n");
    struct polynomial* list2 = create_list();
    printf("您输入的多项式B的各项为：\n");
    print_list(list2);
    printf("\n");
    
    merge_polynomial(&list1, list2);

    printf("和多项式的各项为：\n");
    print_list(list1);
    printf("\n");

    printf("请输入x:");
    float x;
    scanf("%f", &x);
    float result = calculate(x, list1);
    printf("和多项式的值为%f", result);
    return 0;
}
