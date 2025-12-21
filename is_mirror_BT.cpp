#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    char data;
    BTNode *lchild;
    BTNode *rchild;
}BTNode;

int isMirror(BTNode *p, BTNode *q) {
    if (p == NULL && q == NULL) {
        return 1;
    }

    if (p == NULL || q == NULL) {
        return 0;
    }

    if (p->data == q->data) {
        return isMirror(p->lchild, q->rchild) && isMirror(p->rchild, q->lchild);
    }
    return 0;
}

int isSymmetric(BTNode *T) {
    if (T == NULL) {
        return 1;
    }
    return isMirror(T->lchild, T->rchild);
}
