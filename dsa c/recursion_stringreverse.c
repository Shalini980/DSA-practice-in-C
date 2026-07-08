#include<stdio.h>
#include<string.h>
void reverse (char *str)
{
    if(*str)
    {
        reverse(str+1);
        printf("%c",*str);
    }

}
int main()
{
    char str[]="shalini is a goood girl";
    
    reverse(str);
    return 0;
}