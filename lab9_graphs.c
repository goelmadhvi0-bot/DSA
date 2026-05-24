#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node *next;
};

struct node *create_newnode(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->vertex=value;
    newnode->next=NULL;

    return newnode;
}

void addEdge(int **arr,int u,int v,struct node **list){
    // matrix 
    arr[u][v]=1;
    arr[v][u]=1;

    // list 
    //u->v
    struct node *p=create_newnode(v);
    p->next=list[u];
    list[u]=p;

    //v->u
    p=create_newnode(u);
    p->next=list[v];
    list[v]=p;
}

void print_matrix(int **arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
}

void print_list(struct node **list,int n){
    for(int i=0;i<n;i++){
        printf(" %c -> ",i+'a');
        struct node *temp=list[i];
        while(temp!=NULL){
            printf(" %c ",temp->vertex+'a');
            temp=temp->next;
        }
        printf("\n");
    }
}

void dfs(int **arr,int visited[],int v,int n){
    visited[v]=1;
    printf(" %c ",v+'a');

    for(int i=0;i<n;i++){
        if(arr[v][i]==1 && visited[i]==0){
            dfs(arr,visited,i,n);
        }
    }
}

void bfs(int **arr,int n){
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    
    int queue[n],front=0,rear=0;

    visited[0]=1;
    queue[rear++]=0;

    int x;

    while(front<rear){
        x=queue[front++];
        printf(" %c ",x+'a');

        for(int i=0;i<n;i++){
            if(arr[x][i]==1 && visited[i]==0){
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
}

void find_degree(int **arr,int n){
    for(int i=0;i<n;i++){
        int degree=0;
        for(int j=0;j<n;j++){
            if(arr[i][j])
            degree++;
        }
        printf(" %c : %d \n",i+'a',degree);
    }
}

int main (){
    int n,edge;

    printf("enter no. of vertices\n");
    scanf("%d",&n);

    int **adjMatrix=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        adjMatrix[i]=(int *)calloc(n,sizeof(int));
    }

    struct node **adjList=(struct node **)malloc(n*sizeof(struct node *));
    for(int i=0;i<n;i++){
        adjList[i]=NULL;
    }

    int *visited=(int*)calloc(n,sizeof(int));

    printf("enter no. of edges \n");
    scanf("%d",&edge);

    int u,v;


    printf("enter edges\n");
    for(int i=0;i<edge;i++){
        
        scanf("%d %d",&u,&v);
        addEdge(adjMatrix,u,v,adjList);
    }

    printf("-------Adjacency Matrix-------\n");
    print_matrix(adjMatrix,n);
    printf("--------Adjacency List---------\n");
    print_list(adjList,n);

    printf("DFS traversal \n");
    dfs(adjMatrix,visited,0,n);

    printf("\ndegree of each vertex\n ");
    find_degree(adjMatrix,n);

    printf("BFS traversal \n");
    bfs(adjMatrix,n);

    return 0;

}







