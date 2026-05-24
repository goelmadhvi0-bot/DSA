#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct stack {
    int size;
    int top;
    struct node **s;
};

void stackcreate(struct stack *st,int size ){

    st->size=size;
    st->top=-1;
    st->s=(struct node **)malloc(st->size*sizeof(struct node *));
}

void push(struct stack *st,struct node *x){

    if(st->top==st->size-1)
    printf("stack overflow");
    else{
        st->top++;
        st->s[st->top]=x;
    }
}

struct node *pop(struct stack *st){

    struct node *x=NULL;
    if(st->top==-1)
    printf("stack underflow");
    else{
        x=st->s[st->top--];
    }
    return x;
}

int isempty(struct stack st){
    if(st.top==-1)
    return 1;
    return 0;
}

int isfull(struct stack st){
    if(st.top==st.size-1)
    return 1;
    return 0;
}

struct queue {
    int size;
    int front;
    int rear;
    struct node **q;
};

void queuecreate(struct queue *q,int size){

    q->size=size;
    q->front=q->rear=0;
    q->q=(struct node **)malloc(q->size*sizeof(struct node *));
}

void enqueue(struct queue *q,struct node *x){

    if(q->rear==q->size-1)
    printf("queue is full");
    else{
        q->rear++;
        q->q[q->rear]=x;
    }
}

struct node *dequeue(struct queue *q){

    struct node *x=NULL;

    if(q->front==q->rear)
    printf("queue is empty");
    else{
        q->front++;
        x=q->q[q->front];
    }
    return x;
}

int isEmpty(struct queue q) {
    return q.front==q.rear;
}

struct node *root=NULL;

void Treecreate() {

    struct node *p,*t;
    int x;
    struct queue q;
    queuecreate(&q,100);

    printf("enter root value");
    scanf("%d",&x);
    root=(struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){

        p=dequeue(&q);

        printf("enter value of left child of %d. ",p->data);
        scanf("%d",&x);

        if(x!=-1){
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }

        printf("enter value of right child of %d. ",p->data);
        scanf("%d",&x);

        if(x!=-1){
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct node *p){

    if(p){
        printf(" %d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct node *p){

    if(p){
        
        inorder(p->lchild);
        printf(" %d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct node *p){

    if(p){
        
        postorder(p->lchild);
        postorder(p->rchild);
        printf(" %d ",p->data);
    }
}

void Ipreorder(struct node *p){

    struct stack st;
    stackcreate(&st,100);

    while(p || !isempty(st)){
        if(p){
            printf(" %d ",p->data);
            push(&st,p);
            p=p->lchild;
        }
        else{
            p=pop(&st);
            p=p->rchild;
        }
    }
}

void Iinorder(struct node *p){

    struct stack st;
    stackcreate(&st,100);

    while(p || !isempty(st)){
        if(p){
            push(&st,p);
            p=p->lchild;
        }
        else{
            p=pop(&st);
            printf(" %d ",p->data);
            p=p->rchild;
        }
    }
}

/*void Ipostorder(struct node *p){

    struct stack st;
    stackcreate(&st,100);
    long int temp;

    while(p || !isempty(st)){
        if(p){
            push(&st,p);
            p=p->lchild;
        }
        else{
           temp=pop(&st);
           if(temp>0){
            push(&st,-temp);
            p=((struct node *)temp)->rchild;
           }
           else{
            printf(" %d ",((struct node *)temp)->data);
            p=NULL;
           }
        }
    }
}*/

void levelorder(struct node *p){

    struct queue q;
    queuecreate(&q,100);

    printf(" %d ",p->data);
    enqueue(&q,p);

    while( !isEmpty(q) ){

        p=dequeue(&q);
        if(p->lchild){
            printf(" %d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild){
            printf(" %d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}

int searchInorder(int inorder[],int start,int end,int key){

    for(int i=start;i<=end;i++){
        if(inorder[i]==key)
        return i;
    }
    return -1;
}

struct node *generatefromtraversal(int inorder[],int preorder[],int instart,int inend){

    static int preindex=0;

    if(instart>inend)
    return NULL;

    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data=preorder[preindex++];
    node->lchild=node->rchild=NULL;

    if(instart==inend)
    return node;

    int splitindex= searchInorder(inorder,instart,inend,node->data);

    node->lchild=generatefromtraversal( inorder, preorder, instart,splitindex-1);
    node->rchild=generatefromtraversal( inorder, preorder, splitindex+1,inend);

    return node;

}


int main () {

   /* Treecreate();

    printf("\nPreorder\n");
    preorder(root);
    Ipreorder(root);

    printf("\nInorder\n");
    inorder(root);
    Iinorder(root);

    printf("\nPostorder\n");
    postorder(root);

    printf("\nLevelorder\n");
    levelorder(root);
    */

    int pre_order[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int in_order[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    int n=sizeof(in_order)/sizeof(in_order[0]);

    struct node *t=generatefromtraversal( in_order, pre_order, 0,n-1);

    inorder(t);

    return 0;
}