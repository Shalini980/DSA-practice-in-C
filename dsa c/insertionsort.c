#include<stdio.h>
#include<stdlib.h>
int *insertionsort(int arr[],int n)
{
    int min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i;j<n;j++)
        {
            if(arr[min]>arr[i])
            {
                min=i;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    return arr;
}
int main()
{
    int n;
    printf("enter the number of elements you want in your array\n");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("enter the data\n");
        scanf("%d",&ptr[i]);
    }
    printf("original array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
    printf("insertion sort: ");
    ptr=insertionsort(ptr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
    return 0;
}