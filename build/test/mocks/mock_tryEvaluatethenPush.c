/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_tryEvaluatethenPush.h"

typedef struct _CMOCK_tryEvaluatethenPush_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  Token* Expected_token;
  Stack* Expected_numberStack;
  Stack* Expected_operatorStack;

} CMOCK_tryEvaluatethenPush_CALL_INSTANCE;

static struct mock_tryEvaluatethenPushInstance
{
  int tryEvaluatethenPush_IgnoreBool;
  CMOCK_tryEvaluatethenPush_CALLBACK tryEvaluatethenPush_CallbackFunctionPointer;
  int tryEvaluatethenPush_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE tryEvaluatethenPush_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_tryEvaluatethenPush_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.tryEvaluatethenPush_IgnoreBool)
    Mock.tryEvaluatethenPush_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.tryEvaluatethenPush_CallInstance, cmock_line, "Function 'tryEvaluatethenPush' called less times than expected.");
  if (Mock.tryEvaluatethenPush_CallbackFunctionPointer != NULL)
    Mock.tryEvaluatethenPush_CallInstance = CMOCK_GUTS_NONE;
}

void mock_tryEvaluatethenPush_Init(void)
{
  mock_tryEvaluatethenPush_Destroy();
}

void mock_tryEvaluatethenPush_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.tryEvaluatethenPush_CallbackFunctionPointer = NULL;
  Mock.tryEvaluatethenPush_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void tryEvaluatethenPush(Token* token, Stack* numberStack, Stack* operatorStack)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_tryEvaluatethenPush_CALL_INSTANCE* cmock_call_instance = (CMOCK_tryEvaluatethenPush_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.tryEvaluatethenPush_CallInstance);
  Mock.tryEvaluatethenPush_CallInstance = CMock_Guts_MemNext(Mock.tryEvaluatethenPush_CallInstance);
  if (Mock.tryEvaluatethenPush_IgnoreBool)
  {
    return;
  }
  if (Mock.tryEvaluatethenPush_CallbackFunctionPointer != NULL)
  {
    Mock.tryEvaluatethenPush_CallbackFunctionPointer(token, numberStack, operatorStack, Mock.tryEvaluatethenPush_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'tryEvaluatethenPush' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'tryEvaluatethenPush' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'tryEvaluatethenPush' called later than expected.");
  UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_token), (void*)(token), sizeof(Token), cmock_line, "Function 'tryEvaluatethenPush' called with unexpected value for argument 'token'.");
  UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_numberStack), (void*)(numberStack), sizeof(Stack), cmock_line, "Function 'tryEvaluatethenPush' called with unexpected value for argument 'numberStack'.");
  UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_operatorStack), (void*)(operatorStack), sizeof(Stack), cmock_line, "Function 'tryEvaluatethenPush' called with unexpected value for argument 'operatorStack'.");
}

void CMockExpectParameters_tryEvaluatethenPush(CMOCK_tryEvaluatethenPush_CALL_INSTANCE* cmock_call_instance, Token* token, Stack* numberStack, Stack* operatorStack)
{
  cmock_call_instance->Expected_token = token;
  cmock_call_instance->Expected_numberStack = numberStack;
  cmock_call_instance->Expected_operatorStack = operatorStack;
}

void tryEvaluatethenPush_CMockIgnore(void)
{
  Mock.tryEvaluatethenPush_IgnoreBool = (int)1;
}

void tryEvaluatethenPush_CMockExpect(UNITY_LINE_TYPE cmock_line, Token* token, Stack* numberStack, Stack* operatorStack)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_tryEvaluatethenPush_CALL_INSTANCE));
  CMOCK_tryEvaluatethenPush_CALL_INSTANCE* cmock_call_instance = (CMOCK_tryEvaluatethenPush_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.tryEvaluatethenPush_CallInstance = CMock_Guts_MemChain(Mock.tryEvaluatethenPush_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_tryEvaluatethenPush(cmock_call_instance, token, numberStack, operatorStack);
}

void tryEvaluatethenPush_StubWithCallback(CMOCK_tryEvaluatethenPush_CALLBACK Callback)
{
  Mock.tryEvaluatethenPush_CallbackFunctionPointer = Callback;
}

