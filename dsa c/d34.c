#include<stdio.h>
#include<stdlib.h>
//revision single linked list
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
        printf("linked list is empty\n");
        return head;
    }
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    struct node *nn=create(data);
    ptr->next=nn;
    nn->next=NULL;
    return head;
}
struct node *insertatpos(struct node *head,int pos,int data)
{
    if(head==NULL)
    {
        printf("linked list is empty\n");
        return NULL;
    }
    if(pos==1)
    {
        struct node *nn=insertatbeg(head,data);
    }
    else
    {
        struct node *ptr=head;
        int i=0;
        for(int i=1;i<pos-1 && ptr!=NULL;i++)
        {
            ptr=ptr->next;
        }
        struct node *nn=create(data);
        nn->next=ptr->next;
        ptr->next=nn;
       

    }
    return head;
}
struct node *deleteatfront(struct node *head)
{
    struct node *ptr=head;
    head=ptr->next;
    free(ptr);
    ptr=NULL;
    return head;
}
struct node *deleteatlast(struct node *head)
{
    if(head==NULL)
    {
        printf("no node in the list\n");
        return head;
    }
    struct node *current=head;
    struct node *prev=head;
    while(current->next!=NULL)
    {
        prev=current;
        current=current->next;
    }
    prev->next=current->next;
    free(current);
    current=NULL;
    return head;
}
struct node *deleteatpos(struct node *head,int pos)
{
    if(head==NULL)
    {
        printf("no node in linked list\n");
        return head;
    }
    struct node *prev=head;
    struct node *curr=head;
    int i=0;
    for(i=0;i<pos-1 && prev!=NULL;i++)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    free(curr);
    curr=NULL;
    return head;
}
struct node *deleteall(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        free(head);
        head=NULL;
    }
    return head;
}
struct node *reverse(struct node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    struct node *prev=NULL;
    struct node *curr=NULL;
    while(head!=NULL)
    {
        curr=head->next;
        head->next=prev;
        prev=head;
        head=curr;
    }
    return head;
}
int count(struct node *head)
{
    int i=0;
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        i++;
    }
    return i;
}
void print(struct node *head)
{
    if(head==NULL)
    {
        printf("the node os empty\n");
        exit(1);
    }
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node *head=NULL;
    int choice ;
    printf("1.creating a node\n2.insert at beg\n3.insert at end\n4.insert at pos\n5.delete at beg\n6.delete at end\n7.delete at pos\n8.reverse\n9.count of list\n10.print\n11.exit\n");
    while(1)
    {
        int data;
        int pos;
        printf("\nenter choice\n");
        scanf("%d",&choice);
        switch(choice)
    {
        case 1:
        printf("enter the data you want in your list\n");
        scanf("%d",&data);
        head=create(data);
        break;
        case 2:
        printf("enter the data you want to insert at beg\n");
        scanf("%d",&data);
        head=insertatbeg(head,data);
        break;
        case 3:
        printf("insert the data you wanna insert in end\n");
        scanf("%d",&data);
        head=insertatend(head,data);
        break;
        case 4:
        printf("enter the data you wanna insert at a particular position\n");
        scanf("%d",&data);
        printf("enter the position\n");
        scanf("%d",&pos);
        head=insertatpos(head,pos,data);
        break;
        case 5:
        head=deleteatfront(head);
        break;
        case 6:
        head=deleteatlast(head);
        break;
        case 7:
        printf("enterthe position you wanna delete\n");
        scanf("%d",&pos);
        head=deleteatpos(head,pos);
        break;
        case 8:
        head=reverse(head);
        break;
        case 9:
        printf("the count is %d",count(head));
        break;
        case 10:
        print(head);
        break;
        case 11:
        exit(1);
    }

    }
    return 0;
    
}