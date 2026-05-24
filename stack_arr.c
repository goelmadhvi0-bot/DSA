#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *s;
};

void create(struct stack *st){

    printf("enter stack size");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}

void display(struct stack *st){

    for(int i=st->top;i>=0;i--){
        printf("%d ",st->s[i]);
    }
}

void push(struct stack *st,int x){

    if(st->top==st->size-1)
    printf("stack overflow");
    else{
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct stack *st){

    int x=-1;
    if(st->top==-1)
    printf("stack underflow");
    else{
        x=st->s[st->top--];
    }
    return x;
}

int peek(struct stack st,int pos){

    int x=-1;
    if(st.top-pos+1 < 0)
    printf("invalid index");
    x=st.s[st.top-pos+1];

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

int stacktop(struct stack st){
    if(!isempty(st))
    return st.s[st.top];
    return -1;
}

int main () {

    struct stack st;
    create(&st);

    push(&st,5);
    push(&st,7);
    push(&st,2);
    push(&st,9);

    printf("\n");
    display(&st);
    printf("\n");

    printf("%d \n",pop(&st));
    display(&st);

    return 0;
}