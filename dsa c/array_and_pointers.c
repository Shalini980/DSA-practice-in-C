#include<stdio.h>
int *fun(int a[],int b[],int n,int m)
{
    static int res[100];
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        res[j++]=a[i];
    }
    for(i=0;i<m;i++)
    {
        res[j++]=b[i];
    }
return res;
}
int main()
{
    int n,m;
    printf("enter the size of two array\n");
    scanf("%d%d",&n,&m);
    int a[n],b[m];
    printf("enter the first matrix of size %d\n",n);
    for(int i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
printf("enter the second matrix of size %d\n",m);
    for(int i=0;i<m;i++)
{
    scanf("%d",&b[i]);
}
int *s=fun(a,b,n,m);
printf("the union matrix is\n");
for(int i=0;i<m+n;i++)
{
    printf("%d ",s[i]);
}
return 0;
}