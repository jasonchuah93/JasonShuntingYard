#ifndef __GETTOKEN_H__
#define __GETTOKEN_H__

#include "Evaluate.h"

//Function declaration
Token *getToken(Tokenizer *tokenizer);

int isNumber(Token *tokens);
int isOperator(Token *tokens);


#endif //__GETTOKEN_H__