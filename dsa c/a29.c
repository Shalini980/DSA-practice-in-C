#include<stdio.h>
void reverse(int a[],int n,int i)
{
    int temp;
if(i>=n/2) return ;

    temp=a[i];
a[i]=a[n-1-i];
a[n-1-i]=temp;
i++;
reverse(a,n,i);

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
    int i=0;
    reverse(a,n,i);
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}