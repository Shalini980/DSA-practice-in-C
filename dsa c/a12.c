#include<stdio.h>
int polyadd(int a[],int b[],int c[],int m,int n)
{
    int i,p,d;
    p=m>n?n:m;
    for(i=0;i<p;i++)
    {
        c[i]=a[i]+b[i];
    }
    d=m<n?n:m;
    if(m<n)
    {
        for(i=p=1;i<=d;i++)
        {
            c[i]=b[i];
        }
    }
    else
    {
        for(i=p+1;i<=d;i++)
        {
            c[i]=a[i];
        }
    }
    return d;
}
int main()
{
    int m,n;
    printf("enter the size of two array\n");
    scanf("%d%d",&m,&n);
    int a[m],b[n], c[1000];
    printf("print the array elements of size of %d",m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
      printf("print the array elements of size of %d",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int g=polyadd(a,b,c,m,n);
    printf("%d",g);
    return 0;
}