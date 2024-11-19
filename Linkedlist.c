#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node *head=NULL,*newnode,*tail,*temp,*current;
int pos=0;
void insertion();
void deletion();
void display();

void insertbeg(int x);
void insertpos(int x);
void insertend(int x);
void deletebeg();
void deletepos();
void deleteend();
void insertion(){
    int x,choice;
    printf("Enter the data to be inserted :");
    scanf("%d",&x);
    printf("\nwhere you want to insert %d",x);
    printf("\n1.insertion at beginning\n2.insertion at any position\ninsertion at end");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    if(choice==1){
        insertbeg(x);
    }
    else if(choice==2){
        insertpos(x);
    }
    else if(choice==3){
        insertend(x);
    }
    else{
        printf("\nInvalid choice");
    }
}
void insertbeg(int x){
newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL){
    head=tail=newnode;
    pos++;
    }
    else{
        newnode->next=head;
        head=newnode;
        pos++;
    }
}
void insertpos(int x){
    int p,i=0;
    printf("\nEnter the position you want to insert :");
    scanf("%d",&p);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL){
    head=tail=newnode;
    pos++;
    }
    else{
        temp=head;
        while(i!=p){
            temp=temp->next;
            p++;
        }
        current=temp;
        temp=temp->next;
        newnode->next=temp;
        current->next=newnode;
        pos++;
    }
}
void insertend(int x){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL){
    head=tail=newnode;
    pos++;
    }
    else{
        tail->next=newnode;
        tail=newnode;
        pos++;
    }
}
void deletion(){
    int choice;
    printf("\nwhere you want to delete ");
    printf("\n1.deletion at beginning\n2.deletion at any position\n3.deletion at end");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    if(choice==1){
        deletebeg();
    }
    else if(choice==2){
        deletepos();
    }
    else if(choice==3){
        deleteend();
    }
    else{
        printf("\nInvalid choice");
    }
}
void deletebeg(){
    if(pos==0){
        printf("List empty");
    }
    else{
        temp=head;
        head=head->next;
        printf("The deleted element is %d",temp->data);
        free(temp);
        pos--;
    }
}
void deletepos(){
    int p,i=1;
    printf("\nEnter the position to delete :");
    scanf("%d",&p);
    if(pos==0){
        printf("List empty");
    }
    else{
        while(i!=p){
            temp=temp->next;
            i++;
        }
        current=temp;
        temp=temp->next;
        current->next=temp->next;
        printf("The deleted element is %d",temp->data);
        free(temp);
        pos--;
    }
}
void deleteend(){
    int i=0;
    if(pos==0){
        printf("List empty");
    }
    else{
        while(i!=pos-1){
            temp=temp->next;
            i++;
        }
        current=temp;
        temp=temp->next;
        current->next=NULL;
        printf("The deleted element is %d",temp->data);
        free(temp);
        pos--;
    }
}

void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void main(){   
    int c,item;
    while(1){
        printf("\n***LINKED LIST OPERATIONS***");
        printf("\n1.INSERTION\n2.DELETION\n3.DISPLAY\n4.SEARCH\n5.EXIT");
        printf("\nEnter your choice");
        scanf("%d",&c);
        switch(c){
            case 1: 
                    insertion(item);
                    break;
            case 2:
                    deletion();
                    break;
            case 3:
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

