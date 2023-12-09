#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
    int *array;
    int used;
    int initial_size;
} DArray;


void printDArray(DArray *p);
void initDArray(DArray *p, int initial_size);
void insertDArray(DArray *p, int value);
void fillDArray(DArray *p, int size);
void removeElementDArray(DArray *p, int index);
void freeDArray(DArray *p);


int main(){
    int size = 5;
    DArray arr;
    printf("Attempting to Initializing Array with size 0...\n");
    initDArray(&arr, 0);
    printf("Filling Dynamic Array with values from 1 to %d\n", size);
    fillDArray(&arr, size);
    printDArray(&arr);
    printf("Removing numbers and checking if size is getting smaller accordingly...\n");
    for(int i=0;i<size;i++)
    {
        removeElementDArray(&arr, 0);
        printDArray(&arr);
    }
    printf("Freeing up the Dynamic Array...\n");
    freeDArray(&arr);
    printf("%p\n",arr.array);
    return 0;
}


void initDArray(DArray *p, int initial_size){
    if(initial_size<=0){
        printf("Initial size is <=0, initializing array with 2 elements...\n");
        initial_size = 2;
    }
    p->array = (int*) malloc(initial_size * sizeof(int));
    if(p->array==NULL){
        printf("The Array has not been initialized successfully... (malloc error)\n");
        return;
    }
    p->used = 0;
    p->initial_size = 2;
}


void insertDArray(DArray *p, int value){
    if(p->array==NULL){
        printf("The Dynamic Array has not been initialized yet!\n");
        return;
    }

    if(p->used == p->initial_size){
        p->array = realloc(p->array, p->initial_size*2*sizeof(int));
        if(p->array==NULL){
            printf("The Array could not be resized successfully... (realloc error)\n");
            return;
        }
        p->initial_size *= 2;
    }
    p->array[p->used] = value;
    p->used++;
}


void printDArray(DArray *p){
    if(p->array==NULL){
        printf("The Dynamic Array has not been initialized yet!\n");
        return;
    }
    else if(p->used==0){
        printf("There are no elements in the initialized array!\n");
        return;
    }

    printf("Size = %d\n", p->initial_size);
    printf("Used = %d\n", p->used);

    int i=0;
    for(;i<p->used-1;i++){
       printf("%d ", p->array[i]); 
    }
    printf("%d\n", p->array[i]);
}


void fillDArray(DArray *p, int size){
    for(int i=0;i<size;i++){
        insertDArray(p, i+1);
    }
}


void removeElementDArray(DArray *p, int index){
    if(p->array==NULL){
        printf("The Dynamic Array has not been initialized yet!\n");
    }
    else if(p->used==0){
        printf("There are no elements in the initialized array!\n");
        return;
    }

    for(int i=index;i<p->used-1;i++){
        p->array[i] = p->array[i+1];
    }
    p->used--;

    if(p->used <= p->initial_size/2 && (((3/4.0)* p->initial_size) >= 2)){
        p->initial_size = ((3/4.0)* p->initial_size);
        printf("Resizing down the array to avoid wasting memory... New size = %d\n", p->initial_size);
        int *temp = (int*) malloc(p->initial_size * sizeof(int));
        for(int i=0;i<p->used;i++){
            temp[i] = p->array[i];
        }
        free(p->array);
        p->array=temp;
    }
}


void freeDArray(DArray *p){
    if(p->array==NULL){
        printf("Array has not been initialized yet!\n");
        return;
    }

    free(p->array);
    p->array=NULL;
    p->used=0;
    p->initial_size=0;
}
