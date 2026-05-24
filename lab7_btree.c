#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *newnode(int key){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = key;
    n->left = n->right = NULL;
    return n;
}

/* Create a binary tree from array using level-order (complete tree) */
struct node *create_btree(int arr[], int size){
    if(size == 0) return NULL;
    struct node **nodes = (struct node**)malloc(size * sizeof(struct node*));
    for(int i=0;i<size;i++){
        nodes[i] = newnode(arr[i]);
    }
    for(int i=0;i<size;i++){
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l < size) nodes[i]->left = nodes[l];
        if(r < size) nodes[i]->right = nodes[r];
    }
    struct node *root = nodes[0];
    free(nodes);
    return root;
}

/* Insert into binary tree at first available position (level-order) */
void insert_level_order(struct node *root, int key){
    if(root == NULL) return; /* no container here, creation via array recommended */
    struct node **q = (struct node**)malloc(1000 * sizeof(struct node*));
    int front=0, rear=0;
    q[rear++] = root;
    while(front < rear){
        struct node *temp = q[front++];
        if(temp->left == NULL){
            temp->left = newnode(key);
            break;
        } else {
            q[rear++] = temp->left;
        }
        if(temp->right == NULL){
            temp->right = newnode(key);
            break;
        } else {
            q[rear++] = temp->right;
        }
    }
    free(q);
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

/* collect all node values into array (preorder) */
void collect_nodes(struct node *root, int arr[], int *i){
    if(root==NULL) return;
    arr[(*i)++] = root->data;
    collect_nodes(root->left, arr, i);
    collect_nodes(root->right, arr, i);
}

int compare_desc(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

void k_largest(struct node *root,int k){
    int n = count(root);
    if(n==0 || k<=0 || k>n) return;
    int *arr = (int*)malloc(n * sizeof(int));
    int idx=0;
    collect_nodes(root, arr, &idx);
    qsort(arr, n, sizeof(int), compare_desc);
    printf(" %d ", arr[k-1]);
    free(arr);
}

int median(struct node *root){
    int n = count(root);
    if(n==0) return 0;
    int *arr = (int*)malloc(n * sizeof(int));
    int idx=0;
    collect_nodes(root, arr, &idx);
    qsort(arr, n, sizeof(int), compare_desc); /* sort descending */
    /* make it ascending for median calculation */
    for(int i=0;i<n/2;i++){
        int t = arr[i]; arr[i] = arr[n-1-i]; arr[n-1-i] = t;
    }
    int med;
    if(n % 2 == 1)
        med = arr[n/2];
    else
        med = (arr[n/2 - 1] + arr[n/2]) / 2;
    free(arr);
    return med;
}

void display_greater(struct node *root,int ele){
    if(root==NULL)
        return;
    display_greater(root->left, ele);
    if(root->data > ele) printf(" %d ", root->data);
    display_greater(root->right, ele);
}

int printAncestorsHelper(struct node *root, int key){
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (printAncestorsHelper(root->left, key) || printAncestorsHelper(root->right, key)){
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

void printAncestors(struct node *root, int key){
    if(!printAncestorsHelper(root, key))
        printf("(no ancestors found)");
}

int main(){

    int arr[] = {50,30,70,20,40,60};
    struct node *root = create_btree(arr, 6);

    printf("\nbinary tree before insertion\n");
    inorder(root);

    insert_level_order(root, 80);
    insert_level_order(root, 15);
    insert_level_order(root, 25);
    insert_level_order(root, 58);

    printf("\n binary tree after insertion\n");
    inorder(root);

    /* example calls (commented out in original); keep them available if needed */
    /* printf("\n height of tree is %d ",height(root));
    printf("\n total nodes of tree is %d ",count(root));
    printf("\n total leaf nodes of tree is %d ",leaf_count(root));
    printf("\n total prime leaf nodes of tree is %d ",count_prime_atleaf(root));
    printf("\n sum of leaf nodes  of tree is %d ",sum_leaf(root));

    int k;
    printf("\nenter k for kth largest ele\n");
    scanf("%d",&k);
    k_largest(root,k);

    printf("\n median of tree is %d ",median(root));

    int x;
    printf("enter any no. ");
    scanf("%d",&x);

    printf("\n ---elements greater than %d---\n",x);
    display_greater(root,x); */

    printf("\nenter any element to know its ancestor\n");
    int y;
    scanf("%d",&y);

    printf("ancestors of %d are ",y);
    printAncestors(root,y);

    return 0;
}
