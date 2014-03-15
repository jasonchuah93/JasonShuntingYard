#ifndef __STACK_H__
#define __STACK_H__



typedef struct Stack_t{
	void *numberStack;
	void *operatorStack;
}Stack;

//Function declaration
void stackPush(void *element,Stack *stack );
void *stackPop(Stack *stack);

#endif //__STACK_H__