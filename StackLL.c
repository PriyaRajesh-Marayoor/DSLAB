#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top = NULL;
void display();
void push(int x);
void pop();
void peek();
void search();
void push(int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
void display(){
    struct node *temp;
    temp = top;
    if(top==NULL)
    printf("\nStack is empty");
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void peek(){
    if(top==NULL)
    printf("\nstack is empty");
    else{
        printf("Top element is %d",top->data);
    }
}
void pop(){
    struct node *temp;
    temp=top;
    if(top==NULL)
        printf("\nstack is empty");
    else{
        printf("\nThe deleted element is %d",top->data);
        top=top->next;
        free(temp);
    }
}
void search(){
    int s,p=0,flag=0;
    printf("Enter the element you are searching for:");
    scanf("%d",&s);
    struct node *temp = top;
    while(temp!=NULL){
        if(temp->data==s){
            printf("element found at position %d",p+1);
            flag=1;
        }
        temp=temp->next;
        p++;
    }
    if(flag==0){
        printf("element not found");
    }
}
void main(){   
    int c,item;
    while(1){
        printf("\n***STACK OPERATIONS***");
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.SEARCH\n6.EXIT");
        printf("\nEnter your choice");
        scanf("%d",&c);
        switch(c){
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
                    search();
                    break;
            case 6:
                    exit(1);
                    break;
            default:
                    printf("\nInvalid Option");
                    break;
        }
    }
}

