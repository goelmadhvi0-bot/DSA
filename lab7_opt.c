#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char custid[10];
    char name[50];
    int balance;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root,char custid[],char name[],int balance){
    if(root==NULL){
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        strcpy(newnode->custid,custid);
        strcpy(newnode->name,name);
        newnode->balance=balance;
        newnode->left=newnode->right=NULL;

        return newnode;
    }
    if(strcmp(root->custid,custid)>0)
    root->left=insert(root->left,custid,name,balance);

    else if(strcmp(root->custid,custid)<0)
    root->right=insert(root->right,custid,name,balance);

    return root;
}

struct node *create_bst(struct node *root){
    int n;

    printf("\nenter no. of customers.    ");
    scanf("%d",&n);

    char custid[10];
    char name[50];
    int balance;
    
    printf("----enter details----");
    for(int i=0;i<n;i++){
        printf("\ncustomer id : ");
        scanf("%s",custid);

        printf("\ncustomer name : ");
        scanf("%s",name);

        printf("\nbalance : ");
        scanf("%d",&balance);

        root=insert(root,custid,name,balance);
    }
    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
    inorder(root->left);
    printf("customer id : %s               customer name : %s                   balance : %d.    \n",root->custid,root->name,root->balance);
    inorder(root->right);
    }
}

struct node *search_id(struct node *root,char custid[]){
    if(root==NULL)
    return NULL;

    int cmp=strcmp(root->custid,custid);

    if(cmp==0)
    return root;
    else if(cmp>0)
    return search_id(root->left,custid);
    else
    return search_id(root->right,custid);
}

int count_id(struct node *root){
    int x,y;

    if(root == NULL)
    return 0;

    x=count_id(root->left);
    y=count_id(root->right);

    return x+y+1;
}

void display_lowBalance(struct node *root){
    if(root==NULL)
    return;

    if(root->balance<5000){
        display_lowBalance(root->right);
        printf("   %s   ",root->name);
        display_lowBalance(root->left);
    }
    else
    display_lowBalance(root->left);
}

int main(){
    struct node *root=NULL;
    root=create_bst(root);

    printf("---------CUSTOMERS----------\n");
    inorder(root);

    char id[20];
    printf("\nenter id to search\n");
    scanf("%s",id);

    struct node *a=search_id(root,id);
    if(a==NULL)
    printf("\n id not found \n");
    else
    printf("customer id : %s               customer name : %s                   balance : %d.    \n",a->custid,a->name,a->balance);

    printf("\n total id's are  %d. ",count_id(root));

    printf("\n customers with low balance \n");
    display_lowBalance(root);


}
