#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
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
struct node *push(struct node *top,int data)
{
    struct node *temp=create(data);
    temp->next=top;
    top=temp;
    return top;
}
struct node *pop(struct node *top)
{
    if(top==NULL)
    {
       printf("Linked list is empty\n");
    }
    struct node*ptr=top;
    int val=ptr->data;
    top=ptr->next;
    free(ptr);
    ptr=NULL;
    printf("%d is popped from stack\n",val);
    return top;
}

void print(struct node *top)
{
        struct node *ptr=top;
        printf("the stack elements are\n");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
int isempty(struct node *top)
{
    if (top==NULL)
    return 1;
    else 
    return 0;
}
int peek(struct node *top)
{
    if(top==NULL)
    {
        printf("no node\n");
        exit(1);
    }
    return top->data;
}


int main()
{
    struct node *top=NULL;
    int choice ,data;
    printf("\n1.PUSH\n2.POP\n3.PRINT\n4.EXIT\n");
    while(1)
    {
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the element you want to push\n");
            scanf("%d",&data);
            top=push(top,data);
            break;
            case 2:
            top=pop(top);
            break;
            case 3:
            print(top);
            break;
            case 4:
            exit(1);
            default :
            printf("entered wrong choice\n");
        }
      
    }
      return 0;



}