#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(int data)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node ));
    if(nn==NULL)
    {
        printf("stack overflow\n");
        exit(1);
    }
    nn->data=data;
    nn->next=NULL;
    return nn;
}
struct node *push(struct node *top,int data)
{
    struct node *temp=create(data);
    temp->next=top;
    top=temp;
    return top; 
}
void print(struct node *top)
{
    if(top==NULL)
    {
        printf("no node\n");
        return;
    }
    struct node *ptr=top;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node * pop(struct node *top)
{
    if(top==NULL)
    {
        printf("no node\n");
        exit(1);
    }
    struct node *ptr=top;
    top=ptr->next;
    return ptr;
}
void reverse(struct node *top,struct node *top1,struct node *top2)
{
    if(top==NULL)
    return ;
    else
    {
        int data=0;
        while(top!=NULL)
        {
           struct node *ptr=pop(top);
            top=ptr->next;
            data=ptr->data;
            top1=push(top1,data);

        }
        printf("top1 is\n");
        print(top1);
        while(top1!=NULL)
        {
            struct node *ptr1=pop(top1);
            top1=ptr1->next;
            data=ptr1->data;
            top2=push(top2,data);
        }
        printf("top2\n");
        print(top2);
        while(pop(top2)!=NULL)
        {
            struct node *ptr2=pop(top2);
            top2=ptr2->next;
            data=ptr2->data;
            top=push(top2,data);
        }
        printf("original reversed stack\n");
        print(top);

    }
}
int main()
{
    struct node *top=NULL;
    struct node *top1=NULL;
    struct node *top2=NULL;
    top=push(top,1);
    top=push(top,2);
    top=push(top,3);
    print(top);
    struct node *temp;
    temp=pop(&top);
    //top=temp->next;
    top1=push(top1,temp->data);
    temp = pop(&top);
    top=temp->next;
    top1=push(top1,temp->data);
    print(top);
    print(top1);
    reverse(top,top1,top2);
    return 0;

}