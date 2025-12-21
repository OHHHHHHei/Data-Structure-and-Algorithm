#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct BTtree {
    int data;
    struct BTtree *lchild;
    struct BTtree *rchild;
}BTtree;

void Preodrder(BTtree *T) {
    if (T == NULL) {
        return;
    }
    printf("%d", T->data);
    Preodrder(T->lchild);
    Preodrder(T->rchild);
}

void Inorder(BTtree *T) {
    if (T == NULL) {
        return;
    }
    Inorder(T->lchild);
    printf("%d", T->data);
    Inorder(T->rchild);
}

void Postorder(BTtree *T) {
    if (T == NULL) {
        return;
    }
    Postorder(T->lchild);
    Postorder(T->rchild);
    printf("%d", T->data);
}

int preval = INT_MIN;
int IsBST(BTtree *T) {

    if (T == NULL) {
        return 1;
    }

    if (!IsBST(T->lchild)) {
        return 0;
    }

    if (T->data <= preval) {
        return 0;
    }
    preval = T->data;

    return IsBST(T->rchild);
}