#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *q;
};

void enqueue(struct queue *q,int x){

    if(q->rear==q->size-1)
    printf("queue is full");
    else{
        q->rear++;
        q->q[q->rear]=x;
    }
}

int dequeue(struct queue *q){

    int x=-1;

    if(q->front==q->rear)
    printf("queue is empty");
    else{
        q->front++;
        x=q->q[q->front];
    }
    return x;
}

void display(struct queue q){

    for(int i=q.front+1;i<=q.rear;i++){
        printf("%d ",q.q[i]);
    }
    printf("\n");
}

void create_cqueue(struct queue *q,int size){

    q->size=size;
    q->front=q->rear=0;
    q->q=(int *)malloc(q->size*sizeof(int));
}

void cenqueue(struct queue *q,int x){

    if((q->rear+1)%q->size==q->front)
    printf("queue is full");
    else {
        q->rear=(q->rear+1)%q->size;
        q->q[q->rear]=x;
    }
}

int cdequeue(struct queue *q){

    int x=-1;

    if(q->front==q->rear)
    printf("queue is empty");
    else{
        q->front=(q->front+1)%q->size;
        x=q->q[q->front];
    }
    return x;
}

void cdisplay(struct queue q){

    int i=q.front+1;

    do{
        printf("%d ",q.q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}

int main () {

    struct queue q;

    /*printf("enter size of queue");
    scanf("%d",&q.size);
    q.q=(int*)malloc(q.size*sizeof(int));

    q.front=q.rear=-1;

     enqueue(&q,4);
     enqueue(&q,7);
     enqueue(&q,1);

     display(q);*/

     create_cqueue(&q,8);
     cenqueue(&q,4);
     cenqueue(&q,5);
     cenqueue(&q,8);
     cenqueue(&q,2);

     cdisplay(q);





    return 0;
}