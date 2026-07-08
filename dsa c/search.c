#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool searchm(int n,int arr[][100],int key)
{
    int row=0,col=n-1;
    while(row<n && col>=0)
    {
        if(arr[row][col]==key)
        {
            return true;
        }
        if(arr[row][col]<key)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return false;
}
int main()
{
    int n;
    printf("Enter the size of your array\n");
    scanf("%d",&n);
    int ptr[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&ptr[i][j]);
        }
    }
    int key;
    printf("enter the data you want to search\n");
    scanf("%d",&key);
    if(searchm(n,ptr,key))
    {
        printf("the key is present\n");
    }
    else
    {
        printf("key is not present\n");
    }
    return 0;

}