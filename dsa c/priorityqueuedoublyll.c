#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    int priority;
    struct node *next;
    struct node *prev;
};
struct node *create(int d,int p)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    if(nn==NULL)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    nn->data=d;
    nn->priority=p;
    nn->next=NULL;
    nn->prev=NULL;
    return nn;
}
struct node *enqueue(struct node *front,int d,int p)
{
    struct node *ptr=NULL;
    struct node *nn=create(d,p);
    if(nn==NULL)
    {
        return front;
    }
    if(front==NULL || front->priority>p)
    {
        nn->next=front;
        if(front!=NULL)
        {
            front->prev=nn;
        }
        front=nn;
        return front;
    }
    else
    {
        ptr=front;
        while(ptr->next!=NULL && ptr->next->priority<=p)
        {
            ptr=ptr->next;
        }
        nn->next=ptr->next;
        nn->prev=ptr;
        if(ptr->next!=NULL)
        ptr->next->prev=nn;
        ptr->next=nn;
        return front;    
    }
}
struct node *dequeue(struct node *front)
{
    if(front==NULL)
    {
        printf("EMPYU");
        return front;
    }
    struct node *ptr=front;
    front=ptr->next;
    if(front!=NULL)
    front->prev=NULL;
    int data=ptr->data;
    free(ptr);
    ptr=NULL;
    printf("Deleted Node-%d",data);
    return front;
}
void display(struct node*front)
{
    if(front==NULL)
    {
        printf("empty queue\n");
        return ;
    }
    struct node *ptr=front;
    while(ptr!=NULL)
    {
        printf("%d-",ptr->data);
        printf("%d->",ptr->priority);
        ptr=ptr->next;
    }
}
int main()
{
    struct node *front=NULL;
    int choice,data,priority;
    printf("Press:\n1.enqueue\n2.dequeue\n3.display\n4.exit");
    while(1)
    {
        printf("\nenter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter data\n");
            scanf("%d",&data);
            printf("enter priority\n");
            scanf("%d",&priority);
            front=enqueue(front,data,priority);
            printf("Node added succesfully-");
            break;
            case 2:
            front=dequeue(front);
            break;
            case 3:
            printf("priority queue-");
            display(front);
            break;
            case 4:
            exit(1);
        }
    }
    return 0;
    
}