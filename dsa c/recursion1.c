#include<stdio.h>
//codintion to stop the loop is called the base condition
int count =0;
int  f()
{
    if(count ==4)return 0;
    printf("%d\n",count);
    count++;
    f();
}
int main()
{
    f();
    return 0;
}