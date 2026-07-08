#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
int top=-1;
char stack[max];
void push(char data)
{
    if(top==max-1)
    {
        printf("stack is full \n");
        return ;
    }
    top++;
    stack[top]=data;
}
int isempty()
{
    if(top==-1)
    return 1;
    return 0;
}
int match(char a,char b)
{
    if(a=='['&& b==']')return 1;
    if(a=='('&& b==')')return 1;
    if(a=='{' && b=='}')return 1;
    return 0;
}
char pop()
{
    if(isempty())
    {
        printf("stack is empty\n");
        exit(1);
    }
    char value=stack[top];
    top--;
    return value;
}
int checkbalance(char *s)
{
    int i;
    char temp;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='['||s[i]=='('||s[i]=='{')
        {
            push(s[i]);
        }
        if(s[i]==']'||s[i]==')'||s[i]=='}')
        {
            if(isempty())
            {
                printf("right brackets are more than left brackets\n");
                return 0;
            }
            else
            {
                temp=pop();//to pop an element from stack
                if(!match(temp,s[i]))
                {
                    printf("mismatched bracket\n");
                    return 0;
                }
                                                                                                                                                                                            
            }
        }
    }
    if(isempty())
    {
        printf("brackets are well balaced\n");
        return 1;
    }
    else
    {
        printf("left brackets are more than right\n");
        return 0;
    }
}
int main()
{
    int balance;
    char expr[max];
    printf("enter the algebraic expression\n");
    gets(expr);
    balance=checkbalance(expr);
    if(balance==1)
    {
        printf("expression is valid\n");
    }
    else 
    {
        printf("expression is not valid\n");
    }
    return 0;
}
