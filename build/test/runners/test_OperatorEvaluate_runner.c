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
#include "mock_calculateToken.h"
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
extern void test_operator_evaluate_should_calculate_2_PLUS_3(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_Stack_Init();
  mock_calculateToken_Init();
  mock_getToken_Init();
  mock_initializeToken_Init();
  mock_operatorEvaluate_Init();
  mock_tryEvaluatethenPush_Init();
}
static void CMock_Verify(void)
{
  mock_Stack_Verify();
  mock_calculateToken_Verify();
  mock_getToken_Verify();
  mock_initializeToken_Verify();
  mock_operatorEvaluate_Verify();
  mock_tryEvaluatethenPush_Verify();
}
static void CMock_Destroy(void)
{
  mock_Stack_Destroy();
  mock_calculateToken_Destroy();
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
  Unity.TestFile = "test_OperatorEvaluate.c";
  UnityBegin();
  RUN_TEST(test_operator_evaluate_should_calculate_2_PLUS_3, 14);

  return (UnityEnd());
}