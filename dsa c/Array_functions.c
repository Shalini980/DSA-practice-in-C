#include<stdlib.h>
#include<stdio.h>
int *reverse (int *arr,int n,int i)
{
    for(i;i<n/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-1-i]=temp;
    }
    return arr;
}
int sort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int fun(int arr[],int n)
{
    int i,j,max=0;
    for(i=0;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    return max;
}
int small(int arr[],int n)
{
    int i,min=TMP_MAX;
    for(i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    return min;
}
int fun2(int arr[],int n)
{
    int i,j,max=0,smax=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            j=i;
        }
    }
    for(i=0;i<n;i++)
    {
        if(smax<arr[i] && i!=j)
        {
            smax=arr[i];
        }
    }
    return smax;
}
void count(int arr[],int n)
{
    int i;
    int hash[1000]={0};
    for(i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }
    for(i=0;i<n;i++)
    {

    }
}
int small2(int arr[],int n)
{
    int i,j,min=TMP_MAX,smin=min;
    for(i=0;i<n;i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
            j=i;
        }
         if(smin>arr[i]&& i!=j)
        {
            smin=arr[i];
        }
    }
    return smin;
}
int sum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int n;
    printf("enter the size of array you want\n");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*sizeof(int));
    printf("enter the elements of ypur array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("your array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
    int m=fun(ptr,n);
    printf("\nthe largest element in the array is %d",m);
    int l=small(ptr,n);
    printf("\nthe smallest element in the array is %d",l);
    int m1=fun2(ptr,n);
    printf("\nthe 2nd largest element in the array is %d",m1);
    int l1=small2(ptr,n);
    printf("\nthe 2nd smallest element in the array is %d",l1);
    printf("\nthe reversed array is \n");
    int i;
    ptr=reverse(ptr,n,i=0);
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
    //count(ptr,n);
    sort(ptr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
    int s=sum(ptr,n);
    printf("the sum of array elements is %d\n ",s);
    printf("enter the elment you wanna rotate\n");
    int k;
    scanf("%d",&k);
    int k1=k%n;
    ptr=reverse(ptr,k1-1,i=0);
    ptr=reverse(ptr,n,k1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
    return 0;
}