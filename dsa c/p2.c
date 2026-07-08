#include<stdio.h>
#include<stdlib.h>
int count=0;
void f()
{
    if(count==5)return ;
    printf("shalini\n");
    count ++;
    f();
}
void fun(int i,int n)
{
    if(i>n)return;
    printf("%d ",i);
    fun(i+1,n);
}
void fun2(int n)
{
    if(n<1)return ;
    printf("%d ",n);
    fun2(n-1);
}
void backtr(int i,int n)
{
    if(i<1)return;
    backtr(i-1,n);
    printf("%d ",i);
}
void backtr2(int i,int n)
{
    if(i>n)return;
    backtr2(i+1,n);
    printf("%d ",i);
}
void sumt(int i,int s)
{
    if(i<1)
    {
        printf("%d ",s);
        return ;
    }
    sumt(i-1,s+i);
}
int main()
{
    f();
    fun(1,10);
    printf("\n");
    fun2(10);
    printf("\n");
    backtr(10,10);
    printf("\n");
    backtr2(1,10);
    printf("\n");
    int s=0;
    printf("the summation is \n");
    sumt(10,s);
    return 0;
}
