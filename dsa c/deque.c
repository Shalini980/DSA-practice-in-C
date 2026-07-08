#include<stdio.h>
#include<stdlib.h>
#define max 100
int front=-1;
int rear=-1;
int queue[max];

int isempty()
{
    if(front==-1 && rear==-1)
    return 1;
    else
    return 0;
}
int isfull()
{
    if(front==0&&rear==max-1 ||front==rear+1)
    return 1;
    else
    return 0;
}
void enqueuefront(int k)
{
    if(isfull())
    {
        printf("Queue overflown\n");
        exit(1);
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(front==0)
    {
        front=max-1;
    }
    else
    front--;
    queue[front]=k;
}
void enqueuerear(int k)
{
    if(isfull())
    {
        printf("Queue overflown\n");
        exit(1);
    }
    if(rear==max-1)
    {
        rear=0;
    }
    else if (front==-1)
    {
        front=0;
        rear=0;
    }
    else
    rear++;
    queue[rear]=k;
}
int dequeuefront()
{
    if(isempty())
    {
        printf("queue underflow");
        exit(1);
    }
    int data=queue[front];
    if(front==max-1)
    {
        front=0;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    front++;
    return data;
}
int dequeuerear()
{
    if(isempty())
    {
        printf("queue underflow\n");
        exit(1);
    }
    int data=queue[rear];
    if(rear==0)
    {
        rear=max-1;
    }
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    rear--;
    return data;
}
void print()
{
    if(isempty())
    {
        printf("Queue underflown\n");
        exit(1);
    }
    int temp=front;
    if(front<=rear)
    {
        while(temp<=rear)
        {
            printf("%d ",queue[temp]);
            temp++;
        }
    }
    else
    {
        temp=front;
        while(temp<=max-1)
        {
            printf("%d ",queue[temp]);
            temp++;
        }
        temp=0;
        while(temp<=rear)
        {
            printf("%d ",queue[temp]);
            temp++;
        }
    }

    printf("\n");
}
int main()
{
    int choice,data;
    printf("Press:\n1.enqueuefront\n2.dequeuefront\n3.enqueuerear\n4.dequeuerear\n5.exit");
    while(1)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            scanf("%d",&data);
            enqueuefront(data);
            print();
            break;
            case 2:
            data=dequeuefront();
            printf("deleted element -%d\n",data);
            print();
            break;
            case 3:
            scanf("%d",&data);
            enqueuerear(data);
            print();
            break;
            case 4:
            data=dequeuerear();
            printf("deleted element -%d\n",data);
            print();
            break;
            case 5:
            exit(1);
        }
    }
    return 0;
}
