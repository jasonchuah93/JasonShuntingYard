#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "initializeToken.h"
#include "getToken.h"

/*
	This function will generate a Token from a number.
	
	input :
	number				Carry the number that going to store in a Token.
	
	output:
	none
	
	return:
	(Token*)newToken	The token that generated.
*/

Token *createNumberToken(int number)
{
	Number *newToken = malloc (sizeof(Number));
	newToken->type = NUMBER;
	newToken->value=number;
	
	return (Token*)newToken;
}
