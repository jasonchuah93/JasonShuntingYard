#include "unity.h"
#include "Evaluate.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_Stack.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"
#include "mock_calculateToken.h"
#include "stackForEvaluate.h"

void setUp(void){}
void tearDown(void){}

void test_operator_evaluate_should_calculate_2_PLUS_3(void){
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Number answer = {.type=NUMBER, .value=5};
	Token *ansToken = (Token*)&answer;
	
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,token1);
	stackPop_ExpectAndReturn(&numStack,token3);
	calculate_ExpectAndReturn(&plus,&number2,&number3,ansToken);
	stackPush_Expect(ansToken,&numStack);
	
	operatorEvaluate1(&numStack,&opeStack);
}