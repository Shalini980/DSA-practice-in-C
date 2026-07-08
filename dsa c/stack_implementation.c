#include<stdio.h>
#include<stdlib.h>
#define size 100
int stack[size];
int top=-1;

int isempty()
{
    if(top==-1)
    {
        printf("stack underflow\n");
        return 1;
    } 
    return 0;
}
void push(int data)
{
    if(top==size-1)
    {
        printf("stack overflown\n");
        exit(1);
    }
    top++;
    stack[top]=data;
}
int pop()
{
    if(isempty())
    return -1;
    int valv=stack[top];
    top--;
    return valv;
}
void sizet()
{
   printf("the size is  %d\n ",top+1);
}
void display()
{
    if(isempty())
    {
        exit(1);
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    } 
    printf("\n");
}
int main()
{
    int choice;
    printf("1.PUSH\n2.POP\n3.ISEMPTY\n4.SIZE\n5.DISPLAY\n6.EXIT\n");
    while(1)
    {
        int data;
        printf("enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the data you want \n");
            scanf("%d",&data);
            push(data);
            break;
            case 2:
            data=pop();
            printf("the popped value is %d \n",data);
            break;
            case 3:
            if(data)
            {
                printf("stack is empty\n");
            }
            else
            {
                printf("not empty\n");
            }
        break;
        case 4:
        sizet();
        break;
        case 5:
        display();
        break;
        case 6:
        exit(1);
        }
    }
    return 0;
    
}