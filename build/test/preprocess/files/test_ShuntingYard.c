#include "unity.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_Stack.h"
#include "ShuntingYard.h"


void setUp(void){}

void tearDown(void){}



void test_shunting_yard_should_return_0_if_the_expression_is_null(){

 int check;

 Tokenizer tokenizer = {.rawString = "0", .startIndex = 0, .length = 1};



 Number number2 = {.type= NUMBER, .value=0};

 Token *token1 = (Token*)&number2;



 initTokenizer_CMockExpectAndReturn(17, ((void *)0), &tokenizer);



 check=shuntingYard(((void *)0));

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

}





void test_evaluate_2_PLUS_3(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;





 initTokenizer_CMockExpectAndReturn(39, "2+3", &tokenizer);

 getToken_CMockExpectAndReturn(40, &tokenizer, token1);

 stackPush_CMockExpect(41, token1, &numStack);

 getToken_CMockExpectAndReturn(42, &tokenizer, token2);

 stackPush_CMockExpect(43, token2, &opeStack);

 getToken_CMockExpectAndReturn(44, &tokenizer, token3);

 stackPush_CMockExpect(45, token3, &numStack);

 getToken_CMockExpectAndReturn(46, &tokenizer, ((void *)0));



 stackPop_CMockExpectAndReturn(48, &opeStack, token2);

 stackPop_CMockExpectAndReturn(49, &numStack, token3);

 stackPop_CMockExpectAndReturn(50, &numStack, token1);



 shuntingYard("2+3");

}
