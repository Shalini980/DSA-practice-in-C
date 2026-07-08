#include<stdio.h>
int fact (int n)
{
    if(n==0 || n==1) 
    return 1;
    else
    return n*fact(n-1);
    return -111;
}
int main()
{
    int n;
    printf("enter the number\n");
    scanf("%d",&n);
    int val=fact(n);
    printf("the factorial is = %d",val);
    return 0;
}