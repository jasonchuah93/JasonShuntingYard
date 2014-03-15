#include "unity.h"
#include "ShuntingYard.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_Stack.h"

void setUp(void){}
void tearDown(void){}

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
	
	//Evaluate the expression
	initTokenizer_ExpectAndReturn("2+3",&tokenizer);
	getToken_ExpectAndReturn(&tokenizer,token1);
	stackPush_Expect(token1,&numStack);
	getToken_ExpectAndReturn(&tokenizer,token2);
	stackPush_Expect(token2,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,token3);
	stackPush_Expect(token3,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);

	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	
	shuntingYard("2+3");
}
