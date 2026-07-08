#include<stdio.h>
int ret(int num)
{
    ret(num/2);
    if(num==0)
    {
        return 0;
        
    }
    printf("%d",num % 2);
}
int main()
{
    int num ;
    printf("enter the number\n");
    scanf("%d",&num);
    ret(num);
    return 0;
}