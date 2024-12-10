#include<stdio.h>
#include<conio.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*temp,*newnode,*tail=NULL;
void insertbeg(int x){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(tail==NULL){
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
    }
}
void insertend(int x){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(tail==NULL){
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}
void insertpos(int x,int pos){
    int i=0,c=0;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    temp=tail;
    while(temp->next!=tail){
        temp=temp->next;
        c++;
    }
    if(tail==NULL){
        tail=newnode;
        tail->next=newnode;
    }
    else if(pos==1){
        insertbeg(x);
    }
    else if(pos<0 ||pos>c){
        printf("Invalid position");
    }
    else{
        temp=tail->next;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void deletebeg(){
    if(tail==NULL){
        printf("list empty");
    }
    else if(tail->next=tail){
        tail=NULL;
        free(tail);
    }
    else{
        temp=tail->next;
        tail->next=temp->next;
        free(temp);
    }
}
void deleteend(){
    if(tail==NULL){
        printf("list empty");
    }
    else if(tail->next=tail){
        tail=NULL;
        free(tail);
    }
    else{
        temp=tail->next;
        while(temp!=tail){
            temp=temp->next;
        }
        temp->next=tail->next;
        tail=temp;
        free(temp);
    }
}
void 
