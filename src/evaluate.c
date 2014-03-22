#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "Stack.h"
#include "initializeToken.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"


/*
	This function is to push tokens that tokenize from expression to stack 
	
	input  : expression 
	output : none
	return : token 
	Mocking function : 1)initTokenizer(); initialize expression into tokenizer
					   2)getToken();	  get tokens from the tokenizer
					   3)stackPush();   push tokens to number stack or operator stack
					  
*/	

int evaluate(char *expression){
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
	
	return counter;
}

/*
	This function is to evaluate the expression  
	
	input  : token
	output : none
	return : final token 
	Mocking function : 1)stackPop();   pop tokens from number stack or operator stack
					   2)calculate();  to calculate the token taken into 
*/	

void operatorEvaluate1(Stack *numberStack , Stack *operatorStack){
	Tokenizer *tokenizer;
	Token *token1; //operator Token
	Token *token2; // First number token
	Token *token3; // Second number token
	Token *ansToken; // The answer
	Operator *operation;
	Number *num1;
	Number *num2;
	int i;
	int counter =0;
	
	
	token1=(Token*)stackPop(operatorStack);
	if(token1!=NULL)
	{
		operation=(Operator*)token1;
		token2=(Token*)stackPop(numberStack);
		num1=(Number*)token2;
		token3=(Token*)stackPop(numberStack);
		num2=(Number*)token3;
		ansToken = calculate(operation,num1,num2);
		stackPush(ansToken,numberStack);
	}
	

}	


