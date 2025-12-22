#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    int data;
    BTNode *lchild;
    BTNode *rchild;
}BTNode;

int isAncestor(BTNode *T, int target) {
    if (T == NULL) {
        return 0;
    }
    if (T->data == target) {
        return 1;
    }
    if (isAncestor(T->lchild, target) || isAncestor(T->rchild, target)) {
        printf("%i", T->data);
        return 1;
    }
    return 0;
}