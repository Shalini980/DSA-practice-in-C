#include<stdio.h>
void printarray(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
void reverse(int a[],int start,int end)
{
    int temp;
    if(start<end)
    {
        temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        reverse(a,start+1,end-1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int start=0,end=n-1;
    reverse(a,start,end);
    printarray(a,n);
    return 0;

}
