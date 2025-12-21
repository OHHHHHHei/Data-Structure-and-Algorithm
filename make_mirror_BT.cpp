#include <stdlib.h>

typedef struct BTNode {
    int data;
    BTNode *lchild;
    BTNode *rchild;
}BTNode;

void makeMirrorBT(BTNode *T) {
    if (T == NULL) {
        return;
    }

    BTNode *p;
    p = T->lchild;
    T->lchild = T->rchild;
    T->rchild = p;
    
    makeMirrorBT(T->lchild);
    makeMirrorBT(T->rchild);
    return;
}