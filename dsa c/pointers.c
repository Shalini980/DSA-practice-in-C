#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    printf("enter the number of integer");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n* sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("enter the integer you want to enter");
        scanf("%d",(ptr+i));
    }
    for(i=0;i<n;i++)
    {
        printf("%d",*(ptr+i));
    }
    return 0;
}