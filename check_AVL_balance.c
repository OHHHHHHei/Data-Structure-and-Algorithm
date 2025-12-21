#include <stdio.h>
#include <stdlib.h>

typedef struct BTtree
{
    int data;
    struct BTtree *lchild;
    struct BTtree *rchild;
}BTtree;

int countdepth(BTtree *T)
{
    if (T == NULL)
    {
        return 0;
    }
    
    //如果是叶子结点
    if (T->lchild == NULL && T->rchild == NULL)
    {
        return 1;
    }

    return max(countdepth(T->lchild), countdepth(T->rchild)) + 1;
}

int Isbalance(BTtree *T)
{
    if (T == NULL)
    {
        return 1;
    }

    if (Isbalance(T->lchild) && Isbalance(T->rchild))
    {
            if (abs(countdepth(T->lchild) - countdepth(T->rchild)) <= 1)
        {
            return 1;
        }
    }
    return 0;
}