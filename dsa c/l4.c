#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create(int k)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=k;
    nn->prev=NULL;
    nn->next=NULL;
    return nn;
}
struct node *insertfront(struct node *head,int k)
{
    struct node *nn=create(k);
    nn->prev=NULL;
    nn->next=head;
    head=nn;
    return head;
}
struct node *insertend(struct node *head,int k)
{
    if(head==NULL)
    {
        head=insertfront(head,k);
        return head;
    }
    struct node *nn=create(k);
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    nn->prev=ptr;
    ptr->next=nn;
    nn->next=NULL;
    return head;
}
struct node *insertintermediate(struct node *head,int k,int p)
{
    if(head==NULL)
    {
        return head;
    }
    struct node *ptr=head;
    struct node *nn=create(k);
    if(p==1)
    {
        head=insertfront(head,k);
        return head;
    }
    while(p-1>0 && ptr!=NULL)
    {
        ptr=ptr->next;
        p--;
    }
    nn->prev=ptr->prev;
    nn->next=ptr;
    ptr->prev->next=nn;
    ptr->prev=nn;
    return head;
}
struct node *deletefront(struct node *head)
{
    if(head==NULL)
    {
        return head;
    }
    struct node *ptr=head;
    head=ptr->next;
    printf("Node Deleted-%d",ptr->data);
    printf("\n");
    return head;
}
struct node *deleteend(struct node *head)
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
    struct node *temp=ptr->next;
    ptr->next=NULL;
    printf("Node Deleted-%d",temp->data);
    printf("\n");
    return head;
}
int size(struct node*head)
{
    if(head==NULL)
    {
        return 0;
    }
    struct node *ptr=head;
    int count=0;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        count++;
    }
    return count;
}
struct node *deleteintermediate(struct node *head,int p)
{
    if(head==NULL)
    {
    return head;
    }
    if(p==1)
    {
        head=deletefront(head);
        return head;
    }
    struct node *ptr=head;
    while(p-1>0 && ptr!=NULL)
    {
        ptr=ptr->next;
        p--;
    }
    printf("Node Deleted-%d",ptr->data);
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    return head;
}
int isempty(struct node *head)
{
    if(head==NULL)
    return 1;
    else 
    return 0;
}
int findmiddle(struct node *head)
{
    if(head==NULL)
    {
        printf("list is empty");
        return 0;
    }
    struct node *fast=head;
    struct node *slow=head;
    while(fast->next!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    int s=slow->data;
    return s;
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
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
    printf("Press:\n1.to insert node at front\n2.to insert node at end\n3.insert node at specific position\n4.delete node from front\n5.delete node froom end\n6.delete node from specific position\n7.find size of linked list\n8.find middle element of linked list\n9.to exist");
    while(1)
    {
        int choice;
        int data;
        int pos;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            scanf("%d",&data);
            head=insertfront(head,data);
            printf("Doubly Linked List-");
            display(head);
            printf("\n");
            break;
            case 2:
            scanf("%d",&data);
            head=insertend(head,data);
            printf("Doubly Linked List-");
            display(head);
            printf("\n");
            break;
            case 3:
            scanf("%d",&data);
            scanf("%d",&pos);
            head=insertintermediate(head,data,pos);
            printf("Doubly Linked List-");
            display(head);
            printf("\n");
            break;
            case 4:
            head=deletefront(head);
            printf("Doubly Linked List after deletion-");
            display(head);
            printf("\n");
            break;
            case 5:
            head=deleteend(head);
            printf("Doubly Linked List after deletion-");
            display(head);
            printf("\n");
            break;
            case 6:
            scanf("%d",&pos);
            head=deleteintermediate(head,pos);
            printf("Doubly Linked List after deletion-");
            display(head);
            printf("\n");
            break;
            case 7:
            printf("%d",size(head));
            break;
            case 8:
            printf("%d",findmiddle(head));
            break;
            case 9:
            exit(0);
            break;
        }

    }
    return 0;
  
}