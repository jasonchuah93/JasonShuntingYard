









typedef struct Stack_t{

 void *numberStack;

 void *operatorStack;

}Stack;





void stackPush(void *element,Stack *stack );

void *stackPop(Stack *stack);
