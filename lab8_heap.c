#include<stdio.h>

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void maxheapify(int arr[],int size,int i){
    int largest=i;
    int left=(2*i + 1);
    int right=(2*i +2);

    if(left<size && arr[left]>arr[largest])
        largest=left;
    if(right<size && arr[right]>arr[largest])
        largest=right;
    if(largest!=i){
    swap(&arr[largest],&arr[i]); 
    maxheapify(arr,size,largest);
    }
}

void minheapify(int arr[],int size,int i){
    int smallest=i;
    int left=(2*i + 1);
    int right=(2*i +2);

    if(left<size && arr[left]<arr[smallest])
        smallest=left;
    if(right<size && arr[right]<arr[smallest])
        smallest=right;
    if(smallest!=i){
    swap(&arr[smallest],&arr[i]); 
    maxheapify(arr,size,smallest);
    }
}

void create_maxheap(int arr[],int size){
    for(int i=(size-1)/2;i>=0;i--){
        maxheapify(arr,size,i);
    }
    
}

void display_heap(int arr[],int size){
    for(int i=0;i<size;i++){
        printf(" %d ",arr[i]);
    }
}

void insert(int arr[],int size,int ele){
    arr[size]=ele;
    size++;
    for(int i=(size-1)/2;i>=0;i--){
        maxheapify(arr,size,i);
    }
}

int delete(int arr[],int size){
    int x=arr[0];
    arr[0]=arr[size-1];
    maxheapify(arr,size-1,0);

    return x;
}

void heapsort_ascend(int arr[],int size){
    for(int i=(size-1)/2;i>=0;i--){
        maxheapify(arr,size,i);
    }

    for(int i=size-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        maxheapify(arr,i,0);
    }
}

int k_largest(int arr[],int k,int size){
    if(k>size)
    printf("invalid position");

    create_maxheap(arr,size);

    heapsort_ascend(arr,size);
    return arr[size-k];
}

int isMaxheap(int arr[],int size){
    for(int i=0;i<=(size-1)/2;i++){
        int max=i;
        int left=(2*i + 1);
        int right=(2*i + 2);

        if(arr[left]>arr[max] && arr[right]>arr[max] && left<size && right<size)
        return 0;
    }
    return 1;
}

int main () {

    int arr[100];
    int n;
    printf("enter no. of elements in tree");
    scanf("%d",&n);

    printf("\nenter tree elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    /*create_maxheap(arr,n);
    printf("\n-----heap-----\n");
    display_heap(arr,n);

    printf("\nenter element to insert");
    int x;
    scanf("%d",&x);

    printf("\nheap after insertion\n");
    insert(arr,n,x);
    n++;
    display_heap(arr,n);

    printf("\nmax element\n");
    int y=delete(arr,n);
    printf(" %d ",y);
    n--;
    printf("\nheap after deletion\n");
    display_heap(arr,n);

    printf("\nheap sort ascending\n");
    heapsort_ascend(arr,n);
    display_heap(arr,n);

    int k,ele;
    printf("enter k for kth largest element");
    scanf("%d",&k);
    ele=k_largest(arr,k,n);
    printf("\nele = %d ",ele);*/

    int max=isMaxheap(arr,n);
    if(max==1)
    printf("\nis a max heap");
    else
    printf(" \nnot a max heap");




    return 0;
}