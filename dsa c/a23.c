#include<stdio.h>
void fun(int i,int n)
{
    if(i<0)return;

    fun(i-1,n);
    printf("%d",i);

}
int main()
{
    int n,i=0;
    scanf("%d",&n);
    i=n;
    fun(i,n);

    return 0;
    
}