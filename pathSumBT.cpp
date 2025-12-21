#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
    int data;
    BTNode *lchild;
    BTNode *rchild;
}BTNode;

int pathSum(BTNode *T, int path) {
    if (T == NULL) {
        return 0;
    }
    
    if (T->lchild ==NULL && T->rchild == NULL) {
        if (path - T->data == 0) {
            return 1;
        }
        return 0;
    }

    return pathSum(T->lchild, path - T->data) || pathSum(T->rchild, path - T->data);
}