#include<stdio.h>
#include<stdlib.h>
#define max 4
int queue[max];
int front=-1;
int rear=-1;

int isempty()
{
    if(front==-1 && rear==-1)
    return 1;
    else
    return 0;
}
int isfull()
{
    if(front==0 && rear==max-1|| front==rear+1)
    return 1;
    else
    return 0;
}
void enqueue(int k)
{
    if(isfull())
    {
        printf("Queue Overflown\n");
        exit(1);
    }
    if(front==-1)
    {
        front=0;
    }
    if(rear==max-1)
    {
        rear=0;
    }
    else
    rear++;
    queue[rear]=k;
}
int dequeue()
{
    if(isempty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    int s=queue[front];
    if(front==max-1)
    {
        front=0;
    }
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    front++;
    return s;
}
int peek()
{
    if(isempty())
    {
        printf("Queue underflow");
        exit(1);
    }
    return queue[front];
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