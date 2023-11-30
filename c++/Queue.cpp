#include <iostream>
#include <stdlib.h>
#include <time.h>


typedef struct queue
{
    int value;
    struct queue *prox;
} Queue;


void initQueue(Queue **p);
void printQueue(Queue *q);
void enqueue(Queue *q, int value);
int peekTop(Queue *q);
void dequeue(Queue *q);
int queueLength(Queue *q);
void freeQueue(Queue **p);

int main()
{
    srand(time(NULL));
    int size = 20;
    int top_element = 0;
    int queue_len = 0;
    
    Queue *queue=NULL;
    initQueue(&queue);
    printQueue(queue);
    
    std::cout << "Inserting random values into the Queue..." << "\n";
    for(int i=0;i<size;i++)
    {
        enqueue(queue, rand()%size);
    }
    printQueue(queue);
    
    queue_len = queueLength(queue);
    (queue_len != 0) ? std::cout << "The Queue has a length of " << queue_len << "\n" : std::cout << "The Queue is Emtpy! The length is 0!" << "\n";
    
    top_element = peekTop(queue);
    (top_element != -1) ? std::cout << "The element at the top of the Queue is " << top_element << "\n" : std::cout << "The Queue is Emtpy!" << "\n";
    
    std::cout << "Dequeueing..." << "\n";
    dequeue(queue);
    printQueue(queue);
    
    queue_len = queueLength(queue);
    (queue_len != 0) ? std::cout << "The Queue has a length of " << queue_len << "\n" : std::cout << "The Queue is Emtpy! The length is 0!" << "\n";
    
    top_element = peekTop(queue);
    (top_element != -1) ? std::cout << "The element at the top of the Queue is " << top_element << "\n" : std::cout << "The Queue is Emtpy!" << "\n";
    
    
    freeQueue(&queue);
    std::cout << "queue: " << queue << "\n";
    
    return 0;
}


void initQueue(Queue **p)
{
    Queue *aux = (Queue*) malloc(sizeof(Queue));
    if(aux==NULL) return;
    
    aux->value = 0;
    aux->prox = NULL;
    *p = aux;
}


void printQueue(Queue *q)
{
    if(q->prox==NULL)
    {
        std::cout << "Queue is Empty!" << "\n";
        return;
    }
    
    Queue *aux;
    
    for(aux=q->prox;aux->prox!=NULL;aux=aux->prox)
    {
        std::cout << " " << aux->value;
    }
    std::cout << " " << aux->value;
    std::cout << "\n";
}


void enqueue(Queue *q, int value)
{
    Queue *aux = (Queue*) malloc(sizeof(Queue));
    if(aux==NULL) return;
    
    aux->value = value;
    aux->prox = NULL;
    
    Queue *temp;
    for(temp=q;temp->prox!=NULL;temp=temp->prox);
    
    temp->prox = aux;
}


int peekTop(Queue *q)
{
    if(q->prox==NULL) return -1;
    return q->prox->value;
}


void dequeue(Queue *q)
{
    if(q->prox==NULL)
    {
        std::cout << "Queue is already empty. No need to dequeue." << "\n";
        return;
    }
    
    Queue *aux = q->prox;
    q->prox = q->prox->prox;
    free(aux);
}


int queueLength(Queue *q)
{
    int len = 0;
    if(q->prox==NULL) return len;
    
    for(q=q->prox;q->prox!=NULL;q=q->prox)
        len++;
    len++;
    
    return len;
}


void freeQueue(Queue **p)
{
    Queue *q = *p;
    
    Queue *aux = NULL;
    while(q->prox!=NULL)
    {
        aux = q->prox;
        q->prox = q->prox->prox;
        free(aux);
    }
    
    aux = q;
    *p = NULL;
    free(aux);
}