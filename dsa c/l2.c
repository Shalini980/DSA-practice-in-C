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
struct node *nn=(struct node *)malloc(sizeof(struct node ));
nn->data=data;
nn->next=NULL;
nn->prev=NULL;
return nn;
}
struct node *insert(struct node *head,int data)
{
if(head==NULL)
{
struct node *temp=create(data);
head=temp;
return head;
}
else
{
struct node *temp=head;
struct node *nn=create(data);
while(temp->next!=NULL)
{
temp=temp->next;
}
nn->data=data;
nn->prev=temp;
temp->next=nn;
nn->next=NULL;

return head;
}
}

void print(struct node *head)
{
if(head==NULL)
{
printf("The list is empty\n");
return;
}
struct node *temp=head;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
free(temp);
temp=NULL;
}
struct node *reverse(struct node *head)
{
if(head==NULL)
{
return head;
}
struct node *ptr=head;
struct node *temp=NULL;
while(head!=NULL)
{
ptr=ptr->next;
head->prev=ptr;
head->next=temp;
temp=head;
head=ptr;
}
head=temp;
return head;
}
int main()
{
struct node* head=NULL;
int flag=1;
printf("Press:\n1 to insert element to linked list\n2 to exit\n");
while(flag)
{
    int choice,data;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        scanf("%d",&data);
        head=insert(head,data);
        break;
        case 2:
        flag=0;
        break;
    }
}
printf("Doubly linked list: ");
print(head);
printf("\nReversed Doubly Linked list:\n");
head=reverse(head);
print(head);
return 0;
}