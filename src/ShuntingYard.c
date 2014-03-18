#include <stdio.h>
#include <string.h>
#include "ShuntingYard.h"
#include "Stack.h"
#include "initializeToken.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"

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
	
	while((token = getToken(tokenizer))!=NULL){
		if(isNumber(token)){
			stackPush(token,&numStack);
		}
	}
	
	return counter;
}

int operatorEvaluate1(Stack *numStack , Stack *opeStack){
	Tokenizer *tokenizer;
	Token *token;
	int i;
	int counter =0;
	
	for(i=0 ; i<counter ; i++){
		if(isNumber(token)){
			token = stackPop(numStack);
		}
		else if(isOperator(token)){
			token = stackPop(opeStack);
		}
		counter ++;
	}
	
	return counter;
}	
