int stack[5];
int top=-1;
int N=5;
void push();
void pop();
void peek();
void display();
#include<stdio.h>
#include<stdlib.h>
void main()
{   
    int c,n=N;
    while(1){
    printf("\n***STACK OPERATIONS***\n");
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.PEEK\n");
    printf("4.DISPLAY\n");
    printf("5.EXIT\n");
    printf("Enter your choice\n");
    scanf("%d",&c);

    
    switch(c)
    {
        case 1:
               push();
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
        default :
                printf("Invalid option\n");
                break;
     } 
    }
}

void push()
{
    int x;
    printf("Enter the data to be inserted");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top=top+1;
        stack[top]=x;
    }
}

void pop()
{
    int item;
    if(top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        item=stack[top];
        top--;
        printf("The deleted element is %d \n",item);
    }
}

void peek()
{
    if(top==-1)
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The top element is %d \n",stack[top]);
    }
}

void display()
{
    int i;
    
        printf("the stack elements are : \n");
        for(i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
}