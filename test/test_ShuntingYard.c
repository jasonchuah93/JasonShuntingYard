#include "unity.h"
#include "ShuntingYard.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_Stack.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"

void setUp(void){}
void tearDown(void){}

Stack numStack;
Stack opeStack;

void test_shunting_yard_should_return_0_if_the_expression_is_null(){
	int check;
	Tokenizer tokenizer = {.rawString = "0", .startIndex = 0, .length = 1};
	
	Number number2 = {.type= NUMBER, .value=0};
	Token *token1 = (Token*)&number2;
	
	initTokenizer_ExpectAndReturn(NULL,&tokenizer);
	
	check=shuntingYard(NULL);
	TEST_ASSERT_EQUAL(0,check);
}


void test_evaluate_2_PLUS_3(void){
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Number answer = {.type=NUMBER, .value=5};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("2+3",&tokenizer);
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	stackPush_Expect(token2,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	
	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	shuntingYard("2+3");
}

void test_evaluate_2_PLUS_3_MULTIPLY_4(void){
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.rawString = "2+3*4", .startIndex = 0, .length = 5};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Number answer = {.type=NUMBER, .value=14};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("2+3*4",&tokenizer);
	
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	stackPush_Expect(token2,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	stackPush_Expect(token4,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	shuntingYard("2+3*4");
}	

void test_evaluate_2_MULTIPLY_3_PLUS_4(void){	
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token2 = (Token*)&multiply;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Number answer = {.type=NUMBER, .value=10};
	Token *ansToken = (Token*)&answer;

	//Evaluate the expression
	initTokenizer_ExpectAndReturn("2*3+4",&tokenizer);
	
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	stackPush_Expect(token2,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	stackPush_Expect(token4,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	shuntingYard("2*3+4");
}