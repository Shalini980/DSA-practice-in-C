#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int p;
    int data;
    struct node *next;
};
struct node *create(int k,int n)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node ));
    nn->data=k;
    nn->p=n;
    nn->next=NULL;
    return nn;
}
struct node *enqueue(struct node *front,int k,int n)
{
    struct node *nn=create(k,n);
    if(front==NULL || front->p>n)
    {
        nn->next=front;
        front=nn;
        return front;
    }
    else
    {
        struct node *ptr=front;
        while(ptr->next!=NULL && n>=ptr->next->p)
        {
            ptr=ptr->next;
        }
        nn->next=ptr->next;
        ptr->next=nn;
        return front;
    }
}
void print(struct node*front)
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
        printf("%d->",ptr->p);
        ptr=ptr->next;
    }
}
struct node *dequeue(struct node *front)
{
    if(front==NULL)
    {
        return front;
    }
    struct node *ptr=front;
    front=ptr->next;
    int d=ptr->data;
    free(ptr);
    ptr=NULL;
    printf("deleted node-%d",d);
    return front;
}
int main()
{
    struct node *front=NULL;
    int choice,data,priority;
    printf("Press:\n1.enqueue\n2.dequeue\n3.exit\n");
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
            printf("priority queue-");
            print(front);
            break;
            case 2:
            front=dequeue(front);
            printf("\npriority queue-");
            print(front);
            break;
            case 3:
            exit(1);
        }
    }
    return 0;
    
}