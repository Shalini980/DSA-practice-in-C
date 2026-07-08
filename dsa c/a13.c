#include<stdio.h>
int polymul(int a[],int b[],int c[],int m,int n)
{
    int k=0;
    for(int i=0;i<m+n;i++)
    {
        c[k]+=a[i]*b[k-i];
        k++;
    }
    for(k=m+1;k<m+n;k++)
    {
        a[k]=0;
    }
    for(k=n+1;k<m+n;k++)
    {
        b[k]=0;
    }
    return m+n;
}
int main()
{
    int m,n;
    printf("enter the size of array\n");
    scanf("%d%d",&m,&n);
    int a[m],b[n],c[1000];
    printf("enter the array elements of size %d",m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
       printf("enter the array elements of size %d",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int g=polymul(a,b,c,m,n);
    printf("%d",g);
    return 0;
}