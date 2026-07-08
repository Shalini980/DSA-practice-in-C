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
struct node *merge(struct node*head,struct node*head1)
{
if(head1==NULL)
{
return head;
}
if(head==NULL)
{
return head1;
}
struct node *temp=head;
struct node *temp1=head1;
do
{
temp=temp->next;
}while(temp->next!=head);
do
{
temp1=temp1->next;
}while(temp1->next!=head1);
temp->next=head1;
temp1->next=head;
return head;
}
int main()
{
struct node *head=NULL;
struct node *head1=NULL;
int flag=1;
printf("Press:\n1 to insert\n2 to exit\n");
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
printf("Press:\n1 to insert\n2 to exit\n");
flag=1;
while(flag)
{
    int choice,data;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        scanf("%d",&data);
        head1=insert(head1,data);
        break;
        case 2:
        flag=0;
        break;
    }
}
printf("First circular linked list: ");
print(head);
printf("\nSecond circular linked list: ");
print(head1);
printf("\nFinal concatenated linked list: \n");
head=merge(head,head1);
print(head);

return 0;
}