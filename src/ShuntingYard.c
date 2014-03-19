#include <stdio.h>
#include <string.h>
#include "ShuntingYard.h"
#include "Stack.h"
#include "initializeToken.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"

Stack numStack;
Stack opeStack;

/*
	This function is to evaluate expression 
	
	input  : expression 
	output : none
	return : token 
	Mocking function : 1)initTokenizer(); initialize expression into tokenizer
					   2)getToken();	  get tokens from the tokenizer
					   3)stackPush();   push tokens to number stack or operator stack
					   4)stackPop();   pop tokens from number stack or operator stack
*/	

int shuntingYard(char *expression){
	Tokenizer *tokenizer;
	Token *token;
	int i;
	int counter =0;
	
	tokenizer = initTokenizer(expression);
	if(expression ==NULL){	
		return 0;
	}
	
	while((token = getToken(tokenizer))!=NULL){
		if(isNumber(token)){
			stackPush(token,&numStack);
		}
		
		else if(isOperator(token)) 
		{
			tryEvaluatethenPush(token,&numStack,&opeStack);
			stackPush(token,&opeStack);
		}
		counter ++;
	}
	 
	operatorEvaluate(&numStack,&opeStack);
	/*
	while((token = getToken(tokenizer))!=NULL){
		if(isNumber(token)){
			stackPush(token,&numStack);
		}
	}
	*/
	return counter;
}

void operatorEvaluate1(Stack *numStack , Stack *opeStack){
	Tokenizer *tokenizer;
	Token *token1;
	Token *token2;
	Token *token3;
	Operator *operation;
	Number *num1;
	Number *num2;
	int i;
	int counter =0;
	
	
	token1=(Token*)stackPop(opeStack);
	if(token1!=NULL)
	{
		operation=(Operator*)token1;
		token2=(Token*)stackPop(numStack);
		num1=(Number*)token2;
		token3=(Token*)stackPop(numStack);
		num2=(Number*)token3;
		calculate(operation,num1,num2);
	}
	
	
	
}	


