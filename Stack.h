#include <stdbool.h>


#define STACK_MAX 6*7

typedef struct Stack Stack;

int isempty();
bool isfull();
int pop();
void push(int data);
