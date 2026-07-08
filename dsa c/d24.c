#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack_arr[max];
int first=-1;
int isempty()
{
    if(first==-1)
    return 1;
    else 
    return 0;
}
int isfull()
{
    if(first==max-1)
    return 1;
    else
    return 0;
}
void push(int data)
{
    first+=1;
    if(isfull())
    {
    return;
    }
    for(int i=first;i>0;i--)
    {
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
}
int peek()
{
    if(isempty())
    {
        printf("stack underflown\n");
        exit(1);
    }
    return stack_arr[0];
}
int pop()
{
    int value=0;
    value=stack_arr[0];
    for(int i=0;i<first;i++)
    {
        stack_arr[i]=stack_arr[i+1];
    }
    first--;
    return value;
    
}
void print()
{
    if(isempty())
    {
        printf("stack underflown\n");
        return ;
    }
    for(int i=0;i<=first;i++)
    {
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice ,data;
    printf("\n1.PUSH\n2.POP\n3.PRINT THR TOP ELEMENT\n4.PRINT ALL THE ELEMENTS OF STAXK\n5.EXITs\n");
    while(1)
    {
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("enter the element to be pushed\n");
        scanf("%d",&data);
        push(data);
        break;
        case 2:
        data=pop();
        printf("the element popped from stack is %d\n",data);
        break;
        case 3:
        printf("%d\n",stack_arr[0]);
        break;
        case 4:
        print();
        break;
        case 5:
        exit(1);
        default:
        printf("wrong choice\n");
    }
    }
    return 0;
}

