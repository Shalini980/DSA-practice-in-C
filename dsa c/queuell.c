#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

int isempty()
{
    if(front==NULL&&rear==NULL)
    return 1;
    else
    return 0;
}
int peek()
{
    if(isempty())
    {
        printf("List is empty\n");
        exit(1);
    }
    return front->data;
}
void enqueue(int k)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    if(nn==NULL)
    {
        printf("no space");
        exit(1);
    }
    nn->data=k;
    nn->next=NULL;
    if(rear==NULL&&front==NULL)
    {
        front=rear=nn;
    }
    else
    {
        rear->next=nn;
        rear=nn;
    }
}
int dequeue()
{
    int n=front->data;
    struct node *ptr=front;
    front=ptr->next;
    free(ptr);
    ptr=NULL;
    return n;
}
void print()
{
    if(isempty())
    {
        printf("Queue underflown\n");
        exit(1);
    }
    printf("queue-");
    struct node *temp=front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int choice,data;
    printf("Press:\n1.enqueue\n2.dequeue\n3.print top element\n4.exit");
    while(1)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            scanf("%d",&data);
            enqueue(data);
            print();
            break;
            case 2:
            data=dequeue();
            printf("deleted element -%d\n",data);
            print();
            break;
            case 3:
            data=peek();
            printf("the topmost element is %d\n",data);
            break;
            case 4:
            exit(1);
            break;
        }
    }
    return 0;
}