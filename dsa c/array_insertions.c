#include<stdio.h>
#include<stdlib.h>
//insert at begining
int insertatbeg(int arr[],int n,int data)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=data;
    return n+1;
}
//insert at certain position
void insertatcertainposition(int arr2[],int arr3[],int size,int data,int pos)
{
    int i;
    int index=pos-1;
    for(i=0;i<=index-1;i++)
    {
        arr3[i]=arr2[i];
    }
    arr3[index]=data;
    int j;
    for(i=index+1,j=index;i<size+1,j<size;i++,j++)
    {
        arr3[i]=arr2[j];
    }
}
//delete the last element 
int deleteatlast(int size )
{
    return size-1;
}
//delete at begning
int deleteatfront(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    return size-1;
}
int main()
{
    int arr[10],data=10,i,n;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //insert at begning
    n=insertatbeg(arr,n,data);
    printf("array after inserting at begning\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    //insert at certain position 
    int arr2[]={2,34,21,6,7,8,90,67,23,39};
    int pos=5,info=78;
    int size=sizeof(arr2)/sizeof(arr2[0]);
    int arr3[size+1];
    insertatcertainposition(arr2,arr3,size,info,pos);
    printf("\narray after insertion at certain position\n");
    for(i=0;i<size+1;i++)
    {
        printf("%d ",arr3[i]);
    }
    //deleting last element
     printf("\nthe array after deleting last element from array3 is\n");
    int s=sizeof(arr3)/sizeof(arr3[0]);
    s=deleteatlast(s);
    for(i=0;i<s;i++)
    {
        printf("%d ",arr3[i]);
    }
    //delete at front
    printf("\narray after deleting at front\n");
    int y= deleteatfront(arr3,s);
    for(i=0;i<y;i++)
    {
        printf("%d ",arr3[i]);
    }
    return 0;

}