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

void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token4 = (Token*)&multiply;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Operator plus1 = {.type= OPERATOR, .id = ADD};
	Token *token6 = (Token*)&plus1;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};
	Token *token8 = (Token*)&multiply1;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Number answer = {.type=NUMBER, .value=44};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("2+3*4+5*6",&tokenizer);
	
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
	
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	tryEvaluatethenPush_Expect(token6,&numStack,&opeStack);
	stackPush_Expect(token6,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	tryEvaluatethenPush_Expect(token8,&numStack,&opeStack);
	stackPush_Expect(token8,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);

	
	shuntingYard("2+3*4+5*6");
}

void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};
	
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
	
	Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};
	Token *token6 = (Token*)&multiply1;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator plus1 = {.type= OPERATOR, .id = ADD};
	Token *token8 = (Token*)&plus1;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Number answer = {.type=NUMBER, .value=32};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("2*3+4*5+6",&tokenizer);
	
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
	
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	tryEvaluatethenPush_Expect(token6,&numStack,&opeStack);
	stackPush_Expect(token6,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	tryEvaluatethenPush_Expect(token8,&numStack,&opeStack);
	stackPush_Expect(token8,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	shuntingYard("2*3+4*5+6");

}

void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_DIVIDE_10(void){
	Tokenizer tokenizer = {.rawString = "2|3+4*5-6/10", .startIndex = 0, .length = 11};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator OR = {.type= OPERATOR, .id = BITWISE_OR};
	Token *token2 = (Token*)&OR;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token6 = (Token*)&multiply;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator subtract = {.type= OPERATOR, .id = SUBTRACT};
	Token *token8 = (Token*)&subtract;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Operator divide = {.type= OPERATOR, .id = DIVIDE};
	Token *token10 = (Token*)&subtract;
	
	Number number10 = {.type= NUMBER, .value=10};
	Token *token11 = (Token*)&number10;
	
	Number answer = {.type=NUMBER, .value=22.5};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("2|3+4*5-6/10",&tokenizer);
	
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
	
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	tryEvaluatethenPush_Expect(token6,&numStack,&opeStack);
	stackPush_Expect(token6,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	tryEvaluatethenPush_Expect(token8,&numStack,&opeStack);
	stackPush_Expect(token8,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token10);
	isNumber_ExpectAndReturn(token10,0);
	isOperator_ExpectAndReturn(token10,1);
	tryEvaluatethenPush_Expect(token10,&numStack,&opeStack);
	stackPush_Expect(token10,&opeStack);
		
	getToken_ExpectAndReturn(&tokenizer,token11);
	isNumber_ExpectAndReturn(token11,1);
	stackPush_Expect(token11,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);

	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	shuntingYard("2|3+4*5-6/10");
	
}

void test_LEFT_PARENTHESIS_2_PLUS_3_RIGHT_PARENTHESIS_MULTIPLY_4(void){
	Tokenizer tokenizer = {.rawString = "(2+3)*4", .startIndex = 0, .length = 7 };
	
	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token1 = (Token*)&leftBracket;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token2 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token3 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token4 = (Token*)&number3;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token5 = (Token*)&rightBracket;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token6 = (Token*)&multiply;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token7 = (Token*)&number4;
	
	Number answer = {.type=NUMBER, .value=20};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("(2+3)*4",&tokenizer);
	
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	stackPush_Expect(token1,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	stackPush_Expect(token3,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,1);
	stackPush_Expect(token4,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	tryEvaluatethenPush_Expect(token5,&numStack,&opeStack);
	stackPush_Expect(token5,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	tryEvaluatethenPush_Expect(token6,&numStack,&opeStack);
	stackPush_Expect(token6,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	shuntingYard("(2+3)*4");
}

void test_2_MULTIPLY_LEFT_PARENTHESIS_THREE_PLUS_FOUR_RIGHT_PARENTHESIS(void){
	Tokenizer tokenizer = {.rawString = "2*(3+4)", .startIndex = 0, .length = 7 };
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token2 = (Token*)&multiply;
	
	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token3 = (Token*)&leftBracket;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token4 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token5 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token6 = (Token*)&number4;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token7 = (Token*)&rightBracket;
	
	Number answer = {.type=NUMBER, .value=14};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("2*(3+4)",&tokenizer);
	//2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	//MULTIPLY
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	stackPush_Expect(token2,&opeStack);
	//LEFT_PARENTHESIS
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	stackPush_Expect(token3,&opeStack);
	//3
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,1);
	stackPush_Expect(token4,&numStack);
	//PLUS
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	tryEvaluatethenPush_Expect(token5,&numStack,&opeStack);
	stackPush_Expect(token5,&opeStack);
	//FOUR
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,1);
	stackPush_Expect(token6,&numStack);
	//RIGHT PARENTHESIS
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,0);
	isOperator_ExpectAndReturn(token7,1);
	tryEvaluatethenPush_Expect(token7,&numStack,&opeStack);
	stackPush_Expect(token7,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	shuntingYard("2*(3+4)");
}

void test_NEGATIVE_2_SHOULD_RETURN_NEGATIVE_2(void){
	Tokenizer tokenizer = {.rawString = "-2", .startIndex = 0, .length = 2 };
	
	Operator subtract = {.type= OPERATOR, .id = SUBTRACT};
	Token *token1 = (Token*)&subtract;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token2 = (Token*)&number2;
	
	Number answer = {.type=NUMBER, .value=-2};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("-2",&tokenizer);
	
	//NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	stackPush_Expect(token1,&opeStack);
	
	//2
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	shuntingYard("-2");
}

void test_NEGATIVE_2_PLUS_NEGATIVE_3(void){
	Tokenizer tokenizer = {.rawString = "-2+-3", .startIndex = 0, .length = 5 };
	
	Operator negative = {.type= OPERATOR, .id = SUBTRACT};
	Token *token1 = (Token*)&negative;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token2 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token3 = (Token*)&plus;
	
	Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token4 = (Token*)&negative2;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token5 = (Token*)&number3;
	
	Number answer = {.type=NUMBER, .value=-5};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("-2+-3",&tokenizer);
	
	//NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	stackPush_Expect(token1,&opeStack);
	
	//2
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&numStack);
	
	//PLUS
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	stackPush_Expect(token3,&opeStack);
	
	//NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	stackPush_Expect(token4,&opeStack);
	
	//3
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	shuntingYard("-2+-3");
}
	
void test_NEGATIVE_NEGATIVE_NEGATIVE_NEGATIVE_NEGATIVE_2(void){
	Tokenizer tokenizer = {.rawString = "-----2", .startIndex = 0, .length = 6 };
	
	Operator negative = {.type= OPERATOR, .id = SUBTRACT};
	Token *token1 = (Token*)&negative;
	
	Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token2 = (Token*)&negative2;
	
	Operator negative3 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token3 = (Token*)&negative3;
	
	Operator negative4 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token4 = (Token*)&negative4;
	
	Operator negative5 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token5 = (Token*)&negative5;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token6 = (Token*)&number2;
	
	Number answer = {.type=NUMBER, .value=-2};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("-----2",&tokenizer);
	
	//NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	stackPush_Expect(token1,&opeStack);
	
	//NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	stackPush_Expect(token2,&opeStack);
	
	//NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	stackPush_Expect(token3,&opeStack);
	
	//NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	stackPush_Expect(token4,&opeStack);
	
	//NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	tryEvaluatethenPush_Expect(token5,&numStack,&opeStack);
	stackPush_Expect(token5,&opeStack);
	
	//2
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,ansToken);
	isNumber_ExpectAndReturn(ansToken,1);
	stackPush_Expect(ansToken,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	shuntingYard("-----2");
	
}