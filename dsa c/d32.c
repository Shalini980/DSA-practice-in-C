#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000
int top=-1;
char stack[max];
char infix[max];
char postfix[max];
int precedence(char  symbol)
{
    switch(symbol)
    {
        case'^':
        return 3;
        case '/':
        case'*':
        return 2;
        case'+':
        case'-':
        return 1;
        default:
        return 0;
    }
}
void push(char data)
{
    if(top==max-1)
    {
        printf("stack is full\n");
        exit(1);
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
char pop()
{
    if(isempty())
    {
        return '\0';
    }
    char temp=stack[top];
    top--;
    return temp;
}
int space(char symbol)
{
    if(symbol==' '||symbol=='\t')return 1;
    return 0;
}
void intopost()
{
    int j=0;
    char symbol,next;
    for(int i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(!space(symbol))
        {
        switch(symbol)
        {
        case '(':
        push(symbol);
        break;
        case ')':
        while((next=pop())!='(')//left parenthesis will bw popped too
        {
            postfix[j++]=next;
        }
        break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        while(!isempty() && precedence(stack[top])>=precedence(symbol))
        {
            postfix[j++]=pop();
        }
        push(symbol);
        break;
        default:
        postfix[j++]=symbol;
    }
        }
    }
    while(!isempty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int main()
{
    printf("enter the infix expression\n");
    gets(infix);
    intopost();
    puts(postfix);
    return 0;

}
