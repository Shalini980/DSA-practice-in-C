#include<stdio.h>
#include<stdlib.h>
struct  tree
{
    int key;
    struct tree *left ;
    struct tree *right;
};

struct tree*create(int value)
{
    struct tree* nn=(struct tree*)malloc(sizeof(struct tree));
    nn->key=value;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
struct tree*insert(struct tree*head,int value)
{
    if(head==NULL)
    {
        printf("Tree is empty\n");
        return head;
    }
    if(head->key>value)
    {

    }
    else
    {

    }
    return head;
}
struct Tree*searchNode(struct Tree* root, int target)
{
    if (root == NULL || root->key == target) {
        return root;
    }
    if (root->key < target) {
        return searchNode(root->right, target);
    }
    return searchNode(root->left, target);
}