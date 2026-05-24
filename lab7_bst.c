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

void inorder(struct node *root){
    if(root!=NULL){
inorder(root->left);
printf(" %d ",root->data);
inorder(root->right);
    }
}

int height(struct node *root){
    int x,y;

    if(root==NULL)
    return 0;

    x=height(root->left);
    y=height(root->right);

    return x>y?x+1:y+1;
}

int count(struct node *root){
    int x,y;

    if(root==NULL)
    return 0;

    x=count(root->left);
    y=count(root->right);

    return x+y+1;
}

int leaf_count(struct node *root){
    int x,y;

    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL)
    return 1;
    else{
        x=leaf_count(root->left);
        y=leaf_count(root->right);
    }
    return x+y;
    
}

int isPrime(int n) {
    if (n <= 1)
        return 0;

    for ( int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int count_prime_atleaf(struct node *root){
    int x,y;

    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL){
        if(isPrime(root->data)){
            printf(" %d ",root->data);
            return 1;
        }
        return 0;
    }
    else{
        x=count_prime_atleaf(root->left);
        y=count_prime_atleaf(root->right);
    }
    return x+y;
}

int sum_leaf(struct node *root){
    

    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL)
    return root->data;
    
    return sum_leaf(root->left)+sum_leaf(root->right);
}

int ct=0;
void k_largest(struct node *root,int k){
    if(root==NULL)
    return ;

    k_largest(root->right,k);
    ct++;
    if(ct==k){
        printf(" %d ",root->data);
        return;
    }

    k_largest(root->left,k);
}

void store_inorder(struct node *root,int arr[],int *i){
    if(root != NULL){
        store_inorder(root->left,arr,i);
        arr[*i]=root->data;
        (*i)++;
        store_inorder(root->right,arr,i);
    }
}

int median(struct node *root,int size){
    int arr[50];
    int i=0;

    store_inorder(root, arr, &i);

    if (size % 2 == 1)
        return arr[size / 2];   
    else
        return (arr[(size/2 - 1 + size/2)/2]) ;  
}

void display_greater(struct node *root,int ele){
    if(root==NULL)
    return;

    if(root->data > ele){
        display_greater(root->left,ele);
        printf(" %d ",root->data);
        display_greater(root->right,ele);
    }
    else
        display_greater(root->right,ele);
}

void printAncestors(struct node *root, int key) {
    if (root == NULL)
        return ;

    if (key < root->data) {
        printf("%d ", root->data);
        printAncestors(root->left, key);
    }
    else if (key > root->data) {
        printf("%d ", root->data);
        printAncestors(root->right, key);
    }
}

int main(){

    int arr[]={50,30,70,20,40,60};
    struct node *root=NULL;
    root=create_bst(arr,6,root);

    printf("\nbst before insertion\n");
    inorder(root);

    insert(root,80);
    insert(root,15);
    insert(root,25);
    insert(root,58);

    printf("\n bst after insertion\n");
    inorder(root);


   /* printf("\n height of tree is %d ",height(root));
    printf("\n total nodes of tree is %d ",count(root));
    printf("\n total leaf nodes of tree is %d ",leaf_count(root));
    printf("\n total prime leaf nodes of tree is %d ",count_prime_atleaf(root));
    printf("\n sum of leaf nodes  of tree is %d ",sum_leaf(root));

    int k;
    printf("\nenter k for kth largest ele\n");
    scanf("%d",&k);

    k_largest(root,k);

    printf("\n median of tree is %d ",median(root,10));

    int x;
    printf("enter any no. ");
    scanf("%d",&x);

    printf("\n ---elements greater than %d---\n",x);
    display_greater(root,x);*/

    printf("\nenter any element to know its ancestor\n");
    int y;
    scanf("%d",&y);

    printf("ancestors of %d are ",y);
    printAncestors(root,y);






    return 0;
}