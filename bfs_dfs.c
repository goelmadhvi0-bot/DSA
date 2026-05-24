#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){

    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));

    if(t==NULL)
    printf("queue is full");
    else{
        t->data=x;
        t->next=NULL;

        if(front==NULL)
        front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){

    int x=-1;
    struct node *p;

    if(front==NULL)
    printf("queue is empty");
    else {
        p=front;
        front=front->next;
        x=p->data;
        free(p);
    }
    return x;
}

int isEmpty() {
    return front==NULL;
}

void bfs(int a[][6],int i){
    int visited[6]={0};

    printf(" %d ",i);
    visited[i]=1;
    enqueue(i);

    while(!isEmpty()){
        int u=dequeue();
        for(int v=0;v<6;v++){
            if(a[u][v]==1 && visited[v]==0){
                printf(" %d ",v);
                visited[v]=1;
                enqueue(v);
            }
        }
    }
}

void dfs(int a[][6],int i){
    static int visited[6]={0};

    if(visited[i]==0){
        printf(" %d ",i);
        visited[i]=1;
        for(int v=0;v<6;v++){
            if(a[i][v]==1 && visited[v]==0)
            dfs(a,v);
        }
    }
}

int main () {

    int a[6][6]={{0,1,1,0,0,0},{1,0,0,1,0,0},{1,0,0,1,0,0},{0,1,1,0,1,1},{0,0,0,1,0,0},{0,0,0,1,0,0}};

    bfs(a,0);
    printf("\n");
    dfs(a,0);

    return 0;
}