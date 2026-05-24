#include<stdio.h>
#include<stdlib.h>


struct node {
    
    int data ;
    struct node *next;

}*first=NULL,*second=NULL,*third=NULL;

void create(int a[],int n){
   
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t; 
    }
}

void create2(int a[],int n){
   
    struct node *t,*last;
    second=(struct node *)malloc(sizeof(struct node));
    second->data=a[0];
    second->next=NULL;
    last=second;

    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t; 
    }
}

void display(struct node *p){

    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int count(struct node *p){

    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

int sum(struct node *p){

    int sum=0;
    while(p!=0){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int max_element(struct node *p){

    int max=first->data;
    while(p!=0){
        if(p->data >= max)
        max = p->data;
        
        p=p->next;
    }
    return max;
}

struct node* search(struct node *p,int key){

    while(p!=0){
        if(key==p->data)
        return p;
        
        p=p->next;
    }
    return 0;
}

void insert(struct node *p,int pos,int x){

    struct node *t;

    if(pos<0 || pos>count(p))
    return;

    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;

    if(pos==0){
     t->next=first;
     first=t;
    }
    else if(pos>0){
        p=first;
        for(int i=0;i<pos-1 && p;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void sortedinsert(struct node *p,int x){

    struct node *t,*q=NULL;

    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
    first=t;
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

int checksort(struct node *p){

    int x=first->data;
    while(p!=NULL){
        if(p->data<x)
        return 0 ;
        x=p->data;
        p=p->next;
    }
    return 1;
} 

void remove_duplicate(struct node *p){  // sorted list 

    struct node *q;
    q=p->next;

    while(q!=0){
        if(p->data==q->data){
            p->next=q->next;
            free(q);
            q=p->next;
        }
        else{
            p=q;
            q=q->next;
        }
    }
}

void reverse(struct node *p){          // reversing links 

    struct node *q=NULL,*r=NULL;

    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void concat(struct node *p,struct node *q){

    third=p;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}

void merge(struct node *p,struct node *q){           // sorted list 

    struct node *last;

    if(p->data < q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }

    while(p!=0 && q!=0){
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
    last->next=NULL;
    if(q)
    last->next=NULL;
}

int isloop(struct node *f){

    struct node *p,*q;
    p=q=f;

    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;             // if q is null keep it null nahi to aage bdo 
    }while(p && q && p!=q);

    if(p==q)
    return 1;
    else
    return 0;
}

int main () {
    
    struct node *temp;

    int a[]={1,3,5,12,17};

    create(a,5);
    printf("list is ");
    display(first);
    printf("\nlength of list is %d\n",count(first));
    printf("sum of elements is %d\n",sum(first));
    printf("maximum element is %d\n",max_element(first));

    temp = search(first,9);
    if(temp)
    printf("key is found %d\n",temp->data);
    else
    printf("key not found\n");

    printf("insert\n");
    insert(first,3,7);
    display(first);

    printf("\n\n");

    printf("sorted insert\n");
    sortedinsert(first,2);
    display(first);

    printf("\n\n");

    printf("deleted element is %d\n",delete(first,4));
    display(first);

    printf("\ncheck sort -----  %d\n",checksort(first));

    printf("list after removing duplicte\n");
    remove_duplicate(first);
    display(first);

    printf("\n\n");

    printf("reversed list\n");
    reverse(first);
    display(first);

    printf("\n\n");

    int b[]={4,9,11,13,16};
    create2(b,5);

    printf("concated list\n");
    concat(first,second);
    display(third);

    printf("\n\n");

    printf("merged list\n");
    merge(first,second);
    display(third);
    
    printf("\n\n");

    struct node *t1,*t2;                      // creating loop
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;

    printf("check for loop ----- %d\n",isloop(first));


    return 0;

}