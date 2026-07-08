#include<stdio.h>//deletion
int *arr(int a[],int n,int x)
{int i=0;
for(i=x-1;i<n;i++)
{
a[i]=a[i+1];
}

    return a;
}


int main()
{
    int n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the array elements\n");
    for(int i=0 ;i<n;i++)
    {
        scanf("%d",&a[i]);
    
    }
    int x;
    printf("enter the element from array you want to delete");
    scanf("%d",&x);
    int *s=arr(a,n,x);
    printf("the new array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d",i);
        printf("%d\n",s[i]);
    }
    return 0;
    
}