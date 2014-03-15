#include <stdio.h>
#include <string.h>
#include "ShuntingYard.h"
#include "Stack.h"
#include "initializeToken.h"
#include "getToken.h"

Stack numStack;
Stack opeStack;
/*
	This function is to evaluate expression "2+3"
	
	input  : expression contains "2+3"
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
	
	tokenizer = initTokenizer(expression);
	int i;
	int counter =0;
	
	if(expression ==NULL){	
		return 0;
	}
	while((token = getToken(tokenizer))!=NULL){
		
		if(token == NUMBER){
		stackPush(token,&numStack);
		}
		else 
		{
			stackPush(token,&opeStack);
		}
		counter ++;
	
	}
	for(i=0;i<counter;i++){
		if(token == NUMBER){
			token = stackPop(&numStack);
		}
		else
		{
			token = stackPop(&opeStack);
		}
	}
	return counter;
}
