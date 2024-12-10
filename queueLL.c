#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL,*temp;
void enqueue(int x)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void display(){
    if(front==NULL && rear==NULL){
        printf("The Queue is empty");
    }
    else{
        temp=front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void dequeue(){
    temp=front;
    if(front==NULL && rear==NULL){
        printf("The Queue is empty");
    }
    else{
        printf("The deleted element is %d ",front->data);
        front=front->next;
        free(temp);
    }
}
void peek(){
   if(front==NULL && rear==NULL){
        printf("The Queue is empty");
    }
    else{
        printf("The front element is %d ",front->data);
    } 
}
void search(){
    int i=1,flag=0,s;
    printf("Enter the element you are searching for : ");
    scanf("%d",&s);
    temp=front;
    while(temp!=NULL){
        if(s==temp->data){
            flag=1;
            printf("Element found at %d position ",i);
        }
        i++;
        temp=temp->next;
    }
    if(flag==0){
        printf("Element not found ");
    }
}
void main(){
    int ch,item;
    printf("***QUEUE OPERATIONS***");
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Search\n6.Exit\nEnter your choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    printf("\nEnter the element to be inserted : ");
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
                    search();
                    break;
            case 6:
                    exit(0);
                    break;
            default:
                    printf("Invalid option");
                    break;
        }
    }
}