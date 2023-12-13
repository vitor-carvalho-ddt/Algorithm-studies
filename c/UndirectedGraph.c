#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct no{
    char node_name;
    struct no *prox;
} No;


typedef struct{
    No **array;
    int used;
    int initial_size;
} DArray;


void initLinkedList(No **p, char *node_name);
void printLinkedList(No *p);
void insertEndLinkedList(No *p, char *node_name);
void removeElementLinkedList(No *p, char *node_name);
void freeLinkedList(No **p);
void printMatrixGraph(int size, int matrix_graph[][size]);
void printDArray(DArray *p);
void initDArray(DArray *p, int initial_size);
void insertDArray(DArray *p, No* value);
void fillDArray(DArray *p, int size);
void removeElementDArray(DArray *p, int index);
void freeDArray(DArray *p);
void insertGraphNode(DArray *p, char *node_name);
int searchIndexDArray(DArray *p, char *node_name);
void insertGraphConnection(DArray *p, char *node_name, char *conn_node_name);
void removeGraphConnection(DArray *p, char *node_name, char *conn_node_name);


int main(){
    /* Here i will be creating 2 types of graph representations:
     * 1° Will be usin a matrix
     * 2° will be using a linked list (will create and declare linke list in the same file)*/
    printf("Printing Undirected Graph 'Matrix' Representation:\n");
    int matrix_graph[SIZE][SIZE] = { {0, 1, 1, 1, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 1}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 0} };
    printMatrixGraph(SIZE, matrix_graph);
    
    printf("Printing Undirected Graph TESTING ALL FUNCTIONS -> 'Linked List' Representation:\n");
    No *linked_list = NULL;
    printf("Initializing Linked List 'A'...\n");
    initLinkedList(&linked_list, "A");
    printLinkedList(linked_list);
    printf("Inserting connection 'B'...\n");
    insertEndLinkedList(linked_list, "B");
    printLinkedList(linked_list);
    printf("Inserting connection 'C'...\n");
    insertEndLinkedList(linked_list, "C");
    printLinkedList(linked_list);
    printf("Inserting connection 'D'...\n");
    insertEndLinkedList(linked_list, "D");
    printLinkedList(linked_list);
    
    printf("Deleting connection 'C'...\n");
    removeElementLinkedList(linked_list, "C");
    printLinkedList(linked_list); 
    printf("Deleting connection 'B'...\n");
    removeElementLinkedList(linked_list, "B");
    printLinkedList(linked_list); 
    printf("Attempting to delete already deleted connection 'C'...\n");
    removeElementLinkedList(linked_list, "C");
    printLinkedList(linked_list); 
    printf("Deleting connection 'D'...\n");
    removeElementLinkedList(linked_list, "D");
    printLinkedList(linked_list);
    printf("Attempting to delete already deleted connection 'D' on an empty list (only has the head node!)...\n");
    removeElementLinkedList(linked_list, "D");
    printLinkedList(linked_list);

    printf("Freeing the whole list...\n");
    freeLinkedList(&linked_list);
    printf("%p\n", linked_list);

    DArray graph;
    initDArray(&graph, 5);

    printf("Printing Undirected Graph 'Linked List' Representation:\n");
    No *a_node=NULL;
    printf("Initializing Linked List 'A'...\n");
    initLinkedList(&a_node, "A");
    insertEndLinkedList(a_node, "B");
    insertEndLinkedList(a_node, "C");
    insertEndLinkedList(a_node, "D");
    printLinkedList(a_node);
    insertDArray(&graph, a_node);

    No *b_node=NULL;
    printf("Initializing Linked List 'B'...\n");
    initLinkedList(&b_node, "B");
    insertEndLinkedList(b_node, "C");
    insertEndLinkedList(b_node, "A");
    printLinkedList(b_node);
    insertDArray(&graph, b_node);

    No *c_node=NULL;
    printf("Initializing Linked List 'C'...\n");
    initLinkedList(&c_node, "C");
    insertEndLinkedList(c_node, "A");
    insertEndLinkedList(c_node, "B");
    insertEndLinkedList(c_node, "D");
    insertEndLinkedList(c_node, "E");
    printLinkedList(c_node);
    insertDArray(&graph, c_node);
 
    No *d_node=NULL;
    printf("Initializing Linked List 'D'...\n");
    initLinkedList(&d_node, "D");
    insertEndLinkedList(d_node, "A");
    insertEndLinkedList(d_node, "C");
    printLinkedList(d_node);
    insertDArray(&graph, d_node);

    No *e_node=NULL;
    printf("Initializing Linked List 'E'...\n");
    initLinkedList(&e_node, "E");
    insertEndLinkedList(e_node, "C");
    printLinkedList(e_node);
    insertDArray(&graph, e_node);

    printf("Inserting node F into graph via InsertGraph Function...\n");
    insertGraphNode(&graph, "F");
    printf("Inserting Graph connection A into F node via insert Graph connection...\n");
    insertGraphConnection(&graph, "F", "A");
    printf("Inserting Graph connection D into F node via insert Graph connection...\n");
    insertGraphConnection(&graph, "F", "D");
    printf("Inserting Graph connection C into F node via insert Graph connection...\n");
    insertGraphConnection(&graph, "F", "C");
    printf("Attempting to Insert a connection to a node G that does not currently exist in the Graph...\n");
    insertGraphConnection(&graph, "F", "G");

    printf("\nPrinting the graph with all the above inserted nodes using the print graph function...\n");
    printDArray(&graph);

    printf("Removing connection D from F node...\n");
    removeGraphConnection(&graph, "F", "D");
    printf("Attempting to Remove a conncetion to a node K that does not corrently exist in the Graph...\n");
    removeGraphConnection(&graph, "F", "K");
    printDArray(&graph);
     
    int total = graph.used;
    for(int i=0;i<total;i++){
        printf("Removing node %c from the Graph...\n", graph.array[0]->node_name);
        removeElementDArray(&graph, 0);
        printDArray(&graph);
    } 

    printf("\nFreeing up the whole graph (freeing up each linked list within the DArray, and the DArray itself)...\n");
    freeDArray(&graph);
    printf("Attempting to print the Graph (DArray) after it has been freed up...\n");
    printDArray(&graph);
    printf("%p\n", graph);

    return 0;
}


void printMatrixGraph(int size, int matrix_graph[][size]){
    char auxArr[5] = {"ABCDE"};

    printf("  ");
    for(int i=0;i<5;i++){
        printf("%c ", auxArr[i]);
    }
    printf("\n");

    for(int i=0;i<size;i++){
        printf("%c ", auxArr[i]);
        for(int j=0;j<size;j++){
            printf("%d ", matrix_graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void initLinkedList(No **p, char *node_name){
    No *temp = (No*) malloc(sizeof(No));
    temp->node_name = *node_name;
    temp->prox = NULL;

    *p = temp;
}


void printLinkedList(No *p){
    if(p==NULL){
        printf("The list is empty!\n");
        return;
    }
    
    while(p->prox!=NULL){
        printf("%c->", p->node_name);
        p = p->prox;
    }
    printf("%c\n", p->node_name);
}


void insertEndLinkedList(No *p, char *node_name){
    if(p==NULL){
        printf("The list has not been initialized!\n");
        return;
    }

    No *temp = (No*) malloc(sizeof(No));
    temp->node_name = *node_name;
    temp->prox = NULL;
   
    while(p->prox!=NULL)
    {
        p = p->prox;
    }
    p->prox = temp;
}


void removeElementLinkedList(No *p, char *node_name)
{
    if(p==NULL){
        printf("The list has not been initialized!\n");
        return;
    }

    if(p->prox==NULL){
        printf("The list is already empty! (Only contains the head node!)\n");
        return;
    }
    
    No *temp;

    while(p->prox!=NULL){
        if(p->prox->node_name==*node_name){
            temp = p->prox;
            p->prox = p->prox->prox;
            free(temp);
            return;
        }
        p = p->prox;
    }

    printf("Element %c was not found int the list!\n", *node_name);
}


void freeLinkedList(No **p){
    if(*p==NULL){
        printf("The list has already been freed up!\n");
        return;
    }

    No *temp;
    No *aux = *p;
    while(aux->prox!=NULL){
        temp = aux->prox;
        printf("Freeing up element %c...\n", temp->node_name);
        aux->prox = aux->prox->prox;
        free(temp);
    }
    printf("Freeing up element %c...\n", aux->node_name);
    free(aux);
    *p = NULL;
}

void initDArray(DArray *p, int initial_size){
    if(initial_size<=0){
        printf("Initial size is <=0, initializing array with 2 elements...\n");
        initial_size = 2;
    }
    p->array = (No**) malloc(initial_size * sizeof(No));
    if(p->array==NULL){
        printf("The Array has not been initialized successfully... (malloc error)\n");
        return;
    }
    p->used = 0;
    p->initial_size = 2;
}


void insertDArray(DArray *p, No *value){
    if(p->array==NULL){
        printf("The Dynamic Array has not been initialized yet!\n");
        return;
    }

    if(p->used == p->initial_size){
        p->array = realloc(p->array, p->initial_size*2*sizeof(No));
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
       printLinkedList(p->array[i]);
    }
    printLinkedList(p->array[i]);
}


void removeElementDArray(DArray *p, int index){
    if(p->array==NULL){
        printf("The Dynamic Array has not been initialized yet!\n");
    }
    else if(p->used==0){
        printf("There are no elements in the initialized array!\n");
        return;
    }

    char element = p->array[index]->node_name;
    freeLinkedList(&p->array[index]);
    for(int i=index;i<p->used-1;i++){
        p->array[i] = p->array[i+1];
    }
    p->used--;

    if(p->used <= p->initial_size/2 && (((3/4.0)* p->initial_size) >= 2)){
        p->initial_size = ((3/4.0)* p->initial_size);
        printf("Resizing down the array to avoid wasting memory... New size = %d\n", p->initial_size);
        No **temp = (No**) malloc(p->initial_size * sizeof(No));
        for(int i=0;i<p->used;i++){
            temp[i] = p->array[i];
        }
        free(p->array);
        p->array=temp;
    }

    for(int i=0;i<p->used;i++){
        removeElementLinkedList(p->array[i], &element);
    }
}


void freeDArray(DArray *p){
    if(p->array==NULL){
        printf("Array has not been initialized yet!\n");
        return;
    }
    
    for(int i=0; i<p->used;i++){
        freeLinkedList(&p->array[i]);
    }
    free(p->array);
    p->array=NULL;
    p->used=0;
    p->initial_size=0;
}


void insertGraphNode(DArray *p, char *node_name){
    No *new_linked_list=NULL;
    initLinkedList(&new_linked_list, node_name);
    insertDArray(p, new_linked_list);    
}


int searchIndexDArray(DArray *p, char *node_name){
    if(p==NULL){
        printf("DArray not initialized!");
    }

    for(int i=0;i<p->used;i++){
        if(p->array[i]->node_name==*node_name){
            return i;
        }
    }
    return -1;
}


void insertGraphConnection(DArray *p, char *node_name, char *conn_node_name){
    int node_index = searchIndexDArray(p, node_name);
    if(node_index==-1){
        printf("Attempting to insert a connection to a node that is not currently in the graph!\n");
        return;
    }
    int conn_node_index = searchIndexDArray(p, conn_node_name);
    if(conn_node_index==-1){
        printf("Attempting to insert a connection node that is not currently in the graph!\n");
        return;
    }

    No *node = p->array[node_index];
    No *conn_node = p->array[conn_node_index];
    insertEndLinkedList(node, conn_node_name);
    insertEndLinkedList(conn_node, node_name);
}


void removeGraphConnection(DArray *p, char *node_name, char *conn_node_name){
    int node_index = searchIndexDArray(p, node_name);
    if(node_index==-1){
        printf("Attempting to remove a connection to a node that is not currently in the graph!\n");
        return;
    }
    int conn_node_index = searchIndexDArray(p, conn_node_name);
    if(conn_node_index==-1){
        printf("Attempting to remove a connection node that is not currently in the graph!\n");
        return;
    }

    No *node = p->array[node_index];
    No *conn_node = p->array[conn_node_index];
    removeElementLinkedList(node, conn_node_name);
    removeElementLinkedList(conn_node, node_name);
}
