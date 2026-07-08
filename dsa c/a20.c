#include<stdio.h>

int print(int i,int n)
{
    if(i>n)return 0;
    printf("shalini\n");
    i++;
    print(i,n);
}
int main()
{
    int i=0,n;
    printf("enter the no. of times you want to display the name");
    scanf("%d",&n);
    print(i,n);
    return 0;

}