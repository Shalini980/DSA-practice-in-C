#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *prev;
    struct node *curr;
};
//creating a node 
struct node *create(int data)
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->prev=nn;
    nn->curr=nn;
    return nn;

}
//printing
void print(struct node *tail)
{
    if(tail==NULL)
    {
        printf("NO NODE IN LIST\n");
       
    }
    else
    {
    struct node *ptr=tail->curr;
    do
    {
       printf("%d ",ptr->data);
       ptr=ptr->curr;
    } while (ptr!=tail->curr);
    }

}
// adding at begining
struct node *addatbeg(struct node *tail,int data)
{
    if(tail==NULL)
    {
        return tail;
    }
    else
    {
    struct node *nn=create(data);
    struct node *temp=tail->curr;
    nn->curr=temp;
    temp->prev=nn;
    nn->prev=tail;
    tail->curr=nn;
    }
    return tail;
}
// insert at end
struct node *insertatend(struct node *tail,int data)
{
    if(tail==NULL)
    return tail;
    else
    {
    struct node *nn=create(data);
    struct node *ptr=tail->curr;
    nn->curr=tail->curr;
    nn->prev=tail;
    ptr->prev=nn;
    tail->curr=nn;
    tail=nn;
    }
    return tail;

}
//insert between nodes 
struct node *insertatcertain(struct node *tail,int data,int pos)
{
   
        struct node *nn=create(data);
         if(tail==NULL)
    {
        return nn;
    }
        struct node *ptr=tail->curr;
        while(pos>1)
        {
            ptr=ptr->curr;
            pos--;
        }
        nn->prev=ptr;
        nn->curr=ptr->curr;
        ptr->curr->prev=nn;
        ptr->curr=nn;
        if(ptr==tail)
        {
            tail=tail->curr;
        }    
    return tail;
}
//deleting the front node
struct node *delfront(struct node *tail)
{
    if(tail==NULL)
    return tail;
    struct node *temp=tail->curr;
    tail->curr=temp->curr;
    temp->curr->prev=tail;
    free(temp);
    temp=NULL;
    return tail;
}
//deleting last
struct node *dellast(struct node *tail)
{
    if(tail== NULL)
    return tail;
    struct node *temp=tail->curr;
    tail->prev->curr=tail->curr;
    temp->prev=tail->prev;
    temp=tail->prev;
    free(tail);
    tail=temp;
    return tail;
}
//deleting at certain
struct node *delcertain(struct node *tail,int pos)
{
    if(tail==NULL)
    return tail;
    struct node *previous=tail->curr;
    struct node *current=tail->curr;
    while(pos>1)
    {
        previous=current;
        current=current->curr;
        pos--;
    }
    previous->curr=current->curr;
    current->curr->prev=previous;
    if(current==tail)
    {
        tail=previous;
    }
    free(current);
    current=NULL;
    return tail;

}
int main()
{
    struct node *tail;
    printf("the list after creating is \n");
    tail=create(1);
    print(tail);
     printf("\nthe list after adding at beg is \n");
    tail=addatbeg(tail,2);
    print(tail);
    printf("\nthe list after adding at end is \n");
    tail=insertatend(tail,3);
    print(tail);
    printf("\nthe list after adding at certain is \n");
    tail=insertatcertain(tail,5,2);
    print(tail);
     printf("\nthe list after deleting at front is \n");
    tail=delfront(tail);
    print(tail);
    printf("\nthe list after deleting at last is \n");
    tail=dellast(tail);
    print(tail);
     printf("\nthe list after adding at certain is \n");
    tail=insertatcertain(tail,5,2);
    print(tail);
    printf("\nthe list after deleting at certain is \n");
    tail=delcertain(tail,2);
    print(tail);
    return 0;
}
