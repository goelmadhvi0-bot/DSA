#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char name[50];
    long long int phone;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root,long long int phone,char name[]){
    if(root==NULL){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        strcpy(newnode->name,name);
        newnode->phone=phone;
        newnode->left=newnode->right=NULL;

        return newnode;
    }
    if(strcmp(root->name,name)>0)
    root->left=insert(root->left,phone,name);

    else if(strcmp(root->name,name)<0)
    root->right=insert(root->right,phone,name);

    return root;
}

struct node *create_bst(struct node *root,int size){
    char name[50];
    long long int phone;
    printf("enter details \n");
    for(int i=0;i<size;i++){
        printf("name:  %d",i+1);
        scanf("%s",name);
        printf("\nphone no.:  %d",i+1);
        scanf("%lld",&phone);

        root=insert(root,phone,name);
    }
    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
inorder(root->left);
printf(" %s -> %lld\n",root->name,root->phone);
inorder(root->right);
    }
}

struct node *search(struct node *root,char name[]){

    if(root==NULL)
    return NULL;

    int cmp=strcmp(name,root->name);

    if(cmp==0)
    return root;
    else if(cmp<0)
    return search(root->left,name);
    else
    return search(root->right,name);

}

int main(){

    struct node *root=NULL;
    root=create_bst(root,7);

    inorder(root);

    char name[50];

    printf("\nenter name to search ");
    scanf("%s",name);

    struct node *a=search(root,name);
    if(a==NULL)
    printf("name not found");
    else
    printf(" phone no. of %s person is %lld",name,a->phone);

    

    

    return 0;
}