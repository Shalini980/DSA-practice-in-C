#include<stdio.h>
#include<string.h>
char *rev(char str[],int n)
{
static char new[100];
int j=0;
for(int i=n;i>=0;i--)
{
    new[j++]=str[i];

}
return new;
}
int main()
{
    char str[100];
    printf("enter the string\n");
    scanf("%s",str);
    int n=strlen(str);
    printf("the length of the string is %d\n",n);
    char *s2=rev(str,n);
    printf("the reversed string is %s\n",s2);
    return 0;

}