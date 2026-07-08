#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void print(struct node *head)
{
    if(head==NULL)
    {
        printf("empty linked list\n");
        exit(1);
    }
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
struct node *insertfront(struct node *head,int data)
{
        struct node *nn=createnode(data);
        nn->next=head;
        head=nn;
        return head;
}
struct node *insertend(struct node *head,int data)
{
    if(head==NULL)
    {
        printf("empty linked list\n");
        return head;
    }
    struct node *nn=createnode(data);
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    return head;
}
struct node *deletefront(struct node *head)
{
    struct node *temp=head;
    head=temp->next;
    free(temp);
    temp=NULL;
    return head;
}
struct node *deleteend(struct node *head)
{
    if(head==NULL)
    {
        printf("empty linked  list\n");
        return head;
    }
    struct node *ptr=head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
    return head;
}
struct node *insertanywhere(struct node *head,int data,int p)
{
    struct node *nn=createnode(data);
    if(head==NULL)
    {
        return head;
    }
    if(p==1)
    {
        head=insertfront(head,data);
        return head;
    }
    else
    {
        struct node *ptr=head;
        while(p-1>0&&ptr!=NULL)
        {
            ptr=ptr->next;
        }
    }
}
int main()
{
   



    return 0;
}