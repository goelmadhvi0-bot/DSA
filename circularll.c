#include<stdio.h>
#include<stdlib.h>

struct node {

    int data;
    struct node *next;

}*head;

void create(int a[],int n){

    struct node *t,*last;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=head;
    last=head;

    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct node *h){

    do{
        printf("%d ",h->data);
        h=h->next;
    }while(h!=head);
}

int length(struct node *p){

    int l=0;
    do{
        l++;
        p=p->next;
    }while(p!=head);

    return l;
}

void insert(struct node *p,int pos,int x){

    struct node *t;

    if(pos<0 || pos>length(p))
    return;

    if(pos==0){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        if(head==NULL){
            head=t;
            head->next=head;
        }
        else{
            while(p->next != head){
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}

int delete(struct node *p,int pos){

    struct node *q;
    int x;

    if(pos<0 || pos>length(p))
    return -1;

    if(pos==1){
        while(p->next != head){
            p=p->next;
        }
        x=head->data;
        if(head==p){
            free(head);
            head=NULL;
        }
        else{
         p->next=head->next;
         free(head);
         head=p->next;
        }
    }
    else{
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main(){

    int a[]={3,6,8,9,11,16};
    create(a,6);

    display(head);
    
    printf("\nlist after insertion\n");
    insert(head,3,0);
    display(head);

    printf("\nlist after deletion \n");
    delete(head,4);
    display(head);



    return 0;
}