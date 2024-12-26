
int queue[5];
int front=-1;
int rear =-1;
int N=5;
void enqueue(int item);
void dequeue();
void peek();
void display();
#include<stdio.h>
#include<stdlib.h>
void main()
{   
    int c,item;
    while(1){
    printf("\n***QUEUE OPERATIONS***");
    printf("\n1.ENQUEUE");
    printf("\n2.DEQUEUE");
    printf("\n3.PEEK");
    printf("\n4.DISPLAY");
    printf("\n5.EXIT");
    printf("\nEnter your choice\n");
    scanf("%d",&c);

    
    switch(c)
    {
        case 1:
               printf("\nEnter data to be inserted :");
               scanf("%d",&item);
               enqueue(item);
               break;
        case 2:
                dequeue();
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

void enqueue(int item)
{
    if(rear==N-1)
    {
        printf("Queue overflow");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=item;
    }
    else
    {
        rear++;
        queue[rear]=item;
    }
}

void dequeue()
{
    if(front==-1 && rear ==-1)
    {
        printf("\nQueue is empty");
    }
    else if(front==rear)
    {
        printf("\nthe deleted element from the queue is : %d",queue[front]);
        front=rear=-1;
    }
    else
    {   
        printf("\nthe deleted element from the queue is : %d",queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("\n%d",queue[i]);
        }
    }
}

void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("%d",queue[front]);
    }
}
