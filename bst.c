#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *insert(struct node *root,int value){

    if(root==NULL){
        root=(struct node *)malloc(sizeof(struct node));
        root->data=value;
        root->lchild=root->rchild=NULL;
    }

    if(value<root->data)
    root->lchild=insert(root->lchild,value);

    else if(value>root->data)
    root->rchild=insert(root->rchild,value);

    return root;
    
}

struct node *search(struct node *root,int key){

    if(root==NULL || key==root->data)
    return root;

    if(key<root->data)
    return search(root->lchild,key);

    else if(key>root->data)
    return search(root->rchild,key);
}

int height(struct node *root){

    int x,y;
    if(root==NULL)
    return 0;

    x=height(root->lchild);
    y=height(root->rchild);

    return x>y?x+1:y+1;
}

struct node *inPre(struct node *p){
    while(p && p->rchild)
    p=p->rchild;

    return p;
}

struct node *inSucc(struct node *p){
    while(p && p->lchild)
    p=p->lchild;

    return p;
}

struct node *delete(struct node *root,int value){

    struct node *p;

    if(root==NULL)
    return NULL;

    if(root->lchild==NULL && root->rchild==NULL){
        root=NULL;
        free(root);
        return NULL;
    }

    if(value < root->data)
    root->lchild=delete(root->lchild,value);
    
    else if(value > root->data)
    root->rchild=delete(root->rchild,value);

    else{
        if(height(root->lchild) > height(root->rchild)){
            p=inPre(root->lchild);
            root->data=p->data;
            root->lchild=delete(root->lchild,p->data);
        }
        else{
            p=inSucc(root->rchild);
            root->data=p->data;
            root->rchild=delete(root->rchild,p->data);
        }
    }
    return root;
}

void inorder(struct node *p){

    if(p){
        
        inorder(p->lchild);
        printf(" %d ",p->data);
        inorder(p->rchild);
    }
}

int main () {

    struct node *root=NULL;
    int value;
    int key[]={7,1,8,9,5,2,3};

    for(int i=0;i<7;i++){
        root=insert(root,key[i]);
    }

    printf("\nInorder\n");
    inorder(root);

    printf("\n Search Element \n");
    scanf("%d",&value);

    if(search(root,value)->data==value)
    printf("\n element found \n");
    else if(search(root,value)->data!=value)
    printf("\n element not found \n");

    //root=delete(root,8);
   // printf("\n Inorder after deletion\n");
    //inorder(root);

    return 0;
}