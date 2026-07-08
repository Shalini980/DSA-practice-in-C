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
void split(struct node*head)
{
    if(head==NULL)
    {
        return ;
    }
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data %2==0)
        {
            head1=insert(head1,temp->data);
            temp=temp->next;
        }
        else
        {
            head2=insert(head2,temp->data);
            temp=temp->next;
        }
    }
        printf("\nOdd Numbered Nodes list-");
        print(head2);
        printf("\nEven Numbered Nodes list-");
        print(head1);
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
printf("Original list: ");
print(head);
split(head);
return 0;
}


