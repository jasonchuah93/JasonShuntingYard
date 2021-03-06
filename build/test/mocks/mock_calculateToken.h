/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_CALCULATETOKEN_H
#define _MOCK_CALCULATETOKEN_H

#include "calculateToken.h"

void mock_calculateToken_Init(void);
void mock_calculateToken_Destroy(void);
void mock_calculateToken_Verify(void);




#define calculate_IgnoreAndReturn(cmock_retval) calculate_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void calculate_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, Token* cmock_to_return);
#define calculate_ExpectAndReturn(opeToken, first, second, cmock_retval) calculate_CMockExpectAndReturn(__LINE__, opeToken, first, second, cmock_retval)
void calculate_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, Operator* opeToken, Number* first, Number* second, Token* cmock_to_return);
typedef Token* (* CMOCK_calculate_CALLBACK)(Operator* opeToken, Number* first, Number* second, int cmock_num_calls);
void calculate_StubWithCallback(CMOCK_calculate_CALLBACK Callback);

#endif
