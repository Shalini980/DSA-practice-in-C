#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 1000
int top=-1;
int stack[max];
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
void push(int data)
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
int pop()
{
    if(isempty())
    {
        return '\0';
    }
    int temp=stack[top];
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
        while((next=pop())!='(')
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
int evolpost()
{
    int i=0;
    int a,b;
    for(int i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
        push(postfix[i]-'0');
        else
        {
            b=pop();
            a=pop();
            switch(postfix[i])
            {
                case '+':
                push(a+b);
                break;
                 case '-':
                push(a-b);
                break;
                 case '/':
                push(a/b);
                break;
                 case '*':
                push(a*b);
                break;
                 case '^':
                push(pow(a,b));
                break;
            }

        }

    }
    return pop();
}
int main()
{
    printf("enter the infix expression\n");
    gets(infix);
    intopost();
    puts(postfix);
    int result=evolpost();
    printf("%d",result);
    return 0;
    

}
