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
struct node *addatend(struct node *head,int data)
{
    struct node *nn=create(data);
    if(head==NULL)
    {
        head=nn;
    }
    else
    {
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    }
    return head;
}
struct node *createlist(struct node *head)
{
    int n,data;
    printf("enter the no. of digits in the number \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data of digit %d",i+1);
        scanf("%d",&data);
        head=addatend(head,data);
    }
    return head;
}
struct node *reverse(struct node *head)
{
    struct node *curr=NULL;
    struct node *prev=NULL;
    while(head!=NULL)
    {
        curr=head->next;
        head->next=prev;
        prev=head;
        head=curr;
    }
    head=prev;
    return head;   
}
void print(struct node *head)
{
    if(head==NULL)
    {
        printf("no node in the list\n");
    }
    else
    {
        struct node *ptr=head;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
struct node *add(struct node *head,struct node *head2)
{
    struct node *ptr1=head;
    struct node *ptr2=head2;
    struct node *head3=NULL;
    int sum,carry=0;
    while(ptr1!=NULL || ptr2!=NULL)
    {
        sum=0;
        if(ptr1!=NULL)
        {
            sum+=ptr1->data;
        }
        if(ptr2!=NULL)
        {
            sum+=ptr2->data;
        }
       sum=sum+carry;
       carry=sum/10;
       sum=sum%10;
        head3=addatend(head3,sum);
         if(ptr1!=NULL)
        ptr1=ptr1->next;
         if(ptr2!=NULL)
        ptr2=ptr2->next;
    }
    if(carry)
    head3=addatend(head3,carry);
   return head3;
}
int main()
{
    int n;
    struct node *head=NULL;
   printf("enter the first number\n");
   head=createlist(head);
   print(head);
   struct node *head2=NULL;
   printf("\nenter the second number\n");
   head2=createlist(head2);
   print(head2);
   head=reverse(head);
   head2=reverse(head2);
   printf("\nthe summtaion of two no.s is ");
   struct node *sum=add(head,head2);
   print(sum);
   printf("\n");
   sum=reverse(sum);
   print(sum);
   

   return 0;
}