#include<stdio.h>
int *fun(int a[],int n)
{
    static int rev[100];
    int i=0,j=0;
    for(i=n-1;i>=0;i--)
    {
        rev[j++]=a[i];
    }
    return rev;
}
int main()
{
    int n;
    printf("enter the size of array \n");
    scanf("%d",&n);
    int a[n];
    printf("enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int *s=fun(a,n);
    printf("the reversed array is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",s[i]);
    }
    return 0;

}