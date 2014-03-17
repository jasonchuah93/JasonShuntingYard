/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      CMock_Init(); \
      setUp(); \
      TestFunc(); \
      CMock_Verify(); \
  } \
  CMock_Destroy(); \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "mock_Stack.h"
#include "mock_getToken.h"
#include "mock_initializeToken.h"
#include "mock_operatorEvaluate.h"
#include "mock_tryEvaluatethenPush.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_shunting_yard_should_return_0_if_the_expression_is_null(void);
extern void test_evaluate_2_PLUS_3(void);
extern void test_evaluate_2_PLUS_3_MULTIPLY_4(void);
extern void test_evaluate_2_MULTIPLY_3_PLUS_4(void);
extern void test_evaluate_LEFT_PARENTHESIS_2_PLUS_3_RIGHT_PARENTHESIS_MULTIPLY_4(void);
extern void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void);
extern void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void);
extern void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_DIVIDE_10(void);
extern void test_LEFT_PARENTHESIS_2_PLUS_3_LEFTPARENTHESIS_MULTIPLY_4(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_Stack_Init();
  mock_getToken_Init();
  mock_initializeToken_Init();
  mock_operatorEvaluate_Init();
  mock_tryEvaluatethenPush_Init();
}
static void CMock_Verify(void)
{
  mock_Stack_Verify();
  mock_getToken_Verify();
  mock_initializeToken_Verify();
  mock_operatorEvaluate_Verify();
  mock_tryEvaluatethenPush_Verify();
}
static void CMock_Destroy(void)
{
  mock_Stack_Destroy();
  mock_getToken_Destroy();
  mock_initializeToken_Destroy();
  mock_operatorEvaluate_Destroy();
  mock_tryEvaluatethenPush_Destroy();
}

//=======Test Reset Option=====
void resetTest()
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_ShuntingYard.c";
  UnityBegin();
  RUN_TEST(test_shunting_yard_should_return_0_if_the_expression_is_null, 15);
  RUN_TEST(test_evaluate_2_PLUS_3, 29);
  RUN_TEST(test_evaluate_2_PLUS_3_MULTIPLY_4, 73);
  RUN_TEST(test_evaluate_2_MULTIPLY_3_PLUS_4, 133);
  RUN_TEST(test_evaluate_LEFT_PARENTHESIS_2_PLUS_3_RIGHT_PARENTHESIS_MULTIPLY_4, 193);
  RUN_TEST(test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6, 197);
  RUN_TEST(test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6, 290);
  RUN_TEST(test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_DIVIDE_10, 383);
  RUN_TEST(test_LEFT_PARENTHESIS_2_PLUS_3_LEFTPARENTHESIS_MULTIPLY_4, 490);

  return (UnityEnd());
}
