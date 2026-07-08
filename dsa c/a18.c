#include<stdio.h>
//stack overflow
void f()
{
    printf("1");
    f();
}
int main()
{
    f();
    return 0;
}