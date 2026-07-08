#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *create(int data)
{
    struct node  *nn=(struct node *)malloc(sizeof(struct node ));
    nn->data=data;
    nn->next=nn;
    return nn;
}
struct node *insertatbeg(struct node *tail,int data)
{
    struct node *nn=create(data);
    nn->next=tail->next;
    tail->next=nn;
    return tail;
}
struct node *insertatend(struct node *tail,int data)
{

    struct node *nn=create(data);
    nn->next=tail->next;
    tail->next=nn;
    tail=nn;
    return tail;
}
struct node *insertatpos(struct node *tail,int data,int pos)
{
    if(pos==1)
    {
        tail=insertatbeg(tail,data);
        return tail;
    }
    struct node *nn=create(data);
    struct node *ptr=tail->next;
    while(pos-1>1)
    {
        ptr=ptr->next;
        pos--;
    }
    nn->next=ptr->next;
    ptr->next=nn;
    if(ptr==tail)
    {
        tail=tail->next;
    }
    return tail;
}
struct node *deleteatbeg(struct node *tail)
{
    if(tail==NULL)
    {
        return tail;
    }
    struct node *ptr=tail->next;
    tail->next=ptr->next;
    free(ptr);
    ptr=NULL;
    return tail;
}
struct node *deleteatend(struct node *tail)
{
    if(tail==NULL)
    {
        return tail;
    }
    struct node *ptr=tail->next;
    while(ptr->next!=tail)
    {
        ptr=ptr->next;
    }
    ptr->next=tail->next;
    free(tail);
    tail=ptr;
    return tail;
}
struct node *deleteatpos(struct node *tail,int pos)
{
    if(tail==NULL)
    {
        return tail;
    }
    if(pos==1)
    {
        tail=deleteatbeg(tail);
        return tail;
    }
    struct node *ptr=tail->next;
    struct node *pre=NULL;
    int i=1;
    while(i<pos)
    {
        pre=ptr;
        ptr=ptr->next;
        i++;
    }
    pre->next=ptr->next;
    if(ptr=tail)
    {
        pre=tail;
    }
    free(ptr);
    ptr=NULL;
    return tail;
}
int count(struct node *tail)
{
    int count=0;
    struct node *ptr=tail->next;
    do
    {
        count++;
        ptr=ptr->next;
    } while (ptr!=tail->next);
    return count;
}
int search(struct node *tail,int element)
{
    int index=0;
    struct node *temp=tail->next;
    do
    {
        if(temp->data=element)
        {
            return index;
        }   
        temp=temp->next;
        index++;
    } while (temp!=tail->next);
    return -1;
}
void print(struct node *tail)
{
    if(tail==NULL)
    {
        printf("empty list\n");
        exit(1);
    }
    struct node *ptr=tail->next;
    do
    {
       printf("%d ",ptr->data);
       ptr=ptr->next;
    } while (ptr!=tail->next);
    printf("\n");
    
}
int main()
{
    struct node *tail=NULL;
    printf("creating a node\n");
    tail=create(10);
    print(tail);
    printf("inserting at beg\n");
    tail=insertatbeg(tail,20);
    print(tail);
     printf("inserting at end\n");
    tail=insertatend(tail,50);
    print(tail);
    printf("inserting at pos\n");
    tail=insertatpos(tail,60,3);
    print(tail);
    printf("deleting at beg\n");
    tail=deleteatbeg(tail);
    print(tail);
    printf("deleting at end\n");
    tail=deleteatend(tail);
    print(tail);
    printf("inserting at beg\n");
    tail=insertatbeg(tail,20);
    print(tail);
    printf("deleting at pos\n");
    tail=deleteatpos(tail,3);
    print(tail);
    printf("inserting at beg\n");
    tail=insertatbeg(tail,59);
    print(tail);
    printf("THE value is %d ",count(tail));


    return 0;
}