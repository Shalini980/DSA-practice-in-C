#include<stdio.h>
#include<stdlib.h>
int search(int arr[],int n)
{
    int hash[256]={0};
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(hash[i]%2!=0)
        return i;
    }
    return -1;
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
    int f=search(ptr,n);
    if(f==-1)
    {
        printf("no element with odd freq\n");
    }
    else
    {
        printf("the element with odd frequncy is %d\n",f);
    }
    return 0;

}