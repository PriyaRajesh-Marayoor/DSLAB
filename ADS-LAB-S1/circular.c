#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *temp,*newnode,*tail=NULL,*current;
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
void insertpos(int x){
    int i=0,c=1,pos;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    printf("Enter the position to insert :");
    scanf("%d",&pos);
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
    temp=tail->next;
    if(temp->next==temp){
        tail=NULL;
        free(temp);
    }
    else if(tail==NULL){
        printf("list empty");
    }
    else{
        tail->next=temp->next;
        free(temp);
    }
}
void deleteend(){
    temp=tail->next;
    if(tail==NULL){
        printf("List empty");
    } 
    else if(temp->next==temp){
        tail=NULL;
        free(temp);
    }
    else{
        while(temp->next!=tail->next){
            current=temp;
            temp=temp->next;
        }
        current->next=temp->next;
        tail=current;
        free(temp);
    }
}
void deletepos(){
    int p,i=1,c=1;
    printf("Enter the position to delete : ");
    scanf("%d",&p);
    temp=tail->next;
    while(temp!=tail){
        temp=temp->next;
        c++;
    }
    if(tail==NULL){
        printf("List empty");
    } 
    else if(p<1 || p>c){
        printf("Invalid position");
    }
    else if(p==1){
        deletebeg();
    }
    else if(p==c){
        deleteend();
    }
    else{
        temp=tail->next;
        while(i<p){
            current=temp;
            temp=temp->next;
            i++;
        }
        current->next=temp->next;
        free(temp);
    }
}
void search(){
    int s,flag=0,c=1;
    printf("Enter the element you are searching for :");
        scanf("%d",&s);
    if(tail==NULL){
        printf("List empty ");
    }
    else{
        temp=tail->next;
        if(temp->next==temp){
            if(s==temp->data){
                printf("Element found at position 1 ");
                flag=1;
            }
        }
        else{
            do{
                if(s==temp->data)
                {
                    printf("Element found at position %d",c);
                    flag=1;
                }
                temp=temp->next;
                c++;
            }while(temp!=tail->next);}
        if(flag==0){
            printf("Element not found !");
        }
}}
void display(){
    if(tail==NULL){
        printf("List empty");
    }
    else{
        temp=tail->next;
        while(temp!=tail){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
void main(){
    int choice,ch,item;
    printf("CIRCULAR LINKED LIST OPERATIONS ");
    while(1){
        printf("\n1.Insertion\n2.deletion\n3.search\n4.display\n5.Exit\nEnter ypur choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                    printf("\nEnter the data to be inserted :");
                    scanf("%d",&item);
                    printf("\nWhere to insert?\n1.Insert at beginning\n2.insert at end\n3.Insert at any position\nEnter your choice : ");
                    scanf("%d",&ch);
                    if(ch==1){
                        insertbeg(item);
                    }
                    else if(ch==2){
                        insertend(item);
                    }
                    else if(ch==3){
                        insertpos(item);
                    }
                    else{
                        printf("Invalid option");
                    }
                    break;
            case 2 :
                    printf("\nWhere to delete ?\n1.Delete at beginning\n2.Delete at end\n3.Delete at any position\nEnter your choice :");
                    scanf("%d",&ch);
                    if(ch==1){
                        deletebeg();
                    }
                    else if(ch==2){
                        deleteend();
                    }
                    else if(ch==3){
                        deletepos();
                    }
                    else{
                        printf("Invalid choice!");
                    }
                    break;
            case 3:
                    search();
                    break;
            case 4:
                    display();
                    break;
            case 5:
                    exit(0);
                    break;
            default:
                    printf("Invalid choice ");
                    break;
        }
    }
}
