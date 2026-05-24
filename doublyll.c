#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

void create(int a[],int n){
    
    struct node *t,*last;

    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void display(struct node *p){

    while(p != NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int length(struct node *p){

    int l=0;
    
    while(p){
        l++;
        p=p->next;
    }
    return l;
}

void insert(struct node *p,int pos, int x){

    struct node *t;

    if(pos<0 || pos>length(p))
    return;

    if(pos==0){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)
        p->next->prev=t;
        p->next=t;
    }
}

int delete(struct node *p,int pos){

    struct node *q;
    int x=-1;

    if(pos<0 || pos>length(p))
    return -1;

    if(pos==1){
        first=first->next;
        if(first){
            first->prev=NULL;
        }
        x=p->data;
        free(p);
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
    return x;
}

void reverse(struct node *p){

    struct node *temp;

    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next == NULL){
            first=p;
        }
    }
}

int main() {
    
    int a[]={5,8,15,17,21};
    create(a,5);

    display(first);

    printf("\nlist after insertion\n");
    insert(first,4,1);
    display(first);

    printf("\nlist after deletion\n");
    delete(first,3);
    display(first);

    printf("\nreversed list\n");
    reverse(first);
    display(first);




    return 0;
}