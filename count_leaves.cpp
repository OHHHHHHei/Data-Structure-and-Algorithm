#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    char data;
    BTNode *lchild;
    BTNode *rchild;
}BTNode;

int countLeaves(BTNode *T) {
    if (T == NULL) {
        return 0;
    }
    if (T->lchild == NULL && T->rchild == NULL) {
        return 1;
    }
    return countLeaves(T->lchild) + countLeaves(T->rchild);
}