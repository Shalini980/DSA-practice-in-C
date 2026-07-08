#include<stdio.h>
#include<stdlib.h>
#define max 100
int stack[max];
int top=-1;
void push(int data)
{
    if(top==max-1)
    {
        printf("stack overflow\n");
        return ;
    }
    top++;
    stack[top]=data;
}
int pop()
{
    int val=stack[top];
    top--;
    return val;
}
void convert(int num)
{
    int i=2;
    while(num!=0)
    {
        push(num%2);
        num=num/i;
    }
    printf("decimal to binary conversion is \n");
    while(top!=-1)
    {
        printf("%d ",pop());
    }
}
int main()
{
    int n;
    printf("enter the number you want conversion of\n ");
    scanf("%d",&n);
    convert(n);
    return 0;
    
}