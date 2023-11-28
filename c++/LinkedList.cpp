#include <iostream>
#include <stdlib.h>
#include <time.h>


typedef struct no{
    int value;
    struct no *prox;
} No;


void printLinkedList(No *q);
No *insertBegin(No **p, int value);
No *insertEnd(No **p, int value);
No *emptyLinkedList(No *q);
No *insertSorted(No **p, int value);


int main()
{
    srand(time(NULL));
    int rand_num=0;
    int size = 20;
    No* linkedList = NULL;
    
    std::cout << "Inserting at the beggining of the linked list..." << "\n";
    
    for(int i=0;i<size;i++)
    {
        rand_num = rand()%size;
        (i==0)? std::cout << rand_num: std::cout << "|" << rand_num;
        linkedList = insertBegin(&linkedList, rand_num);
    }
    printf("\n");
    printLinkedList(linkedList);
    linkedList = emptyLinkedList(linkedList);


    std::cout << "Inserting at the end of the linked list..." << "\n";
    
    for(int i=0;i<size;i++)
    {
        rand_num = rand()%size;
        (i==0)? std::cout << rand_num: std::cout << "|" << rand_num;
        linkedList = insertEnd(&linkedList, rand_num);
    }
    printf("\n");
    printLinkedList(linkedList);
    linkedList = emptyLinkedList(linkedList);
    
    
    std::cout << "Inserting sorted into the linked list..." << "\n";
    
    for(int i=size;i>0;i--)
    {
        rand_num = rand()%size;
        (i==0)? std::cout << rand_num: std::cout << "|" << rand_num;
        linkedList = insertSorted(&linkedList, rand_num);
    }
    printf("\n");
    printLinkedList(linkedList);
    linkedList = emptyLinkedList(linkedList);

    return 0;
}


void printLinkedList(No *q)
{
    if(q==NULL)
    {
        std::cout << "Empty List!" << "\n";
    }
    while(q!=NULL)
    {
        printf(" %d", q->value);
        q = q->prox;
    }
    printf("\n");
}


No *emptyLinkedList(No *q)
{
    if(q==NULL) return q;
    if(q->prox==NULL)
    {
        free(q);
    }
    else
    {
        while(q!=NULL)
        {
            No *temp = q;
            q = q->prox;
            free(temp);
        }
    }
    return q;
}


No *insertBegin(No **p, int value)
{
    No *q = *p;
    No *aux = (No*) malloc(sizeof(No));
    if(aux==NULL) return q;
    aux->value = value;
    aux->prox  = q;
    if(q==NULL)
    {
        q=aux;
    }
    else
    {
        q=aux;
    }
    return q;
}


No *insertEnd(No **p, int value)
{
    No *q = *p;
    No *aux = (No*) malloc(sizeof(No));
    if(aux==NULL) return q;
    aux->value = value;
    aux->prox  = NULL;
    if(q==NULL)
    {
        q=aux;
    }
    else
    {
        No *temp = *p;
        while(temp->prox!=NULL)
        {
            temp = temp->prox;
        }
        temp->prox=aux;
    }
    return q;
}


No *insertSorted(No **p, int value)
{
    No *q = *p;
    No *aux = (No*) malloc(sizeof(No));
    if(aux==NULL) return q;
    aux->value = value;
    if(q==NULL)
    {
        aux->prox = q;
        q = aux;
    }
    
    else
    {
        if(value<=q->value)
        {
            aux->prox=q;
            q = aux;
            return q;
        }
        No *temp = q;
        while(temp->prox!=NULL)
        {
            if(value>temp->prox->value)
            {
                temp = temp->prox;
            }
            else
            {
                aux->prox = temp->prox;
                temp->prox = aux;
                return q;
            }
        }
        aux->prox=NULL;
        temp->prox=aux;
    }
    return q;
}