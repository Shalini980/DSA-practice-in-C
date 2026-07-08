#include<stdio.h>
int *fun(int a[],int b[],int n,int m)
{
static int  res[100];
int i=0,j=0,cou;
for(int i=0;i<n;i++)
{
    for(int k=0;k<m;k++)
    {
        if(a[i]==b[k])
        {
          res[j++]=a[i];
        }
    }
}
   return res; 
}
int main()
{
    int n,m;
    printf("enter the size of two arrays\n");
    scanf("%d%d",&n,&m);
    int a[n],b[m];
     printf("enter the first matrix with size %d\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    } 
     printf("enter the second matrix with size %d\n",m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    int *c=fun(a,b,n,m);
    printf("the intersection of two matrix is \n");
    for(int i=0;i<m+n;i++)
    {
        if(c[i]!=0)
        {
        printf("%d ",c[i]);
    }
    }
    return 0;
}