#include<stdio.h>
#include<stdlib.h>
#define n 5

void enq (int q[],int *r,int *f,int x)
{
    q[(*r)++]=x;
}
int deq(int q[],int *f)
{
    return q[(*f)++];
}
void push(int q1[],int q2[],int *rear1,int *rear2,int *front1,int *front2,int v)
{
    if((*rear2)==n-1)
    {
        printf("stack is full\n");
        return ;
    }
    else
    {
        enq(q2,rear2,front2,v);
        while((*front1)<(*rear1))
        {
            int x;
            x=deq(q1,front1);

            enq(q2,rear2,front2,x);
        }
        for(int i=0;i<n;i++)
        {
            q1[i]=q2[i];
        }
        *front1=0;
        *rear1=*rear2;
        *front2=0;
        *rear2=0;
    }
}
int pop(int q1[],int q2[],int *rear1,int *rear2,int *front1,int *front2)
{
    if(*front1>=*rear1)
    {
        printf("stack is empty\n");
        return -1;
    }
    else
    {
        return deq(q1,front1);
    }
}
void display(int q1[],int rear1 ,int front1)
{
    for(int i=(rear1-1);i>=front1;i--)
    {
        printf("%d ",q1[i]);
    }
    printf("\n");
}
int main()
{
    int q1[n],q2[n],q[3],rear1=0,rear2=0,front1=0,front2=0;
    printf("Press:\n1 to push\n2 to pop\n3 to exit");
    while(1)
    {
        int choice;
        scanf("%d",&choice);
         int val;
         int w;
        switch(choice)
        {
            case 1:
            scanf("%d",&val);
            push(q1,q2,&rear1,&rear2,&front1,&front1,val);
            printf("Stack-");
            display(q1,rear1,front1);
            break;
            case 2:
            w=pop(q1,q2,&rear1,&rear2,&front1,&front2);
            printf("Element popped from stack-%d",w);
            printf("\nstack after pop operation-");
            display(q1,rear1,front1);
            break;
            case 3:
            exit(1);
        }
    }
    return 0;
}