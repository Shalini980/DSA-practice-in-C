#include<stdio.h>
#include<stdlib.h>
int distance(int arr[],int n,int a,int b)
{
    int posa=-1,posb=-1,maxdist=__INT_MAX__;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==a)
        {
            posa=i;
        }
        if(arr[i]==b)
        {
            posb=i;
        }
        if(posa!=-1 && posb!=-1 )
        {
            int dist=(posa>posb)?posa-posb:posb-posa;
            if(dist<maxdist)
            {
                maxdist=dist;
            }
        }
    }
    return maxdist;
}
int main()
{
    int n;
    printf("enter the number of elements in your array\n");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("enter the data\n");
        scanf("%d",&ptr[i]);
    }
    int a,b;
    printf("enter the numbers you want to find the distance between\n");
    scanf("%d %d",&a,&b);
    printf("the distance between two points is %d",distance(ptr,n,a,b));
    return 0;
}
