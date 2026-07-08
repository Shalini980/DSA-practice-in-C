#include<stdio.h>
int osum(int a[],int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
    {
     if(a[i]%2!=0)
     {
        sum+=a[i];
     }
    }
    return sum;
}
int main()
{
    int n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the array elemnts\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("the sum of odd elements of an array is = %d",osum(a,n));
    return 0;
}