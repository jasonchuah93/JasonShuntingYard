#ifndef ShuntingYard_H
#define ShuntingYard_H

#include "Stack.h"

extern Stack numStack;
extern Stack opeStack;

typedef enum {NUMBER,OPERATOR,IDENTIFIER}Token;
//Updating in progress, please be patient.....
typedef enum {CURRENT_PROGRAM_COUNTER,LEFT_PARENTHESIS,RIGHT_PARENTHESIS,LOGIC_NOT,
				COMPLEMENT,LOW,HIGH,UPPER,MULTIPLY,DIVIDE,MODULUS,ADD,SUBTRACT,LEFT_SHIFT,
				RIGHT_SHIFT,GREATER_EQUAL_THAN,GREATER_THAN,LESS_THAN,LESS_EQUAL_THAN,
				EQUAL_TO,NOT_EQUAL,BITWISE_AND,BITWISE_XOR,BITWISE_OR,LOGICAL_AND,LOGICAL_OR,
				EQUAL,ADD_SET_EQUAL,SUBTRACT_SET_EQUAL,MULTIPLY_SET_EQUAL,DIVIDE_SET_EQUAL,
				MODULUS_SET_EQUAL,LEFT_SHIFT_SET_EQUAL,RIGHT_SHIFT_SET_EQUAL,AND_SET_EQUAL,
				OR_SET_EQUAL,XOR_SET_EQUAL}OperatorID;

//Will be update when discuss with bing xuan group.
typedef enum {INVALID_INDENTIFIER,UNKNOWN_OPERATOR} Error;

//This structure store the converted version of string
typedef struct {
	char *rawString;
	int  startIndex;
	int length;	
}Tokenizer;

//Three type of token needed.
typedef struct {
	Token type;
	int value;
}Number;

typedef struct {
	Token type;
	OperatorID id;
}Operator;

typedef struct {
	Token type;
	char *name;
}Identifier;

int shuntingYard(char *expression);

int operatorEvaluate1(Stack *numStack , Stack *opeStack);

#endif // ShuntingYard_H
