#include<stdio.h>
void print(int i,int n)
{
    if(i<0)return ;
    printf("%d",i);
    i--;
    print(i,n);
}
int main()
{
    int i,n;
    printf("enter the n\n");
    scanf("%d",&n);
    i=n;
print(i,n);
return 0;
}