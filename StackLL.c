#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* top = NULL;
void push(int x);
void pop();
void peek();
void display();

void main()
{   
    int c,item;
    while(1)
    {
        printf("\n***STACK OPERATIONS***");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.PEEK");
        printf("\n4.DISPLAY");
        printf("\n5.EXIT");
        printf("\nEnter your choice");
        scanf("%d",&c);
        switch(c)
        {
            case 1: 
                    printf("\nEnter the data to be inserted :");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2:
                    pop();
                    break;
            case 3:
                    peek();
                    break;
            case 4:
                    display();
                    break;
            case 5:
                    exit(1);
                    break;
            default:
                    printf("\nInvalid Option");
                    break;
        }
    }
}

void push(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void display()
{
    struct node *temp;
    temp = top;
    if(top==NULL)
    printf("\nStack is empty");
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

void peek()
{
    if(top==NULL)
    printf("\nstack is empty");
    else
    {
        printf("Top element is %d",top->data);
    }
}
void pop()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
        printf("\nstack is empty");
    else
    {
        printf("\nThe deleted element is %d",top->data);
        top=top->next;
        free(temp);
    }
}
