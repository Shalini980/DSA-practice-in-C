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
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    nn->prev=NULL;
    return nn;
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
    printf("\n");
}
struct node *insertatbeg(struct node *head,int data)
{
    struct node *nn=create(data);
    nn->next=head;
    head=nn;
    return head;
}
struct node *insertatend(struct node *head,int data)
{
    if(head==NULL)
    {
        printf("list is full\n");
        return head;
    }
    struct node *nn=create(data);
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    nn->prev=ptr;
    return head;
}
struct node *insertatpos(struct node *head,int data,int pos)
{
    if(pos==1)
    {
        head=insertatbeg(head,data);
        return head;
    }
    int i=0;
    struct node *nn=create(data);
    struct node *ptr2=NULL;
    struct node *ptr=head;
    for(i=1;i<pos-1 && ptr!=NULL;i++)
    {
        ptr=ptr->next;
    }
    ptr2=ptr->next;
    nn->next=ptr->next;
    ptr->next=nn;
    nn->prev=ptr;
    ptr2->prev=nn;
    return head;
    
}
struct node *deleteatbeg(struct node *head)
{
    if(head==NULL)
    {
        return head;
    }
    struct node *ptr=head;
    head=ptr->next;
    head->prev=NULL;
    free(ptr);
    ptr=NULL;
    return head;
}
struct node *deleteatend(struct node *head)
{
    if(head==NULL)
    {
        return head;
    }
    struct node *ptr=head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    struct node *ptr2=ptr->next;
    ptr->next=NULL;
    free(ptr2);
    ptr2=NULL;
    return head;
}
struct node *deleteatpos(struct node *head,int pos)
{
    if(head==NULL)
    {
        return head;
    }
    struct node *ptr=head;
    int i=0;
    for(i=1;i<pos-1 && ptr!=NULL;i++)
    {
        ptr=ptr->next;
    }
    struct node *ptr2=ptr->next;
    ptr->next=ptr2->next;
    ptr2->next->prev=ptr;
    free(ptr2);
    ptr2=NULL;
    return head;
}
struct node *reverse(struct node *head)
{
    struct node *ptr=head;
    struct node *ptr2=ptr->next;
    ptr->next=NULL;
    ptr->prev=ptr2;
    while(ptr2!=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr;
        ptr=ptr->prev;
        ptr2=ptr2->prev;
    }
    head=ptr;
    return head;
}
int main()
{
    
    struct node *head=NULL;
    printf("creating the data\n");
    head=create(10);
    print(head);
    printf("inserting at beg\n");
    head=insertatbeg(head,20);
    print(head);
    printf("inserting at end\n");
    head=insertatend(head,30);
    print(head);
     printf("inserting at pos\n");
    head=insertatpos(head,30,2);
    print(head);
     printf("deleting at beg\n");
    head=deleteatbeg(head);
    print(head);
    printf("deleting at end\n");
    head=deleteatend(head);
    print(head);
     printf("inserting at beg\n");
    head=insertatbeg(head,50);
    print(head);
     printf("inserting at beg\n");
    head=insertatbeg(head,60);
    print(head);
     printf("inserting at beg\n");
    head=insertatbeg(head,70);
    print(head);
     printf("delete at pos\n");
    head=deleteatpos(head,3);
    print(head);
    printf("reversed link\n");
    head=reverse(head);
    print(head);
    return 0;

}