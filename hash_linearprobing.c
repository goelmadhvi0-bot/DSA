#include<stdio.h>

int hash(int key){
    return key%10;
}

int probe(int h[],int key){
    int index=hash(key);
    int i=0;
    
    while(h[index+i%10] != 0)
    i++;

    return (index+i)%10;
}

void insert(int h[],int key){
    int index=hash(key);
    if(h[index]!=0)
    index=probe(h,key);
    h[index]=key;
}

int search(int h[],int key){
     int index=hash(key);
    int i=0;
    
    while(h[index+i%10] != key)
    i++;

    return (index+i)%10;
}

int main() {

    int ht[10];

    insert(ht,25);
    insert(ht,35);
    insert(ht,24);
    insert(ht,37);

    printf("\nkey found at %d\n",search(ht,35));

    return 0;
}