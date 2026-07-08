#include<stdio.h>
#include<stdlib.h>
void rotate(int arr[],int start,int end)
{
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t){
    int n,k;
    printf("enter the size of array you want\n");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("enter the data of your array\n");
        scanf("%d",&ptr[i]);
    }
    printf("enter the number you wanna rotate your array\n");
    scanf("%d",&k);
    k=k%n;
    rotate(ptr,0,k-1);
    rotate(ptr,k,n-1);
    rotate(ptr,0,n-1);
    printf("the rotated array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
    t--;
    }
    return 0;
}