#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*top=NULL;
int isempty()
{
    if(top==NULL)
    return 1;
    else
    return 0;
}
struct node *create(int data)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node ));
    if(nn==NULL)
    {
        printf("stack overflow\n");
        exit(1);
    }
    nn->data=data;
    nn->next=NULL;
    return nn;
}
struct node *push(int data)
{
    struct node *nn=create(data);
    nn->next=top;
    top=nn;
    return top;
}
int pop()
{
    if(top==NULL)
    {
        printf("no node\n");
        exit(1);
    }
    struct node *ptr=top;
    int val=ptr->data;
    top=ptr->next;
    free(ptr);
    ptr=NULL;
    return val;
}
void pallindrome(char *s)
{
    int i=0;
    while(s[i]!='x')
    {
        top=push(s[i]);
        i++;
    }
    i++;
    while(s[i]!='\0')
    {
        if(isempty()||s[i]!=pop())
        {
            printf("not a pallindrome\n");
            exit(1);
        }
        i++;
    }
    printf("pallindrome\n");
}
int main()
{
    char s[100];
    printf("please enter the string\n");
    scanf("%s",s);
    pallindrome(s);
    return 0;

}