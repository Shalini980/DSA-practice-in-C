#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create(int data)
{
    struct node *nn=(struct node *)malloc(sizeof (struct node) );
    nn->data=data;
    nn->next=NULL;
    nn->prev=NULL;
    return nn;
}
struct node *insertatbeg(struct node *tail,int data)
{
    struct node *nn=create(data);
    struct node *ptr=tail->next;
    nn->next=tail->next;
    tail->next=nn;
    return tail;
}