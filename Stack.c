
#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

int MAXSIZE = 42;
int stack[42];
int top = -1;

int isempty() {

	if(top == -1)
		return 1;
	else
		return 0;
}

bool isfull() {

	if(top == MAXSIZE)
		return true;
	else
		return false;
}

int pop() {
	int data;

	if(!isempty()) {
		data = stack[top];
		top = top - 1;
		return data;
	} else {
		printf("Could not retrieve data, Stack is empty.\n");
	}
	return  0;
}
void push(int data) {

	if(!isfull()) {
		top = top + 1;
		stack[top] = data;
	} else {
		printf("Could not insert data, Stack is full.\n");
	}
}


