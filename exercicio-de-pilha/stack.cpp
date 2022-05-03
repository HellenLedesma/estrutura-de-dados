#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

struct stack {
	int stackTop;
	int vetor[MAXSIZE];
};

typedef struct stack STACK;
STACK s;

int options(){
	int ops;
	printf("\n\n ------------ \n\n");
	printf("0 - Exit\n");
	printf("1 - Push\n");
	printf("2 - Pop\n");
	printf("3 - Print stack\n\t");
	scanf("%d", &ops);
	return ops;
}

//function remove element from the top of the stack
 void functionPop(){
	int num;
	int stackTop;
	if (s.stackTop == 0){
		printf("The stack is empty. You should push a element before.");
	}else {
		num = s.vetor[stackTop];
		printf("The removed element was:\n\t ");
		printf("%d", s.vetor[s.stackTop]);
		s.stackTop = s.stackTop -1;
	}
}

//function add element at the top of the stack
void functionPush(){
	int num;
	if (s.stackTop == (MAXSIZE)){
		printf("Stack full!");
	}else {
		printf("Insert an element at the top of the stack:\n\t");
		scanf("%d", &num);
		s.stackTop = s.stackTop + 1;
		s.vetor[s.stackTop] = num;
	}

}
//function print the list of the elements
void printStack(){
	int i;
	if (s.stackTop == 0){
		printf("Stack empty.");
	}else {
		printf("Stack elements are: \n\t");
		for(i = s.stackTop; i >= 1; i--){
			printf("%d\n\t", s.vetor[i]);
		}
	}
}

int choices(int ops, struct stack *vetor){
	switch(ops){
		case 0:
			break;
		case 1:
			functionPush();
			break;
		case 2:
			functionPop();
			break;
		case 3:
			printStack();	
	}
}

main(){	
	struct stack stack = STACK();
	int menu = -1;
	while (menu != 0){
		menu = options();
		system("cls");
		choices(menu, &stack);
	}
}

