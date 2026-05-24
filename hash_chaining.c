#include<stdio.h>
#include<stdlib.h>

struct node {
    
    int data ;
    struct node *next;

};

void sortedinsert(struct node **h,int x){

    struct node *t,*q=NULL,*p=*h;

    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;

    if(*h==NULL)
    *h=t;
    else {
        while (p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

struct node* search(struct node *p,int key){

    while(p!=0){
        if(key==p->data)
        return p;
        
        p=p->next;
    }
    return 0;
}

int delete(struct node *p,int pos){

    struct node *q;
    int x=-1;

    if(pos<1 || pos>count(p))
    return -1;
    
    if(pos==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }

    else{
        for(int i=0;i<pos-1 && p;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int hash(int key){
    return key%10;
}

void insert(struct node *h[],int key){
    int index=hash(key);
    sortedinsert(&h[index],key);
}

int main () {

    struct node *ht[10];

    for(int i=0;i<10;i++)
        ht[i]=NULL;

        insert(ht,22);
        insert(ht,52);
        insert(ht,26);
        insert(ht,29);




    return 0;
}