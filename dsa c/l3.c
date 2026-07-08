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
nn->next=nn;
head=nn;
return head;
}
else
{
struct node *temp=head;
struct node *nn=create(data);
do
{
temp=temp->next;
}while(temp->next!=head);
temp->next=nn;
nn->next=head;
return head;
}
}
void print(struct node *head)
{
if(head==NULL)
{
printf("list is emprt\n");
return ;
}
struct node *temp=head;
do
{
printf("%d ",temp->data);
temp=temp->next;
}while(temp!=head);
}
void split(struct node*head,int pos)
{
    if(head==NULL)
    {
        return ;
    }
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *temp=head;
   struct node *ptr=NULL;
   while(pos>1 && temp->next!=head)
   {
    temp=temp->next;
    pos--;
   }
   ptr=temp->next;
   head1=head;
   temp->next=head1;
   printf("\nFirst part of the list-");
   print(head1);
   head2=ptr;
   while(ptr->next!=head)
   {
    ptr=ptr->next;
   }
   ptr->next=head2;
   printf("\nsecond part of the list-");
   print(head2);
   free(ptr);
   ptr=NULL;
   free(temp);
   temp=NULL;
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
int pos;
scanf("%d",&pos);
printf("Original list: ");
print(head);
split(head,pos);
return 0;
}


