#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *create(int data)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    if(nn==NULL)
    {
        printf("STACK OVERFLOW\n");
        return nn;
    }
    nn->data=data;
    nn->next=NULL;
    return nn;
}
void push(struct node **top1,int data)
{
    struct node *nn=create(data);
    nn->next=*top1;
    *top1=nn;
}
void print(struct node **top)
{
    if(*top==NULL)
    {
        printf("no node\n");
        return ;
    }
    struct node *ptr=*top;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int pop(struct node **top)
{
    if(*top==NULL)
    {
        printf("empty\n");
        exit(1);
    }
    struct node *ptr=*top;
    int data=ptr->data;
    *top=ptr->next;
    free(ptr);
    ptr=NULL;
    return data;
}
void reversestack(struct node **top)//this top pointer is local to this function
{
    struct node *top1=NULL;
    struct node *top2=NULL;
    while(*top!=NULL)
    {
        push(&top1,pop(top));
    }
    while(top1!=NULL)
    {
        push(&top2,pop(&top1));
    }
    while(top2!=NULL)
    {
        push(top,pop(&top2));
    }
}
int main()
{
    int data;
    struct node *top=NULL,*top1=NULL,*top2=NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    print(&top);

    /*data=pop(&top);
    push(&top1,data);
    data=pop(&top);
    push(&top1,data);
    data=pop(&top);
    push(&top1,data);
    print(&top1);
    print(&top);

    data=pop(&top1);
    push(&top2,data);
    data=pop(&top1);
    push(&top2,data);
    data=pop(&top1);
    push(&top2,data);
    print(&top2);
    print(&top1);

    data=pop(&top2);
    push(&top,data);
    data=pop(&top2);
    push(&top,data);
    data=pop(&top2);
    push(&top,data);
    printf("reversed stack\n");
    print(&top);
    print(&top2);*/
    printf("the reversed stack is \n");
    reversestack(&top);
    print(&top);
    return 0;
}