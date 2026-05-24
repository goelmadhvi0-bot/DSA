#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *insert(struct node *root ,int key){
    if(root==NULL){
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=key;
        newnode->left=newnode->right=NULL;
        return newnode;
    }
    if(root->data > key)
    root->left=insert(root->left,key);
    else if(root->data < key)
    root->right=insert(root->right,key);

    return root;
}

struct node *create_bst(int arr[],int size,struct node *root){
    for(int i=0;i<size;i++){
        root=insert(root,arr[i]);
    }
    return root;
}

void preorder(struct node *root){
    if(root!=NULL){
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
}
}

void inorder(struct node *root){
    if(root!=NULL){
inorder(root->left);
printf(" %d ",root->data);
inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
postorder(root->left);
postorder(root->right);
printf(" %d ",root->data);
    }
}

struct node *search_node(struct node *root,int key){
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

struct node *max(struct node *root){
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}

struct node *min(struct node *root){
    while(root->left != NULL){
        root=root->left;
    }
    return root;
}


int main(){

    int arr[]={6,4,2,5,1,3,8,7,9,10};
    struct node *root=NULL;
    root=create_bst(arr,10,root);

    printf("\n----inorder----\n");
    inorder(root);

    printf("\n----preorder----\n");
    preorder(root);

    printf("\n----postorder----\n");
    postorder(root);



    return 0;
}