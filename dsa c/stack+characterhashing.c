#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
char stack[size];
int top=-1;

void push(char data)
{
    if(top==size-1)
    {
        printf("stack overflown\n");
        exit(1);
    }
    top++;
    stack[top]=data;
}
char  pop()
{
    if(top==-1)
    {
        printf("stack underflown\n");
        return -1;
    }
    char val=stack[top];
    top--;
    return val;
}
int matched(char a,char b)
{
    if(a=='[' && b==']')return 1;
    if(a=='{' && b=='}')return 1;
    if(a=='(' && b==')')return 1;
    return 0;
}
int checkbal(char *s)
{
    char temp;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='['||s[i]=='{'||s[i]=='(')
        {
            push(s[i]);
        }
        if(s[i]==']'||s[i]=='}'||s[i]==')')
        {
            if(top==-1)
            {
                printf("right brackets are more than left");
            }
            else
            {
                temp=pop();
                if(!matched(temp,s[i]))
                {
                    printf("mismatched\n");
                    return 0;
                }
            }
        }
    }
    if(top==-1)
    {
        printf("well balanced\n");
        return 1;
    }
    else
    {
        printf("not balanced\n");
        return 0;
    }

}

int main()
{
    char exprs[size];
    printf("enter the expression\n");
    gets(exprs);
    int balance=checkbal(exprs);
    if(balance==1)
    {
        printf("valid\n");
    }
    else 
    printf("invalid\n");
    return 0;
}