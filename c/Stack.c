#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// REVIEWED

typedef struct no
{
    int value;
    struct no *prox;
} Stack;


void fillStack(Stack *p, int size);
void printStack(Stack *p);
void initStack(Stack **p);
void insertStack(Stack *p, int value);
void removeStack(Stack *p);
int peekStack(Stack *p);
int elementsInStack(Stack *p);
void freeStack(Stack **p);


int main()
{
    srand(time(NULL));
    int size = 20;
    int num_of_elements_in_stack = 0;
    int top_element = 0;
    Stack *stack = NULL;
    initStack(&stack);
    fillStack(stack, size);
    
    printStack(stack);
    
    num_of_elements_in_stack = elementsInStack(stack);
    (num_of_elements_in_stack!=0) ? printf("There are %d elements in the stack.\n", num_of_elements_in_stack) : printf("The Stack is Empty!\n");
    
    top_element = peekStack(stack);
    (top_element != -1) ? printf("The top element in the stack is %d\n", top_element) : printf("The Stack is Empty!\n");
    
    printf("\n\nRemoving top element...\n");
    removeStack(stack);
    printStack(stack);
    
    num_of_elements_in_stack = elementsInStack(stack);
    (num_of_elements_in_stack!=0) ? printf("There are %d elements in the stack.\n", num_of_elements_in_stack) : printf("The Stack is Empty!\n");
    
    top_element = peekStack(stack);
    (top_element != -1) ? printf("The top element in the stack is %d\n", top_element) : printf("The Stack is Empty!\n");
    
    printf("Freeing Up the Stack...\n");
    freeStack(&stack);
    printf("%p",stack);
    
    return 0;
}


void initStack(Stack **p)
{
    Stack *aux = (Stack*) malloc(sizeof(Stack));
    if(aux == NULL)
    {
        printf("Fail to initialize Stack (malloc)\n");
        return;
    }
    
    
    aux->value = 0;
    aux->prox = NULL;
    *p = aux;
}


void fillStack(Stack *p, int size)
{
    for(int i=0; i<size; i++)
    {
        insertStack(p, rand()%size);
    }
}


void printStack(Stack *p)
{
    if(p->prox==NULL)
    {
        printf("Stack is Empty!\n");
        return;
    }
    
    while(p->prox!=NULL)
    {
        p = p->prox;
        printf("%d ", p->value);
    }
    printf("\n");
}


void insertStack(Stack *p, int value)
{
    Stack *aux = (Stack*) malloc(sizeof(Stack));
    if(aux == NULL)
    {
        printf("Fail to insert into Stack (malloc)\n");
        return;
    }
    
    aux->value = value;
    aux->prox = p->prox;
    p->prox = aux;
    p->value++;
}


int elementsInStack(Stack *p)
{
    return p->value;
}


int peekStack(Stack *p)
{
    if(p->prox==NULL)
    {
        return -1;
    }
    return p->prox->value;
}


void removeStack(Stack *p)
{
    if(p->prox==NULL)
    {
        printf("The Stack is Already Empty!\n");
        return;
    }
    
    Stack *aux = NULL;
    aux = p->prox;
    p->prox=p->prox->prox;
    free(aux);
    p->value--;
}


void freeStack(Stack **p)
{
    Stack *q = *p;
    Stack *aux = NULL;
    while(q->prox!=NULL)
    {
        aux = q->prox;
        q->prox=q->prox->prox;
        free(aux);
    }
    aux = q;
    *p = NULL;
    free(aux);
}
