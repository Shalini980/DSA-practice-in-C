#include<stdio.h>
#include<stdio.h>
int findone(int m,int n,int arr[m][n])
{
    int row=0,col=n-1,lastrowwithone=-1;
    while(row<m &&col>=0)
    {
        if(arr[row][col]==1)
        {
            lastrowwithone=row;
            col--;
        }
        else
        row++;
    }
    if(lastrowwithone!=-1)
    {
        printf("ROW=%d\n",lastrowwithone+1);
    }
    else
    printf("no 1s found\n");
}
int main()
{
    int m,n;
    printf("enter the row and column \n");
    scanf("%d%d",&m,&n);
    int ptr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&ptr[i][j]);
        }
    }
    findone(m,n,ptr);
    return 0;
}