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

void getnexts(nodet *head){
	nodet *temp = head;
	nodet *temp2 = head;
	while (temp != NULL){
		temp = temp->prev;
		if (temp == NULL){
			break;
		}
		temp->next = temp2;
		temp2 = temp;
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
	getnexts (head);
	printvalues(head);
	printvaluesnormally(tail);
	return 0;
}