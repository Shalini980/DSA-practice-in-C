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
    int m;
    printf("\nenter the new size");
    scanf("%d",&m);
    ptr=(int *)realloc(ptr,m*sizeof(int));
    for(i=n;i<m;i++)
    {
        printf("enter the values you want to enter\n");
        scanf("%d",(ptr+i));
    }
    for(i=0;i<m;i++)
    {
        printf("%d",*(ptr+i));
    }

    return 0;
}