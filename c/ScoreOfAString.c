#include <stdio.h>
#include <stdlib.h>

#define INITIAL_DA_SIZE 0
#define INITIAL_DA_CAPACITY 50
typedef struct{
	char *arr;
	int size;
	int capacity;
}DA;

DA* initDA();
void freeDA(DA **ptrda);
void printDA(DA *da);
void readUserInput(DA *da, FILE *fp);
void printDAStats(DA *da);
int scoreOfString(DA *da);

int main(int argc, char **argsv){
	DA *da = initDA();
	if(da==NULL){
		return 1;
	}

	readUserInput(da, stdin);
	int stringScore = scoreOfString(da);
	printf("\nThe score of the string:\n");
	printDA(da);
	printf("Score = %d\n",stringScore);
	freeDA(&da);

	return 0;
}

int absValue(int value){
	if (value<0){
		return value*-1;
	}
	return value;
}

int scoreOfString(DA *da){
	if(da==NULL){
		printf("NULL Dynamic Array!\n");
		return -1;
	}	
	if(da->size==0){
		printf("Empty String!\n");
		return -1;
	}

	int totalValue=0;
	char *temparr = da->arr;
	for(int i=0;i<da->size-2;i++){
		totalValue += absValue(temparr[i] - temparr[i+1]);
		printf("Total Value for |%c - %c| = |%d - %d| -> %d\n", temparr[i], temparr[i+1],temparr[i], temparr[i+1], totalValue);
	}
	return totalValue;
}

void printDAStats(DA *da){
	if(da==NULL){
		printf("NULL Dynamic Array!\n");
		return;
	}
	printf("Dynamic Array size: %d\n", da->size);
	printf("Dynamic Array capacity: %d\n", da->capacity);
}

void printDA(DA *da){
	if(da==NULL){
		printf("NULL Dynamic Array!\n");
		return;
	}
	if(da->size==0){
		printf("Empty Dynamic Array!\n");
		return;
	}

	int i;
	for(i=0;i<da->size-1;i++){
		printf("%c",da->arr[i]);
	}
	printf("%c\n",da->arr[i]);
}

DA* initDA(){
	DA *da;
	da = (DA*)malloc(sizeof(DA));
	if (da==NULL){
		printf("Failed to allocate struct DA\n");
		return NULL;
	}
	char *arr = (char*)malloc(sizeof(char)*INITIAL_DA_CAPACITY);
	if (arr==NULL){
		printf("Failed to allocate array for DA struct\n");
		return NULL;
	}
	
	da->arr = arr;
	da->size = INITIAL_DA_SIZE;
	da->capacity = INITIAL_DA_CAPACITY;
	
	return da;
}

void freeDA(DA **ptrda){
	if((*ptrda)==NULL){
		printf("Already NULL Dynamic Array!\n");
		return;
	}
	free((*ptrda)->arr);
	free((*ptrda));
	(*ptrda) = NULL;
}

void insertIntoDA(DA *da, char data){
	if(da==NULL){
		printf("NULL Dynamic Array!\n");
		return;
	}
	if (da->size+1>da->capacity){
		char *temp = (char*)realloc(da->arr, da->capacity*2);
		if (temp==NULL){
			printf("Failed to realloc DA\n");
			return;
		}
		da->arr = temp;
		da->capacity = da->capacity*2;
	}
	da->arr[da->size] = data;
	da->size++;
}

void readUserInput(DA *da, FILE *fp){
	if(da==NULL){
		printf("NULL Dynamic Array!\n");
		return;
	}
	
	printf("Enter your text and press enter to finish!\n");

	int c;
	while(1){
		c = fgetc(fp);
		if(c==10){
			insertIntoDA(da, '\0');
			break;
		}
		insertIntoDA(da, (char)c);
	}
}
