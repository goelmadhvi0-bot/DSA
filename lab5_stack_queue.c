#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *s;
};

void create_stack(struct stack *st){
    printf("enter stack size\n");
    scanf("%d",&st->size);

    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}

void display_stack(struct stack *st){
    for(int i=st->top;i>=0;i--){
        printf(" %d ",st->s[i]);
    }
}

void push(struct stack *st,int ele){
    if(st->top==st->size-1){
    printf("stack is full\n");
    return ;
    }

    (st->top)++;
    st->s[st->top]=ele;
}

int pop(struct stack *st){
    if(st->top==-1){
    printf("stack is empty");
    return -1;
    }

    int x=-1;
    x=st->s[st->top];
    (st->top)--;

    return x;
}

int peek(struct stack *st,int pos){
    int x=-1;
    if(st->top-pos+1 < 0)
    printf("invalid index");
    
    x=st->s[st->top-pos+1];

    return x;
}

int isEmpty(struct stack *st){
    if(st->top == -1)
    return 1;

    return 0;
}

int isFull(struct stack *st){
    if(st->top==st->size-1)
    return 1;

    return 0;
}

int isMatching(char ch1,char ch2){
    if(ch1=='(' && ch2==')')
    return 1;
    if(ch1=='[' && ch2==']')
    return 1;
    if(ch1=='{' && ch2=='}')
    return 1;

    return 0;
}

int isBracketBalanced(char *exp){

    struct stack *st=(struct stack *)malloc(sizeof(struct stack));
    create_stack(st);
    char ch;

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{' ){
            
            push(st,exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(st))
            return 0;

             ch=pop(st);

            if(!isMatching(ch,exp[i]))
            return 0;
        }
    }
    return isEmpty(st);
}

int main (){
    char test[]={"{([])}"};
    
    if(isBracketBalanced(test))
    printf(" Balanced");
    else
    printf(" Not Balanced");

    return 0;
}