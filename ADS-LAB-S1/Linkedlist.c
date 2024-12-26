#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL,*temp;
void insertbeg(int item){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
       newnode->next=head;
       head=newnode; 
    }
}
void insertend(int item){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insertpos(int item,int pos){
    int i=1;
    struct node *newnode,*current;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(i<pos){
            current=temp;
            temp=temp->next;
            i++;
        }
        newnode->next=temp;
        current->next=newnode;
    }
}
void deletebeg(){
    int i;
   if(head==NULL){
    printf("List Empty");
   }
   else if(head->next==NULL){
    temp=head;
    head=NULL;
    free(temp);
   }
   else{
    temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
   }}

void deleteend(){
    struct node *current;
    temp=head;
    if(head==NULL){
    printf("List Empty");
   }
   if(head->next==NULL){
    temp=head;
    head=NULL;
    free(temp);
   }
   else{
    temp=head;
    while(temp->next!=NULL){
        current=temp;
        temp=temp->next;
    }
    current->next=NULL;
    free(temp);
   }
}
void deletepos(int pos){
    struct node *current;
    int i=1;
    if(head==NULL){
    printf("List Empty");
   }
    else if(head->next==NULL){
    temp=head;
    head=NULL;
    free(temp);
   }
   else{
    temp=head;
    while (i<pos)
    {
      current=temp;
      temp=temp->next;
      i++;  
    }
    current->next=temp->next;
    free(temp);
   }
}
void display(){
    if(head==NULL){
    printf("List Empty");
   }
   else{
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
   }
}
void search(int s){
    int flag=0,i=0;
    if(head==NULL){
    printf("List Empty");
   }
   else{
    temp=head;
    while(temp!=NULL){
        if(temp->data==s){
            flag=1;
            printf("Element found at position %d\n",i+1);
        }
    temp=temp->next;
    i++;
    }
    if(flag==0){
        printf("Element not found");
    }
   }
}
void main(){
    int ch,c,x,p,pos,choice,position,s;
    while(1){
    printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Search\n5.Exit\nEnter your choice :");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1: 
            printf("\nEnter the data to be inserted :");
            scanf("%d",&x);
            printf("\nWhere you want to insert ? \n1.Insertion at beginning\n2.Insertion at any position\n3.Insertion at end  \n");
            scanf("%d",&c);
            if(c==1){
                insertbeg(x);
            }
            else if(c==2){
                printf("Enter the position to insert : ");
                scanf("%d",&p);
                insertpos(x,p);
            }
            else if(c==3){
                insertend(x);
            }
            else{
                printf("Invalid option");
            }
            break;
    case 2:
            printf("Where you want to delete ? \n1.Delete from beginning\n2.delete from any position,\n3.delete from end ");
            scanf("%d",&choice);
            if(choice==1){
                deletebeg();
            }
            else if(choice==2){
                printf("Enter the position to delete");
                scanf("%d",&position);
                deletepos(position);
            }
            else if(choice==3){
                deleteend();
            }
            else{
                printf("\nInvalid option");
            }
            break;
    case 3:
            display();
            break;
    case 4:
            printf("Enter the element you are searching for : ");
            scanf("%d",&s);
            search(s);
            break;
    case 5 :
            exit(0);
            break;
    default:
            printf("\nInvalid option");
            break;
    }
}}