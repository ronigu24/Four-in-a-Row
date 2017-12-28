#include <stdbool.h>


#define MAXSIZE 6*7

typedef struct Stack Stack;

int isempty();
bool isfull();
int pop();
void push(int data);
