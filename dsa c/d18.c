#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
//creating a node
struct node *createnode(int data)//add to empty
{
    struct node *nn=(struct node *)malloc(sizeof (struct node));
    nn->data=data;
    nn->next=nn;
    return nn;
}
//insert at beginning
struct node *insertatbeg(struct node *tail,int data)
{
    struct node*nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=tail;
    tail->next=nn;
    return tail;
}
//printing
void print(struct node *tail)
{
    if(tail==NULL)
    printf("no node in the list\n");
    else
    {
    struct node *ptr=tail->next;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=tail->next);
    }   
}
//inserting at end
struct node *insertatend(struct node *tail,int data)
{
    struct node *nn=createnode(data);
    nn->next=tail->next;
    tail->next=nn;
    tail=nn;
    return tail;

}
//insert between
struct node *insertbetween(struct node *tail,int data,int pos)
{
    int i=1;
    struct node *nn=createnode(data);
    struct node *ptr=tail->next;
    struct node *prev=NULL;
    if(pos==1)
    {
        tail=insertatbeg(tail,data);
        return tail;
    }
    else{
    do
    {
     prev=ptr;   
     ptr=ptr->next;
     i++;
    } while (i<pos);
    if(ptr==tail)
    {
        tail=insertatend(tail,data);
        return tail;
    }
    else
    {
    prev->next=nn->next;
    nn->next=ptr;
    }
    return tail;
    }
}
//seperate function to create a complete circular linked list 
struct node *createlist(struct node *tail)
{
    int i,n,data;
    printf("enter the numvber of elements in list \n");
    scanf("%d",&n);
    if(n==0)
    return tail;
    printf("enter the 1st data");
    scanf("%d",&data);
    tail=createnode(data);
    for(i=1;i<n;i++)
    {
        printf("Enter the elements %d",i+1);
        scanf("%d",&data);
        tail=insertatend(tail,data);
    }
    return tail;

}
//deleting the first node 
struct node *deletefront(struct node *tail)
{
    if(tail==NULL)
    return tail;
    struct node *ptr=tail->next;
    tail-> next=ptr->next;
    free(ptr);
    ptr=NULL;
    return tail;

}
//delete the last node
struct node *dellast(struct node *tail)
{
    struct node *p=tail->next;
    while(p->next!=tail)
    {
        p=p->next;
    }
    p->next=tail->next;
    free(tail);
    tail=p;
    return tail;
}
//deleting intermediate 
struct node *delcertain(struct node *tail,int pos)
{
    if(tail==NULL)
    return tail;
    struct node *ptr=tail->next;
    struct node *prev=NULL;
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
}
int i=1;
if(pos==1)
{
    tail=deletefront(tail);
    return tail;
}
else
{
while (i<pos)
{
    prev =ptr;
    ptr=ptr->next;
    i++;
}
prev->next=ptr->next;
if(ptr==tail)
{
    tail=prev;
}
free(ptr);
ptr=NULL;
}
return tail;
}
//counting number of nodes
int count(struct node *tail)
{
    int count=0;
    struct node *temp=tail->next;
   do
    {
        count++;
        temp=temp->next;
        
    } while(temp!=tail->next);
    return count;
}
//searching an element 
int search(struct node *tail,int element)
{
    struct node *temp=tail->next;
    int index=0;
    if(tail==NULL)
    return -2;
    do
    {
        if(temp->data==element)
        {
            return index;
        }
        temp=temp->next;
        index++;
    } while (temp!=tail->next);
    return -1;
}
int main()

{
    struct node *tail;
    printf("the list after creating is \n");
    tail=createnode(1);
    print(tail);
    printf("\nthe list after inserting at beg is \n");
    tail=insertatbeg(tail,2);
    print(tail);
     printf("\nthe list after inserting at last is \n");
    tail=insertatend(tail,3);
    print(tail);
    printf("\nthe list after inserting at certain position is \n");
    tail=insertbetween(tail,4,2);
    print(tail);
    printf("\nthe list after inserting at beg is \n");
    tail=insertatbeg(tail,2);
     printf("\nthe list after inserting at certain position is \n");
    tail=insertbetween(tail,4,1);
    print(tail);
     printf("\nthe list after inserting at certain position is \n");
    tail=insertbetween(tail,4,5);
    print(tail);
    /*printf("\ncreating the new list \n");
     tail=NULL;
    tail=createlist(tail);
    print(tail);*/
     printf("\nthe list after deleting at front position is \n");
    tail=deletefront(tail);
    print(tail);
    printf("\nthe list after deleting at last position is \n");
    tail=dellast(tail);
    print(tail);
     printf("\nthe list after deleting at certain position is \n");
    tail=delcertain(tail,1);
    print(tail);
     printf("the list after creating is \n");
    tail=createnode(1);
    print(tail);
    printf("\nthe list after inserting at beg is \n");
    tail=insertatbeg(tail,2);
    print(tail);
     printf("\nthe list after inserting at last is \n");
    tail=insertatend(tail,3);
    print(tail);
    printf("\nthe list after inserting at certain position is \n");
    tail=insertbetween(tail,4,2);
    print(tail);
    printf("\nthe list after deleting at certain position is \n");
    tail=delcertain(tail,1);
    print(tail);
     printf("\nthe count is  \n");
    int n=count(tail);
    printf("%d :",n);
    printf("\nThe searched element is %d\n",search(tail,5));
    return 0;
}