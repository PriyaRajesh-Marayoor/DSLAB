#define N 3
int queue[N];
int front=-1;
int rear=-1;
#include<stdio.h>
#include<stdlib.h>
void enqueue(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front){
        printf("Queue is full ,cannot insert %d ",x);
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue empty");
    }
    else if(front==rear){
        printf("The deleted element is %d ",queue[front]);
        front=rear=-1;
    }
    else{
        printf("The deleted element is %d ",queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("Queue empty");
    }
    else{
        printf("The queue is : \n");
       do{
            printf("%d ",queue[i]);
            i=(i+1) % N;
        } while(i!=(rear+1)%N);
    }
}
void peek(){
    if(front==-1 && rear==-1){
        printf("Queue empty");
    }
    else{
    printf("The peek element is : %d",queue[front]);
}}
void main(){
    int c,item;
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1 :
                printf("\nEnter the data to be inserted : ");
                scanf("%d",&item);
                enqueue(item);
                break;
        case 2 :
                dequeue();
                break;
        case 3 : 
                peek();
                break;
        case 4 :
                display();
                break;
        case 5 :
                exit(0);
                break;
        default:
                printf("Invalid choice ");
                break;
        }

    }
}

