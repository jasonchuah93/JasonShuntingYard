#ifndef EVALUATE_H
#define EVALUATE_H

#include "Stack.h"
#include "stackForEvaluate.h"

typedef enum {NUMBER,OPERATOR,IDENTIFIER}Token;
//Updating in progress, please be patient.....
typedef enum {XOR_SET_EQUAL,OR_SET_EQUAL,AND_SET_EQUAL,RIGHT_SHIFT_SET_EQUAL,
				LEFT_SHIFT_SET_EQUAL,MODULUS_SET_EQUAL,DIVIDE_SET_EQUAL,
				MULTIPLY_SET_EQUAL,SUBTRACT_SET_EQUAL,ADD_SET_EQUAL,EQUAL,
				LOGICAL_OR,LOGICAL_AND,BITWISE_OR,BITWISE_XOR,BITWISE_AND,
				NOT_EQUAL,EQUAL_TO,LESS_EQUAL_THAN,LESS_THAN,GREATER_THAN,
				GREATER_EQUAL_THAN,RIGHT_SHIFT,LEFT_SHIFT,SUBTRACT,ADD,MODULUS,
				DIVIDE,MULTIPLY,UPPER,HIGH,LOW,COMPLEMENT,LOGIC_NOT,LEFT_PARENTHESIS,
				RIGHT_PARENTHESIS,CURRENT_PROGRAM_COUNTER}OperatorID;

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

void operatorEvaluate1(Stack *numStack , Stack *opeStack);

#endif // EVALUATE_H
