#include<stdio.h>
void print(int i,int n)
{
    if(i>n)return ;
    printf("%d",i);
    i++;
    print(i,n);
}
int main()
{
    int i=0,n;
    printf("enter the n\n");
    scanf("%d",&n);
print(i,n);
return 0;
}