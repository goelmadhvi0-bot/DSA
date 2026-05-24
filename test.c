#include<stdio.h>
#include<stdlib.h>


struct array {
    int *a;
    int size;
    int length;
};

void display(struct array arr){

    printf("elements are\n");
    for(int i=0;i<arr.length;i++){
        printf("%d",arr.a[i]);
    }
    

}

int main () {
    
    int n,i;
    struct array arr ;

    printf("enter size of array");
    scanf("%d",&arr.size);

    arr.a=(int*)malloc(arr.size*sizeof(int));
    arr.length = 0;

    printf("enter number of elements");
    scanf("%d",&n);

    printf("enter all elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr.a[i]);
    }

    arr.length = n;

    display(arr);

    return 0;


}
