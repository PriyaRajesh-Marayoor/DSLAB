#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
void insert(int x){
    struct node *newnnode,*parent,*current;
    parent=root;
    newnnode=(struct node*)malloc(sizeof(struct node));
    newnnode->data=x;
    newnnode->left=NULL;
    newnnode->right=NULL;
    if(root==NULL)
        root=newnnode;
    else{
        current=root;
        while(current!=NULL){
            parent=current;
            if(newnnode->data>=current->data)
                current=current->right;
            else
                current=current->left;
        }
        if(newnnode->data>=parent->data){
            parent->right=newnnode;
        }
        else{
            parent->left=newnnode; 
        }
    }
}
struct node *findmin(struct node *root){
    while(root->data){
        root=root->left;
    }
    return root;
}
struct node *delete(struct node *root,int s){
    struct node *temp;
    if(root==NULL)
        return NULL;
    else if(s<root->data)
        root->left=delete(root->left,s);
    else if(s>root->data){
        root->right=delete(root->right,s);
    }
    //node to be deleted found
    else{
        //case 1 : no child
        if(root->left==NULL && root->right==NULL){
            temp=root;
            free(temp);
            return root;
        } 
        //one child case
        else if(root->left==NULL){
            temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL){
            temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        //two children case
        else{
            temp=findmin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
}
void preorder(struct node *root){
    if(root==NULL)
        return;
    else{
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(struct node *root){
    if(root==NULL)
        return;
    else{
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void display(){
    if(root==NULL)
        printf("Tree is empty");
    else{
        printf("\nPreorder :");
        preorder(root);
        printf("\nInorder : ");
        inorder(root);
        printf("\nPostorder :");
        postorder(root);
    }
}
void main(){
    int ch,item,x;
    struct node *del;
    while(1){
        printf("\n1.Insertion\n2.Deletion\n3.Displa\n4.Exit");
        printf("\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch){
            case 1 :
                    printf("Enter the data to be inserted : ");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2 :
                    printf("Enter the data to be deleted :");
                    scanf("%d",&item);
                    break;
            case 3 :
                    display();
                    break;
            case 4 :
                    exit(0);
                    break;
            default:
                    printf("Invalid choice");
        }
    }
}