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
    nn->data=data;
    nn->next=NULL;
    return nn;
}
struct node *insertatend(struct node *head,int data)
{
    if(head==NULL)return head;
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    struct node *nn=create(data);
    ptr->next=nn;
    return head;
}
struct node *createlist(struct node *head)
{
    int n,data;
    printf("enter the number of element syou want in your list\n");
    scanf("%d",&n);
    if(n==0)
    return head;
    printf("enter the first element data\n");
    scanf("%d",&data);
    head=create(data);
    for(int i=1;i<n;i++)
    {
        printf("enter the data of element no. %d",i+1);
        scanf("%d",&data);
        head=insertatend(head,data);
    }
    return  head;
}
void print(struct node * head)
{
    if(head==NULL)
    {
        printf("no node in the list\n");
    }
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
//inserting in sorted list
struct node *insertinsorted(struct node *head,int data)
{
     struct node *nn=create(data);
     int key=nn->data;
     struct node *temp=head;
    if(head==NULL||head->data>key)
    {
        nn->next=head;
        head=nn;
    return head;
    }
    else
    {
        while(temp->next!=NULL&&temp->next->data<key)
    {
        temp=temp->next;
    }
    nn->next=temp->next;
    temp->next=nn;
    }
    return head;
}
int main()
{
    struct node *head=NULL;
    printf("Creating a whole list\n");
    head=createlist(head);
    print(head);
    printf("\ninserting in sorted list\n");
    head=insertinsorted(head,0);
    print(head);
    return 0;
}