#include<stdio.h>
int *fun(int a[],int n,int k)
{

}
int main()
{
    int n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int k;
    printf("enter the no. you wanna left rotate");
    scanf("%d",&k);
    int *s=fun(a,n,k);
    for(int i=0;i<n;i++)
    {
        printf("%d",s[i]);
    }
    return 0;
}