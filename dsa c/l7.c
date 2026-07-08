#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *next;
};
struct node *create(int data)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
nn->data=data;
nn->next=NULL;
return nn;
}
struct node *insert(struct node *head,int data)
{
if(head==NULL)
{
struct node *nn=create(data);
nn->next=NULL;
head=nn;
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
temp->next=nn;
nn->next=NULL;
return head;
}
}
void print(struct node *head)
{
if(head==NULL)
{
printf("list is empty\n");
return ;
}
struct node *temp=head;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
}
void reverse(struct node*head)
{
    if(head==NULL)
    {
        return ;
    }
    struct node *temp=head;
    struct node *ptr=NULL;
    while(head!=NULL)
    {
        temp=temp->next;
        head->next=ptr;
        ptr=head;
        head=temp;
    }
    head=ptr;
    printf("\nReversed Linked List-");
    print(head);
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
printf("Linked List: ");
print(head);
reverse(head);
return 0;
}


