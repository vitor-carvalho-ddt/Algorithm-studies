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
int findIndex(No *q, int value);
int findIndexSorted(No *q, int value);
int countElement(No *q, int value);
int countElementSorted(No *q, int value);
No *deleteStart(No **p);
No *deleteEnd(No **p);
No *deleteNumber(No **p, int value);


int main()
{
    srand(time(NULL));
    int rand_num=0;
    int size = 20;
    int value_to_find = rand()%size;
    int item_index = 0;
    int item_found_times = 0;
    No* linkedList = NULL;
    
    std::cout << "Inserting at the beggining of the linked list..." << "\n";
    
    for(int i=0;i<size;i++)
    {
        rand_num = rand()%size;
        (i==0)? std::cout << rand_num: std::cout << "|" << rand_num;
        linkedList = insertBegin(&linkedList, rand_num);
    }
    std::cout << "\n";
    printLinkedList(linkedList);
    item_index = findIndex(linkedList, value_to_find);
    (item_index!=-1)?std::cout << "Value " << value_to_find << " found at index " << item_index << "\n": std::cout << "Value " << value_to_find << " not found in the list!" << "\n";
    item_found_times = countElement(linkedList, value_to_find);
    (item_index!=-1)?std::cout << "Value " << value_to_find << " found " << item_found_times << " times" << "\n" : std::cout << "Value " << value_to_find << " not found in the list!" << "\n";
    std::cout << "Deleting at the start..." << "\n";
    linkedList = deleteStart(&linkedList);
    printLinkedList(linkedList);
    std::cout << "Deleting at the end..." << "\n";
    linkedList = deleteEnd(&linkedList);
    printLinkedList(linkedList);
    std::cout << "Deleting random number " << rand_num << "...\n";
    linkedList = deleteNumber(&linkedList, rand_num);
    printLinkedList(linkedList);
    std::cout << "\n\n";
    linkedList = emptyLinkedList(linkedList);
    

    std::cout << "Inserting at the end of the linked list..." << "\n";
    
    for(int i=0;i<size;i++)
    {
        rand_num = rand()%size;
        (i==0)?std::cout << rand_num : std::cout << "|" << rand_num;
        linkedList = insertEnd(&linkedList, rand_num);
    }
    std::cout << "\n";
    printLinkedList(linkedList);
    item_index = findIndex(linkedList, value_to_find);
    (item_index!=-1)?std::cout << "Value " << value_to_find << " found at index " << item_index << "\n" : std::cout << "Value " << value_to_find << " not found in the list!" << "\n";
    item_found_times = countElement(linkedList, value_to_find);
    (item_index!=-1) ? std::cout << "Value " << value_to_find << " found " << item_found_times << " times\n" : std::cout << "Value " << value_to_find << " not found in the list!" << "\n";
    std::cout << "Deleting at the start..." << "\n";
    linkedList = deleteStart(&linkedList);
    printLinkedList(linkedList);
    std::cout << "Deleting at the end..." << "\n";
    linkedList = deleteEnd(&linkedList);
    printLinkedList(linkedList);
    std::cout << "Deleting random number " << rand_num << "...\n";
    linkedList = deleteNumber(&linkedList, rand_num);
    printLinkedList(linkedList);
    std::cout << "\n\n";
    linkedList = emptyLinkedList(linkedList);
    
    
    std::cout << "Inserting sorted into the linked list..." << "\n";
    
    for(int i=size;i>0;i--)
    {
        rand_num = rand()%size;
        (i==0)?std::cout << rand_num :std::cout << "|" << rand_num;
        linkedList = insertSorted(&linkedList, rand_num);
    }
    std::cout << "\n";
    printLinkedList(linkedList);
    item_index = findIndexSorted(linkedList, value_to_find);
    (item_index!=-1)?std::cout << "Value " << value_to_find << " found at index " << item_index << "\n" : std::cout << "Value " << value_to_find << " not found in the list!" << "\n";
    item_found_times = countElementSorted(linkedList, value_to_find);
    (item_index!=-1)?std::cout << "Value " << value_to_find << " found " << item_found_times << " times\n" : std::cout << "Value " << value_to_find << "not found in the list!" << "\n";
    std::cout << "Deleting at the start..." << "\n";
    linkedList = deleteStart(&linkedList);
    printLinkedList(linkedList);
    std::cout << "Deleting at the end..." << "\n";
    linkedList = deleteEnd(&linkedList);
    printLinkedList(linkedList);
    std::cout << "Deleting random number " << rand_num << "...\n";
    linkedList = deleteNumber(&linkedList, rand_num);
    printLinkedList(linkedList);
    std::cout << "\n\n";
    linkedList = emptyLinkedList(linkedList);

    return 0;
}


void printLinkedList(No *q)
{
    if(q==NULL)
    {
        std::cout << "Empty List!";
    }
    while(q!=NULL)
    {
        std::cout << " " << q->value;
        q = q->prox;
    }
    std::cout << "\n";
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


int findIndex(No *q, int value)
{
    if(q==NULL)
    {
        return -1;
    }
    int index=0;
    while(q!=NULL)
    {
        if(value==q->value)
        {
            return index;
        }
        else
        {
            q = q->prox;
            index++;
        }
    }
    return -1;
}


int findIndexSorted(No *q, int value)
{
    if(q==NULL)
    {
        return -1;
    }
    int index=0;
    while(q!=NULL)
    {
        if(value<q->value)
        {
            return -1;
        }
        if(value==q->value)
        {
            return index;
        }
        else
        {
            q = q->prox;
            index++;
        }
    }
    return -1;
}


int countElement(No *q, int value)
{
    int sum = 0;
    if(q==NULL)
    {
        return sum;
    }
    while(q!=NULL)
    {
        if(value==q->value)
        {
            sum++;
            q = q->prox;
        }
        else
        {
            q = q->prox;
        }
    }
    return sum;
}



int countElementSorted(No *q, int value)
{
    int sum = 0;
    if(q==NULL)
    {
        return sum;
    }
    while(q!=NULL)
    {
        if(value<q->value)
        {
            return sum;
        }
        if(value==q->value)
        {
            sum++;
            q = q->prox;
        }
        else
        {
            q = q->prox;
        }
    }
    return sum;
}


No *deleteStart(No **p)
{
    No *q = *p;
    No *aux = q;
    if(q==NULL) return q;
    else if (q->prox!=NULL)
    {
        aux = q;
        q = q->prox;
        free(aux);
    }
    else
    {
        aux = q;
        q = NULL;
        free(aux);
    }
    
    return q;
}


No *deleteEnd(No **p)
{
    No *q = *p;
    No *aux = q;
    if(q==NULL) return q;
    else if(q->prox==NULL)
    {
        q = NULL;
        free(aux);
        return q;
    }
    while(aux->prox->prox!=NULL)
    {
        aux = aux->prox;
    }
    No *temp = aux->prox;
    aux->prox=NULL;
    free(temp);
    
    return q;
}

No *deleteNumber(No **p, int value)
{
    No *q = *p;
    if(q==NULL) return q;

    if(q->value==value)
    {
        No *aux = q;
        q = q->prox;
        free(aux);
        return q;
    }
    
    No* temp = q;
    while(temp->prox->prox!=NULL)
    {
        if(temp->prox->value==value)
        {
            No *aux = temp->prox;
            temp->prox = temp->prox->prox;
            free(aux);
            return q;
        }
        else
        {
            temp = temp->prox;    
        }
    }
    if(temp->prox->value==value)
    {
        No *aux = temp->prox;
        temp->prox = NULL;
        free(aux);
    }
    return q;
}