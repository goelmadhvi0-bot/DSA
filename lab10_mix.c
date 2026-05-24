#include<stdio.h>
#include<string.h>

/* You are tasked with implementing a command history feature for a basic text editor. The text editor
supports the following commands:
a) insert(text): Insert the given text at the current cursor position.
b) delete(num_chars): Delete the specified number of characters from the current cursor position.
c) undo(): Undo the last operation. If there is nothing to undo, print "Nothing to undo."
d) redo(): Redo the last undone operation. If there is nothing to redo, print "Nothing to redo."
e) getText(): Return the current text in the editor. */

/*struct operation{
    int data;
    char type;
};

struct stack{
    int top;
    struct operation arr[100];
};

void init_stack(struct stack *st){
    st->top=-1;
}

void push(struct stack *st, struct operation op){
    st->arr[++st->top]=op;
}

struct operation pop(struct stack *st){
    return st->arr[st->top--];
}

int isEmpty(struct stack *st){
    return st->top == -1;
}

char text[1000]="";

void insert(struct stack *undo,struct stack *redo, char *str){
    strcat(text,str);

    struct operation op;
    op.type='i';

    strcpy(op.data,str);
    push(undo,op);

    redo->top=-1;
}

void delete(struct stack *undo,struct stack *redo,int n){
    int len=strlen(text);
    if(n>len)
    n=len;

    char temp[100];

    strncpy(temp,text+len-n,n);
    temp[n]='\0';
    text[len-n]='\0';

    struct operation op;
    op.type='d';

    strcpy(op.data,temp);
    push(undo,op);

    redo->top=-1;
}

void undo(struct stack *undo,struct stack *redo){
    if(isEmpty(undo)){
    printf("nothng to undo\n");
    return;
    }

    struct operation op=pop(undo);

    if(op.type=='i'){
        int l=strlen(op.data);
        text[strlen(text)-l]='\0';
    }
    else{
        strcat(text,op.data);
    }
    push(redo,op);
}

void redo(struct stack *undo,struct stack *redo){
    if(isEmpty(redo)){
    printf("nothng to redo\n");
    return;
    }

    struct operation op=pop(undo);

    if(op.type=='i'){
         strcat(text,op.data);
    }
    else{
        int l=strlen(op.data);
        ext[strlen(ext)-l]='\0';
    }
    push(undo,op);
}

void getText() {
    printf("Text: %s\n", text);
}

int main (){
    struct stack undo,redo;

    init_stack(undo);
    init_stack(redo);

    insert(&undo,&redo,"hello");
    insert(&undo,&redo,"world");
    getText();

    delete(&undo, &redo, 5);
    getText();

    undo(&undo, &redo);
    getText();

    redo(&undo, &redo);
    getText();

    return 0;
}*/


/*Given a directed acyclic graph (DAG), write a C program to perform topological sorting (a
topological sorting is a linear ordering of its vertices such that for every directed edge from vertex
u to vertex v, u comes before v in the ordering.)*/

void topological_order(int arr[][10],int n){
    int indegree[10]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1)
            indegree[j]++;
        }
    }

    int visited[10]={0};
    int count=0;

    printf("----Topological Order----\n");

    while(count<n){
        for(int i=0;i<n;i++){
            if(indegree[i]==0 && visited[i]==0){
                printf(" %d ",i);
                visited[i]=1;
                count++;
            }
            for(int j=0;j<n;j++){
                if(arr[i][j]==1 )
                indegree[j]--;
            }
        }
    }
}

int main(){
    int n;

    printf("enter no.of vertices\n ");
    scanf("%d",&n);

    int adj[10][10];

    printf("enter adjacency matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }

    topological_order(adj,n);

    
}