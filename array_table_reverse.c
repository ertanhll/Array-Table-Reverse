


#include <stdio.h>
#include <stdlib.h>

void fill_table(int table[10][10]){
   
    int i, j = 0;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            *(*(table+i)+j)=rand()%9+1;
        }
    }
    *(*(table+i-1)+j-1)=0;
}

void print_table(int table[10][10]){
   
    int i, j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d ",*(*(table+i)+j));
        }
        printf("\n");
    }
}

void reverse(int * array1, int position, int * array2, int len2){
    
    int *p, *q;
    q=array2+(len2-1);
    p=array1+position;
    
        while(len2>0){
            *p = *q;
            p++; q--; len2--;
    }
}

int find_and_replace_array(int * array1, int * array2, int len1, int len2){
    
    int exist=0;
    int position=0;
    int count=0;
    int *p, *q;
    p=array1;
    q=array2;
   
    while(p<array1+10){
     
        while(*p==*q && p<array1+10){
      
            p++;
            q++;
            count++;
            exist=1;
        }
        if(count!=len2 && exist==1){
            p--;
            q=q-count;
        }
        if(count==len2){
            reverse(array1, position, array2, len2);
            q=q-count;
            p--;
        }
        p++;
        if(exist==0){
            position++;
        } else {
            position+=count;
            exist=0;
            count=0;
        }
    }
        return 0;
}

void find_and_replace_table(int table[10][10], int * array, int len1, int len2){
    
  int i;
    for(i=0;i<10;i++){
        find_and_replace_array(*(table+i), array,  len1, len2);
    }
}

int main() {
    int len2=0;
    int *p;
    int table[10][10];
    int array[10]={1,9,7,9,1,3,8};
    p=array;
    
    printf("before\n");
    fill_table(table);
    print_table(table);
    printf("\n\nfind the below array in the table and reverse it\n");
   
    while(*p!='\0'){
        printf("%d ",*p);
        len2++;
        p++;
    }
    
    find_and_replace_table(table,array,10,len2);
    printf("\n\nafter\n");
    print_table(table);
   
    return 0;
}

