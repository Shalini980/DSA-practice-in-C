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
void prime(int num)
{
    int i=2;
    while(num!=1)
    {
        while(num%i==0)
        {
            push(i);
            num=num/i;
        }
        i++;
    }
    while(top!=-1)
    {
        printf("%d ",pop());
    }
}

int main()
{
    int choice ,data;
    int num;
    printf("enter the number you want prime factors of \n");
    scanf("%d",&num);
    
        prime(num);
      
    return 0;
    
}