#include<stdio.h>
#include<stdlib.h>
#define max 4
int stack_arr[max];
int top=-1;
int isfull()
{
    if(top==max-1)
    return 1;
    else
    return 0;
}
int isempty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(int data)
{
    if(isfull())
    {
        printf("stack is full\n");
        return ;
    }
    top=top+1;
    stack_arr[top]=data; 
}
int pop()
{
    if(isempty())
    {
        printf("stack underflown\n");
        exit(1);
    }
    
    int value=stack_arr[top];
    top--;
    return value;
}
void print()
{
    if(isempty())
    {
        printf("stack underflow\n");
        return;
    }
    for(int i=top;i>-1;i--)
    {
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

int main()
{
    int data,choice;
     printf("\n1.PUSH\n2.POP\n3.PRINT THR TOP ELEMENT\n4.PRINT ALL THE ELEMENTS OF STAXK\n5.EXIT\n");
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
        printf("\n%d",stack_arr[top]);
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
