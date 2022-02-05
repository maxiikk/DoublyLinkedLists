#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct node {
	int value;
	struct node *next;
	struct node *prev;
};
typedef struct node nodet;

nodet *createnode(int value, nodet *temp){
	nodet *result = malloc (sizeof(nodet));
	result->prev = temp;
	temp->next = result;
	result->value = value;
	result->next = NULL;
	return result;
}

void printvalues(nodet *head) {
	nodet *temp = head;
	while (temp != NULL){
		printf("%d\n", temp->value);
		temp = temp->prev;
	}
}
void printvaluesnormally (nodet *tail){
	nodet *temp = tail;
	while (temp != NULL){
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}
int main(int argc, char *argv[]) {
	
	
	nodet *head = NULL;
	nodet *temp;
	nodet *tail = temp;
	temp->prev = NULL;
	temp->value = 0;
	
	for (int i = 1; i <= 5; i++){
		temp = createnode(i, temp);
		head = temp;
	}
	printvalues(head);
	printvaluesnormally(tail);
	return 0;
}
