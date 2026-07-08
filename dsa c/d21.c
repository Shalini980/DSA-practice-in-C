#include<stdio.h>
#include<stdlib.h>
struct node
{
    float coeff;
    int  expo;
    struct node *next;
};
struct node *create(float coeff,int expo)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->coeff=coeff;
    nn->expo=expo;
    nn->next =NULL;
    return nn;
}
struct node *addatend(struct node *head,int expo,float coeff)
{
    struct node *nn=create(coeff,expo);
    if(head==NULL)
    {
        head=nn;
        return head;
    }
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    return head;
}
struct node *sortinsert(struct node *head,float coeff,int expo)
{
    struct node *temp=head;
    struct node *nn=create(coeff,expo);
    int key=nn->expo;
    if(head==NULL || key>temp->expo)
    {
        nn->next=head;
        head=nn;
    }
    else
    {
    while(temp->next!=NULL && temp->next->expo>key)
    {
        temp=temp->next;
    }
    nn->next=temp->next;
    temp->next=nn;
}
return head;
}
struct node *createlist(struct node *head)
{
    float coeff;
    int n,expo;
    printf("enter the no. of nodes you want in your list\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the coefficient of term %d\n",i+1);
        scanf("%f",&coeff);
         printf("enter the exponent of term %d\n",i+1);
        scanf("%d",&expo);
        head=sortinsert(head,coeff,expo);

    }
    return head;
}
void print(struct node *head)
{
    if(head==NULL)
    printf("no polynomial in list\n");
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        printf("%0.1f x^%d +",ptr->coeff,ptr->expo);
        ptr=ptr->next;
    }
    printf("%.1f x^%d",ptr->coeff,ptr->expo);
}
struct node *add(struct node *head,struct node *head1)
{
    struct node *ptr1=head;
    struct node *ptr2=head1;
    struct node *head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {
    if(ptr1->expo==ptr2->expo)
    {
        head3=sortinsert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    else if (ptr1->expo>ptr2->expo)
    {
        head3=sortinsert(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->next;
    }
    else if(ptr1->expo<ptr2->expo)
    {
        head3=sortinsert(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->next;
    }
    }
    while(ptr1!=NULL)
    {
        head3=sortinsert(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        head3=sortinsert(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->next;
    }
    return head3;

}
struct node *mul(struct node *head,struct node *head1)
{
    struct node *ptr1=head;
    struct node *ptr2=head1;
    struct node *head3=NULL;
    while(ptr1!=NULL)
    {
        while(ptr2!=NULL)
        {
            head3=sortinsert(head3,ptr1->coeff*ptr2->coeff,ptr1->expo+ptr2->expo);
            ptr2=ptr2->next;
        }
        ptr2=head1;
        ptr1=ptr1->next;
    }
    struct node *ptr3=head3;
    struct node *temp=NULL;
    while(ptr3->next!=NULL)
    {
        if(ptr3->expo==ptr3->next->expo)
        {
            ptr3->coeff=ptr3->coeff+ptr3->next->expo;
            temp=ptr3->next;
            ptr3->next=ptr3->next->next;
            free(temp);
            temp=NULL;
        }
        else
        ptr3=ptr3->next;
    }
    return head3;
}
int main()
{
    struct node *head=NULL;
    printf("enter the polynomial\n");
    head=createlist(head);
    print(head);
    struct node *head1=NULL;
    printf("\nenter 2nd polynomial\n");
    head1=createlist(head1);
    print(head1);
    printf("\nthe added polynomial is \n");
    struct node *sum=add(head,head1);
    print(sum);
     printf("\nthe multiplied polynomial is \n");
    struct node *multiply=mul(head,head1);
    print(multiply);

    return 0;
}
