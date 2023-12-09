#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct no{
    char node_name;
    struct no *prox;
} No;


void initLinkedList(No **p, char *node_name);
void printLinkedList(No *p);
void insertEndLinkedList(No *p, char *node_name);
void removeElementLinkedList(No *p, char *node_name);
void freeLinkedList(No **p);
void printMatrixGraph(int size, int matrix_graph[][size]);


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

    printf("Printing Undirected Graph 'Linked List' Representation:\n");

    printf("Initializing Linked List 'A'...\n");
    initLinkedList(&linked_list, "A");
    insertEndLinkedList(linked_list, "B");
    insertEndLinkedList(linked_list, "C");
    insertEndLinkedList(linked_list, "D");
    printLinkedList(linked_list);
    freeLinkedList(&linked_list);

    printf("Initializing Linked List 'B'...\n");
    initLinkedList(&linked_list, "B");
    insertEndLinkedList(linked_list, "C");
    insertEndLinkedList(linked_list, "A");
    printLinkedList(linked_list);
    freeLinkedList(&linked_list);

    printf("Initializing Linked List 'C'...\n");
    initLinkedList(&linked_list, "C");
    insertEndLinkedList(linked_list, "A");
    insertEndLinkedList(linked_list, "B");
    insertEndLinkedList(linked_list, "D");
    insertEndLinkedList(linked_list, "E");
    printLinkedList(linked_list);
    freeLinkedList(&linked_list);
 
    printf("Initializing Linked List 'D'...\n");
    initLinkedList(&linked_list, "D");
    insertEndLinkedList(linked_list, "A");
    insertEndLinkedList(linked_list, "C");
    printLinkedList(linked_list);
    freeLinkedList(&linked_list);
 
    printf("Initializing Linked List 'E'...\n");
    initLinkedList(&linked_list, "E");
    insertEndLinkedList(linked_list, "C");
    printLinkedList(linked_list);
    freeLinkedList(&linked_list);
    

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
