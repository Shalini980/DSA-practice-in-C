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
    nn->data=data;
    nn->next=NULL;
    return nn;
}
struct node *insertatfirst(struct node *head,int data)
{
    struct node *nn=create(data);
    nn->next=head;
    head=nn;
    return head;
}
struct node *insertatend(struct node *head,int data)
{
    struct node *nn=create(data);
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    return head;
}
/*struct node *createlist(struct node *head)
{
    printf("Enter the number of nodes you want\n");
    int n,data;
    struct node *ptr=head;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data \n");
        scanf("%d",&data);
       // head=insertatend(head,data);
    }
    return head;
}*/
void print(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    struct node *head=NULL;
    head=createlist(head);
    print(head);
    return 0;
    
}