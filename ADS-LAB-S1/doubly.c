#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev,*next;
};
struct node *temp,*current,*newnode,*head,*tail;
void insertbeg(int x){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
    }
}
void insertend(int x){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=NULL;
        tail=newnode;
    }
}
void insertpos(int x){
    int i=1,po;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Enter the position to insert :");
    scanf("%d",&po);
    if(po==1){
        head=tail=newnode;
    }
    else{
    temp=head;
    while(i<po-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;

}}
void deletebeg(){
    if(head==NULL){
        printf("List empty");
    }
    else if(head==tail && head!=NULL){
        head=tail=NULL;
    }
    else{
        temp=head;
        head->next->prev=NULL;
        head=head->next;
        free(temp);
    }
}
void deleteend(){
     if(head==NULL){
        printf("List empty");
    }
    else if(head==tail && head!=NULL){
        head=tail=NULL;
    }
    else{
        temp=tail;
        tail->prev->next=NULL;
        tail=tail->prev;
        temp->prev=NULL;
        free(temp);
        
    }
}
void deletepos(){
    int i=1,p; 
    printf("Enter the position to delete : ");
    scanf("%d",&p);
    if(head==NULL){
        printf("List empty");
    }
    else if(p==1){
        deletebeg();
    }
    else{
        temp=head;
        while(i<p){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void search(int s){
    int i=0,flag=0;
    if(head==NULL){
        printf("List empty");
    }
    else{
        temp=head;
        while(temp!=NULL){
            if(temp->data==s){
                printf("Element found at position %d ",i+1);
                flag=1;
            }
            temp=temp->next;
            i++;
        }
        if(flag==0){
            printf("Element not found");
        }
    }
}
void display(){
    if(head==NULL){
        printf("List empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void main(){
    int ch,c,choice,item,key;
    printf("Doubly Linked List Operations");
    while(1){
        printf("\n1.insertion\n2.Deletion\n3.Search\n4.Display\n5.Exit\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Where you want to insert ? : ");
                    printf("\n1.Beginning\n2.Any position\n3.End\n");
                    scanf("%d",&c);
                    printf("\nEnter the data to be inserted : ");
                    scanf("%d",&item);
                    if(c==1){
                        insertbeg(item);
                    }
                    else if(c==2){
                        insertpos(item);
                    }
                    else if(c==3){
                        insertend(item);
                    }
                    else{
                        printf("\nInvalid Option");
                    }
                    break;
            case 2:
                    printf("Where you want to delete ? : ");
                    printf("\n1.Beginning\n2.Any position\n3.End\n");
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
                        printf("\nInvalid Option");
                    }
                    break;
            case 3:
                    printf("\nEnter the element you are searching for : ");
                    scanf("%d",&key);
                    search(key);
                    break;
            case 4:
                    display();
                    break;
            case 5:
                    exit(0);
                    break;
            default:
                    printf("\nInvalid option");
                    break;
        }

        
    }
}