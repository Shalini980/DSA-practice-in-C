#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
//create node
struct node *createnode(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
//printing the linked list
void print(struct node *head)
{
    if(head==NULL)
    {
        printf("empty linked list\n");
    }
    struct node * ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
//counting the nodes of linked list
int count(struct node *head)
{
    int c=0;
    if(head==NULL)
    {
        printf("empty linked list\n");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        c++;
        ptr=ptr->next;

    }
    printf("%d\n",c);
}
//insert at begning
struct node *insertatbeg(struct node * head,int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next =NULL;
    temp->next=head;
    head=temp;
    return head;

}
//insert at certain position
struct node *insertatanyposition(struct node *head,int data,int pos)
{
    if(pos==1)
    {
        struct node *nn=createnode(data);
        nn->next=head;
        head=nn;
        return head;
    }
    int i;
    struct node *nn=createnode(data);
    struct node *ptr=head;
    for( i=1;i<pos-1 && ptr!=NULL;i++)
    {
       ptr=ptr->next;
    }
        nn->next=ptr->next;
        ptr->next=nn;
        return head;
}
//inserting at end
struct node  *insertatend(struct node * head,int data)
{
    struct node *temp,*ptr=NULL;
    ptr=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}
//deleting the first node 
struct node *deletethefirst(struct node *head)
{
    if(head==NULL)
    {
        printf("the limked list is empty\n");
    }
    struct node *temp=head;
    head=temp->next;
    free(temp);
    temp=NULL;
    return head;
}
//deleting the last node
struct node *deleteatlast(struct node *head)
{
    struct node *ptr=head;
    struct node *previous =NULL;
    while(ptr->next!=NULL)
    {
        previous=ptr;
        ptr=ptr->next;
    }
    previous->next=NULL;
    free(ptr);
    ptr=NULL;
    return head;
}
//deleting last node using single pointer 
void deleteatlastusingsp(struct node *head)
{
    struct node *ptr=head;
    while(ptr->next->next !=NULL)
    {
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
}
//delete the node at specific position
struct node * deleteatspecificposition(struct node *head,int pos)
{
    if(pos==1)
    {
        struct node *current=head;
         head=current->next;
         free(current);
         current=NULL;
         return head;
    }
    struct node *current=head;
    struct node *previous=NULL;
    for(int i=1;i<pos && current!=NULL;i++)
    {
        previous=current;
        current =current->next;
    }
    previous->next=current->next;
    free(current);
    current =NULL;
    return head;
}
//delete the whole linkedlist
struct node *deletewhole(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL){
    temp=temp->next;
    free(head);
    head=temp;
    }
    return head;
}
// reversing the whole list
struct node *reverse(struct node *head)
{
    struct node *temp=NULL;
    struct node *temp2=NULL;
    while(head!=NULL)
    {
        temp2=head->next;
        head->next=temp;
        temp=head;
        head=temp2;
    }
    head=temp;
    return head;
}

int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;
    struct node *current =(struct node *)malloc(sizeof(struct node));
    current->data=98;
    current->next=NULL;
    head->next=current ;
    /*
    METHOD 1
    struct node *current2=(struct node *)malloc(sizeof(struct node));
    current2->data=3;
    current2->next=NULL;
    current->next=current2;*/
    //METHOD 2
    current=(struct node *)malloc(sizeof(struct node));
    current->data=3;
    current->next=NULL;
    head->next->next=current;
    count(head);
    print(head);
    printf("\n");
    head=insertatend(head,24);
    print(head);
    printf("\n");
    head=insertatbeg(head,48);
    print(head);
      printf("\n");
    head=insertatanyposition(head,70,3);
    print(head);
      printf("\n");
    head=insertatanyposition(head,70,7);
    print(head);
       printf("\n");
    head=insertatanyposition(head,70,1);
    print(head);
     printf("\n");
    head=deletethefirst(head);
    printf("list after deletion at first\n");
     print(head);
      head=deleteatlast(head);
    printf("\nlist after deletion at last\n");
     print(head);
    deleteatlastusingsp(head);
    printf("\nlist after deletion at last using single pointer\n");
     print(head);
     head=deleteatspecificposition(head,3);
    printf("\ndeleting at specific positionr\n");
     print(head);
     head=deleteatspecificposition(head,1);
    printf("\ndeleting at specific positionr\n");
     print(head);
    /*head=deletewhole(head);
     printf("\ndeleting at whole list\n");
     print(head); */
     head=reverse(head);
    printf("\nreversing the list\n");
     print(head);

    return 0;
}