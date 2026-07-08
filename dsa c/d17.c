#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};
//creating a node
struct node *create(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
//printing the list
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
//inserting in empty list
struct node *insertempty(struct node *head,int data)
{
    struct node *nn=create(data);
    head=nn;
    return head;
}
//insert at beginning
struct node *insertatbeg(struct node *head,int data)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return head;
    }
    struct node *nn=create(data);
    nn->next=head;
    head=nn;
    nn->prev=NULL;
    return head;
}
// insert at end posiiton
struct node *insertatend(struct node *head,int data)
{
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
//insert at certain position
struct node *insertbetween(struct node *head,int data,int pos)
{
    if(pos==1)
    {
         struct node *nn=create(data);
         head=insertatbeg(head,data);
         return head;
    }
    struct node *ptr=head;
    struct node *ptr2=NULL;
    struct node *nn=create(data);
    for(int i=1;i<pos-1 && ptr!=NULL;i++)
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
//create an entire list 
struct node *createentire(struct node *head)
{
    int n,data,i;
    printf("enter the nodes you want\n");
    scanf("%d",&n);
    if(n==0)return head;
    printf("enter the elemenr for node 1\n");
    scanf("%d",&data);
    head=insertempty(head,data);
    for(i=1;i<n;i++)
    {
        printf("enter the element\n");
        scanf("%d",&data);
        insertatend(head,data);
    }
    return head;
}
//delete first node
struct node *delfirst(struct node *head)
{
    struct node *temp=head;
    head=temp->next;
    temp->next->prev=NULL;
    free(temp);
    temp=NULL;
    return head;
}
//deleting last node 
struct node *dellast(struct node *head)
{
    struct node *ptr =head;
    struct node *ptr2;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr2=ptr->prev;
    ptr2->next=NULL;
    free(ptr);
    ptr=NULL;
    return head;
}
//deleting at certain position
struct node *delatcertain(struct node *head , int pos)
{
    if(pos==1)
    {
        head=delfirst(head);
        return head;
    }
    struct node *ptr=head;
    struct node *ptr2=NULL;
    struct node *ptr3=NULL;
    for(int i=1;i<pos && ptr!=NULL;i++)
    {
        ptr=ptr->next;
    }
    ptr2=ptr->prev;
    ptr3=ptr->next;
    ptr2->next=ptr3;
    ptr3->prev=ptr2;
    free(ptr);
    ptr=NULL;
    return head;


}
//reverse 
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
        ptr2=ptr2->prev;
        ptr=ptr->prev;
    }
    head=ptr;
    return head;
    
}
int main()
{
    /*struct node *head=create(1);
    head->next=create(2);
    printf("list after creating node \n");
    print(head);*/
    struct node *head=NULL;
    printf("inserting in empty list\n");
    head=insertempty(head,1);
    print(head);
    printf("\ninserting at beginning\n");
    head=insertatbeg(head,2);
    print(head);
     printf("\ninserting at end\n");
    head=insertatend(head,3);
    print(head);
     printf("\ninserting at certain position\n");
    head=insertbetween(head,4,3);
    print(head);
    printf("\ninserting at certain position\n");
    head=insertbetween(head,4,2);
    print(head);
    /*printf("\ninserting an entire list\n");
    head=createentire(head);
    print(head);*/
     printf("\ndeleting first node \n");
    head=delfirst(head);
    print(head);
    printf("\ndeleting last node \n");
    head=dellast(head);
    print(head);
     printf("\ndeleting certain node  \n");
    head=delatcertain(head,2);
    print(head);
    printf("\ninserting at beginning\n");
    head=insertatbeg(head,2);
    print(head);
     printf("\ninserting at end\n");
    head=insertatend(head,3);
    print(head);
     printf("\nreversing list  \n");
    head=reverse(head);
    print(head);
    return 0;
}