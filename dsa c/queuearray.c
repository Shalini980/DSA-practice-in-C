//queue
#include<stdio.h>
#include<stdlib.h>
#define max 100
int queue[max];
int front=-1;
int rear=-1;

int isfull()
{
    if(rear==max-1)
    return 1;
    else
    return 0;
}
int isempty()
{
    if(front==-1&&rear==-1||front==rear+1)
    return 1;
    else
    return 0;
}
void enqueue(int data)
{
    if(isfull())
    {
        printf("queue overflown\n");
        exit(1);
    }
    if(front==-1&&rear==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=data;
}
int peek()
{
    if(isempty())
    {
        printf("queue underflown\n");
        exit(1);
    }
    return queue[front];
}
int size()
{
    return rear;
}
int dequeue()
{
    int data;
    if(isempty())
    {
        printf("queue underflown\n");
        exit(1);
    }
    data=queue[front];
    front++;
    return data;
}
void print()
{
    if(isempty())
    {
        printf("Queue underflown\n");
        exit(1);
    }
    int i;
    printf("Queue-");
    for(i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main()
{
    int choice,data;
    printf("Press:\n1.enqueue\n2.dequeue\n3.to calculate size\n4.exit");
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
            data=size();
            printf("size= %d\n",data+1);
            break;
            case 4:
            exit(1);
            break;
        }
    }
    return 0;
}