#include<stdio.h> //array insertion
int *arr(int a[],int n)
{
    int i=0;
    printf("enter the array elements \n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    return a;
}
int main()
{
    int n;
    printf("enter the array size\n");
    scanf("%d",&n);
    int a[n];
    int *s=arr(a,n);
    printf("the array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d",s[i]);
    }
    return 0;
}