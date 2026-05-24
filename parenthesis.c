#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char data;
    struct node *next;
}*top=NULL;

void push(char x){

    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));

    if(t==0)
    printf("stack is full");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

char pop() {
    struct node *t;
    char x=-1;

    if(top==0)
    printf("stack is empty");
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

int isBalanced(char *exp){
    
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(')
        push(exp[i]);
        else if(exp[i]==')'){
            if(top==NULL)
            return 0;
            pop();
        }
    }
    if(top==NULL)
    return 1;
    else
    return 0;
}

int precedence(char x){

    if(x=='+' || x=='-' )
    return 1;
    else if(x=='*' || x=='/')
    return 2; 

    return 0;
}

int isOperand(char x ){

    if(x=='+' || x=='-' || x=='*' || x=='/' )
    return 0;
    else
    return 1;
}

char *InToPost(char *infix){

    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(precedence(infix[i]>precedence(top->data)))
            push(infix[i++]);
            else
            postfix[j++]=pop();
        }
    }
    while(top!=NULL){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main () {

    //char a,b,c,d;
    //char *exp="((a+b)*(c-d))";

   // printf("%d ",isBalanced(exp));

    char *infix="a+b*c";
    push('#');

    char *postfix=InToPost(infix);
    printf("%s ",postfix);



    return 0;
}