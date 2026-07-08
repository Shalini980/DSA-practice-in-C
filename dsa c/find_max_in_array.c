#include<stdio.h>
int max(int a[],int n)
{
    int i=0,m=-1;
    for(i=0;i<n;i++)
    {
        if(m<a[i])
        {
            m=a[i];
        }
    }
    return m;
}
int main()
{
    int n;
    printf("enetr the array size\n ");
    scanf("%d",&n);
    int a[n];
    printf("enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int yes =max(a,n);
    printf("the maximum value from the array is %d",yes);
    return 0;


}