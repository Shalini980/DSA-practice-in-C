#include<stdio.h>
int sumon(int i,int n, int sum)
{
    
    if(i>n)return sum;

    sum=sum+i;
    i++;
    sumon(i,n,sum);
}
int main()
{
    int n,i=0,sum=0;
    printf("enter the n");
    scanf("%d",&n);
    
    printf("the sum is %d",sumon(i,n,sum));
    return 0;


}