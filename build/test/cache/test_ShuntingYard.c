#include "unity.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_calculateToken.h"
#include "mock_Stack.h"
#include "ShuntingYard.h"


void setUp(void){}

void tearDown(void){}



Stack numStack;

Stack opeStack;



void test_shunting_yard_should_return_0_if_the_expression_is_null(){

 int check;

 Tokenizer tokenizer = {.rawString = "0", .startIndex = 0, .length = 1};



 Number number2 = {.type= NUMBER, .value=0};

 Token *token1 = (Token*)&number2;



 initTokenizer_CMockExpectAndReturn(23, ((void *)0), &tokenizer);



 check=shuntingYard(((void *)0));

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

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



 Number answer = {.type=NUMBER, .value=5};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(47, "2+3", &tokenizer);



 getToken_CMockExpectAndReturn(49, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(50, token1, 1);

 stackPush_CMockExpect(51, token1, &numStack);



 getToken_CMockExpectAndReturn(53, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(54, token2, 0);

 isOperator_CMockExpectAndReturn(55, token2, 1);

 tryEvaluatethenPush_CMockExpect(56, token2, &numStack, &opeStack);

 stackPush_CMockExpect(57, token2, &opeStack);



 getToken_CMockExpectAndReturn(59, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(60, token3, 1);

 stackPush_CMockExpect(61, token3, &numStack);

 getToken_CMockExpectAndReturn(62, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(65, &numStack, &opeStack);











 shuntingYard("2+3");

}



void test_evaluate_2_PLUS_3_MULTIPLY_4(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2+3*4", .startIndex = 0, .length = 5};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Number answer = {.type=NUMBER, .value=14};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(98, "2+3*4", &tokenizer);



 getToken_CMockExpectAndReturn(100, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(101, token1, 1);

 stackPush_CMockExpect(102, token1, &numStack);



 getToken_CMockExpectAndReturn(104, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(105, token2, 0);

 isOperator_CMockExpectAndReturn(106, token2, 1);

 tryEvaluatethenPush_CMockExpect(107, token2, &numStack, &opeStack);

 stackPush_CMockExpect(108, token2, &opeStack);



 getToken_CMockExpectAndReturn(110, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(111, token3, 1);

 stackPush_CMockExpect(112, token3, &numStack);



 getToken_CMockExpectAndReturn(114, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(115, token4, 0);

 isOperator_CMockExpectAndReturn(116, token4, 1);

 tryEvaluatethenPush_CMockExpect(117, token4, &numStack, &opeStack);

 stackPush_CMockExpect(118, token4, &opeStack);



 getToken_CMockExpectAndReturn(120, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(121, token5, 1);

 stackPush_CMockExpect(122, token5, &numStack);

 getToken_CMockExpectAndReturn(123, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(125, &numStack, &opeStack);











 shuntingYard("2+3*4");

}



void test_evaluate_2_MULTIPLY_3_PLUS_4(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token2 = (Token*)&multiply;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Number answer = {.type=NUMBER, .value=10};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(158, "2*3+4", &tokenizer);



 getToken_CMockExpectAndReturn(160, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(161, token1, 1);

 stackPush_CMockExpect(162, token1, &numStack);



 getToken_CMockExpectAndReturn(164, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(165, token2, 0);

 isOperator_CMockExpectAndReturn(166, token2, 1);

 tryEvaluatethenPush_CMockExpect(167, token2, &numStack, &opeStack);

 stackPush_CMockExpect(168, token2, &opeStack);



 getToken_CMockExpectAndReturn(170, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(171, token3, 1);

 stackPush_CMockExpect(172, token3, &numStack);



 getToken_CMockExpectAndReturn(174, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(175, token4, 0);

 isOperator_CMockExpectAndReturn(176, token4, 1);

 tryEvaluatethenPush_CMockExpect(177, token4, &numStack, &opeStack);

 stackPush_CMockExpect(178, token4, &opeStack);



 getToken_CMockExpectAndReturn(180, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(181, token5, 1);

 stackPush_CMockExpect(182, token5, &numStack);

 getToken_CMockExpectAndReturn(183, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(185, &numStack, &opeStack);











 shuntingYard("2*3+4");

}



void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token4 = (Token*)&multiply;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Operator plus1 = {.type= OPERATOR, .id = ADD};

 Token *token6 = (Token*)&plus1;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token7 = (Token*)&number5;



 Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};

 Token *token8 = (Token*)&multiply1;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token9 = (Token*)&number6;



 Number answer = {.type=NUMBER, .value=44};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(230, "2+3*4+5*6", &tokenizer);



 getToken_CMockExpectAndReturn(232, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(233, token1, 1);

 stackPush_CMockExpect(234, token1, &numStack);



 getToken_CMockExpectAndReturn(236, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(237, token2, 0);

 isOperator_CMockExpectAndReturn(238, token2, 1);

 tryEvaluatethenPush_CMockExpect(239, token2, &numStack, &opeStack);

 stackPush_CMockExpect(240, token2, &opeStack);



 getToken_CMockExpectAndReturn(242, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(243, token3, 1);

 stackPush_CMockExpect(244, token3, &numStack);



 getToken_CMockExpectAndReturn(246, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(247, token4, 0);

 isOperator_CMockExpectAndReturn(248, token4, 1);

 tryEvaluatethenPush_CMockExpect(249, token4, &numStack, &opeStack);

 stackPush_CMockExpect(250, token4, &opeStack);



 getToken_CMockExpectAndReturn(252, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(253, token5, 1);

 stackPush_CMockExpect(254, token5, &numStack);



 getToken_CMockExpectAndReturn(256, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(257, token6, 0);

 isOperator_CMockExpectAndReturn(258, token6, 1);

 tryEvaluatethenPush_CMockExpect(259, token6, &numStack, &opeStack);

 stackPush_CMockExpect(260, token6, &opeStack);



 getToken_CMockExpectAndReturn(262, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(263, token7, 1);

 stackPush_CMockExpect(264, token7, &numStack);



 getToken_CMockExpectAndReturn(266, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(267, token8, 0);

 isOperator_CMockExpectAndReturn(268, token8, 1);

 tryEvaluatethenPush_CMockExpect(269, token8, &numStack, &opeStack);

 stackPush_CMockExpect(270, token8, &opeStack);



 getToken_CMockExpectAndReturn(272, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(273, token9, 1);

 stackPush_CMockExpect(274, token9, &numStack);

 getToken_CMockExpectAndReturn(275, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(277, &numStack, &opeStack);













 shuntingYard("2+3*4+5*6");

}



void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token2 = (Token*)&multiply;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};

 Token *token6 = (Token*)&multiply1;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token7 = (Token*)&number5;



 Operator plus1 = {.type= OPERATOR, .id = ADD};

 Token *token8 = (Token*)&plus1;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token9 = (Token*)&number6;



 Number answer = {.type=NUMBER, .value=32};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(323, "2*3+4*5+6", &tokenizer);



 getToken_CMockExpectAndReturn(325, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(326, token1, 1);

 stackPush_CMockExpect(327, token1, &numStack);



 getToken_CMockExpectAndReturn(329, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(330, token2, 0);

 isOperator_CMockExpectAndReturn(331, token2, 1);

 tryEvaluatethenPush_CMockExpect(332, token2, &numStack, &opeStack);

 stackPush_CMockExpect(333, token2, &opeStack);



 getToken_CMockExpectAndReturn(335, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(336, token3, 1);

 stackPush_CMockExpect(337, token3, &numStack);



 getToken_CMockExpectAndReturn(339, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(340, token4, 0);

 isOperator_CMockExpectAndReturn(341, token4, 1);

 tryEvaluatethenPush_CMockExpect(342, token4, &numStack, &opeStack);

 stackPush_CMockExpect(343, token4, &opeStack);



 getToken_CMockExpectAndReturn(345, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(346, token5, 1);

 stackPush_CMockExpect(347, token5, &numStack);



 getToken_CMockExpectAndReturn(349, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(350, token6, 0);

 isOperator_CMockExpectAndReturn(351, token6, 1);

 tryEvaluatethenPush_CMockExpect(352, token6, &numStack, &opeStack);

 stackPush_CMockExpect(353, token6, &opeStack);



 getToken_CMockExpectAndReturn(355, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(356, token7, 1);

 stackPush_CMockExpect(357, token7, &numStack);



 getToken_CMockExpectAndReturn(359, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(360, token8, 0);

 isOperator_CMockExpectAndReturn(361, token8, 1);

 tryEvaluatethenPush_CMockExpect(362, token8, &numStack, &opeStack);

 stackPush_CMockExpect(363, token8, &opeStack);



 getToken_CMockExpectAndReturn(365, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(366, token9, 1);

 stackPush_CMockExpect(367, token9, &numStack);

 getToken_CMockExpectAndReturn(368, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(370, &numStack, &opeStack);











 shuntingYard("2*3+4*5+6");



}



void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){

 Tokenizer tokenizer = {.rawString = "2|3+4*5-6-10", .startIndex = 0, .length = 11};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator OR = {.type= OPERATOR, .id = BITWISE_OR};

 Token *token2 = (Token*)&OR;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token6 = (Token*)&multiply;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token7 = (Token*)&number5;



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT};

 Token *token8 = (Token*)&subtract;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token9 = (Token*)&number6;



 Operator subtract1 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token10 = (Token*)&subtract1;



 Number number10 = {.type= NUMBER, .value=10};

 Token *token11 = (Token*)&number10;



 Number answer = {.type=NUMBER, .value=7};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(420, "2|3+4*5-6-10", &tokenizer);



 getToken_CMockExpectAndReturn(422, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(423, token1, 1);

 stackPush_CMockExpect(424, token1, &numStack);



 getToken_CMockExpectAndReturn(426, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(427, token2, 0);

 isOperator_CMockExpectAndReturn(428, token2, 1);

 tryEvaluatethenPush_CMockExpect(429, token2, &numStack, &opeStack);

 stackPush_CMockExpect(430, token2, &opeStack);



 getToken_CMockExpectAndReturn(432, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(433, token3, 1);

 stackPush_CMockExpect(434, token3, &numStack);



 getToken_CMockExpectAndReturn(436, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(437, token4, 0);

 isOperator_CMockExpectAndReturn(438, token4, 1);

 tryEvaluatethenPush_CMockExpect(439, token4, &numStack, &opeStack);

 stackPush_CMockExpect(440, token4, &opeStack);



 getToken_CMockExpectAndReturn(442, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(443, token5, 1);

 stackPush_CMockExpect(444, token5, &numStack);



 getToken_CMockExpectAndReturn(446, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(447, token6, 0);

 isOperator_CMockExpectAndReturn(448, token6, 1);

 tryEvaluatethenPush_CMockExpect(449, token6, &numStack, &opeStack);

 stackPush_CMockExpect(450, token6, &opeStack);



 getToken_CMockExpectAndReturn(452, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(453, token7, 1);

 stackPush_CMockExpect(454, token7, &numStack);



 getToken_CMockExpectAndReturn(456, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(457, token8, 0);

 isOperator_CMockExpectAndReturn(458, token8, 1);

 tryEvaluatethenPush_CMockExpect(459, token8, &numStack, &opeStack);

 stackPush_CMockExpect(460, token8, &opeStack);



 getToken_CMockExpectAndReturn(462, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(463, token9, 1);

 stackPush_CMockExpect(464, token9, &numStack);



 getToken_CMockExpectAndReturn(466, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(467, token10, 0);

 isOperator_CMockExpectAndReturn(468, token10, 1);

 tryEvaluatethenPush_CMockExpect(469, token10, &numStack, &opeStack);

 stackPush_CMockExpect(470, token10, &opeStack);



 getToken_CMockExpectAndReturn(472, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(473, token11, 1);

 stackPush_CMockExpect(474, token11, &numStack);

 getToken_CMockExpectAndReturn(475, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(477, &numStack, &opeStack);











 shuntingYard("2|3+4*5-6-10");



}



void test_LEFT_PARENTHESIS_2_PLUS_3_RIGHT_PARENTHESIS_MULTIPLY_4(void){

 Tokenizer tokenizer = {.rawString = "(2+3)*4", .startIndex = 0, .length = 7 };



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token1 = (Token*)&leftBracket;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token3 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token4 = (Token*)&number3;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token5 = (Token*)&rightBracket;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token6 = (Token*)&multiply;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token7 = (Token*)&number4;



 Number answer = {.type=NUMBER, .value=20};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(515, "(2+3)*4", &tokenizer);



 getToken_CMockExpectAndReturn(517, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(518, token1, 0);

 isOperator_CMockExpectAndReturn(519, token1, 1);

 tryEvaluatethenPush_CMockExpect(520, token1, &numStack, &opeStack);

 stackPush_CMockExpect(521, token1, &opeStack);



 getToken_CMockExpectAndReturn(523, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(524, token2, 1);

 stackPush_CMockExpect(525, token2, &numStack);



 getToken_CMockExpectAndReturn(527, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(528, token3, 0);

 isOperator_CMockExpectAndReturn(529, token3, 1);

 tryEvaluatethenPush_CMockExpect(530, token3, &numStack, &opeStack);

 stackPush_CMockExpect(531, token3, &opeStack);



 getToken_CMockExpectAndReturn(533, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(534, token4, 1);

 stackPush_CMockExpect(535, token4, &numStack);



 getToken_CMockExpectAndReturn(537, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(538, token5, 0);

 isOperator_CMockExpectAndReturn(539, token5, 1);

 tryEvaluatethenPush_CMockExpect(540, token5, &numStack, &opeStack);

 stackPush_CMockExpect(541, token5, &opeStack);



 getToken_CMockExpectAndReturn(543, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(544, token6, 0);

 isOperator_CMockExpectAndReturn(545, token6, 1);

 tryEvaluatethenPush_CMockExpect(546, token6, &numStack, &opeStack);

 stackPush_CMockExpect(547, token6, &opeStack);



 getToken_CMockExpectAndReturn(549, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(550, token7, 1);

 stackPush_CMockExpect(551, token7, &numStack);

 getToken_CMockExpectAndReturn(552, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(554, &numStack, &opeStack);











 shuntingYard("(2+3)*4");

}



void test_2_MULTIPLY_LEFT_PARENTHESIS_THREE_PLUS_FOUR_RIGHT_PARENTHESIS(void){

 Tokenizer tokenizer = {.rawString = "2*(3+4)", .startIndex = 0, .length = 7 };



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token2 = (Token*)&multiply;



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token3 = (Token*)&leftBracket;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token4 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token5 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token6 = (Token*)&number4;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token7 = (Token*)&rightBracket;



 Number answer = {.type=NUMBER, .value=14};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(591, "2*(3+4)", &tokenizer);



 getToken_CMockExpectAndReturn(593, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(594, token1, 1);

 stackPush_CMockExpect(595, token1, &numStack);



 getToken_CMockExpectAndReturn(597, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(598, token2, 0);

 isOperator_CMockExpectAndReturn(599, token2, 1);

 tryEvaluatethenPush_CMockExpect(600, token2, &numStack, &opeStack);

 stackPush_CMockExpect(601, token2, &opeStack);



 getToken_CMockExpectAndReturn(603, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(604, token3, 0);

 isOperator_CMockExpectAndReturn(605, token3, 1);

 tryEvaluatethenPush_CMockExpect(606, token3, &numStack, &opeStack);

 stackPush_CMockExpect(607, token3, &opeStack);



 getToken_CMockExpectAndReturn(609, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(610, token4, 1);

 stackPush_CMockExpect(611, token4, &numStack);



 getToken_CMockExpectAndReturn(613, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(614, token5, 0);

 isOperator_CMockExpectAndReturn(615, token5, 1);

 tryEvaluatethenPush_CMockExpect(616, token5, &numStack, &opeStack);

 stackPush_CMockExpect(617, token5, &opeStack);



 getToken_CMockExpectAndReturn(619, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(620, token6, 1);

 stackPush_CMockExpect(621, token6, &numStack);



 getToken_CMockExpectAndReturn(623, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(624, token7, 0);

 isOperator_CMockExpectAndReturn(625, token7, 1);

 tryEvaluatethenPush_CMockExpect(626, token7, &numStack, &opeStack);

 stackPush_CMockExpect(627, token7, &opeStack);

 getToken_CMockExpectAndReturn(628, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(630, &numStack, &opeStack);











 shuntingYard("2*(3+4)");

}



void test_NEGATIVE_2_SHOULD_RETURN_NEGATIVE_2(void){

 Tokenizer tokenizer = {.rawString = "-2", .startIndex = 0, .length = 2 };



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&subtract;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Number answer = {.type=NUMBER, .value=-2};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(652, "-2", &tokenizer);





 getToken_CMockExpectAndReturn(655, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(656, token1, 0);

 isOperator_CMockExpectAndReturn(657, token1, 1);

 tryEvaluatethenPush_CMockExpect(658, token1, &numStack, &opeStack);

 stackPush_CMockExpect(659, token1, &opeStack);





 getToken_CMockExpectAndReturn(662, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(663, token2, 1);

 stackPush_CMockExpect(664, token2, &numStack);

 getToken_CMockExpectAndReturn(665, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(668, &numStack, &opeStack);











 shuntingYard("-2");

}



void test_NEGATIVE_2_PLUS_NEGATIVE_3(void){

 Tokenizer tokenizer = {.rawString = "-2+-3", .startIndex = 0, .length = 5 };



 Operator negative = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&negative;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token3 = (Token*)&plus;



 Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token4 = (Token*)&negative2;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token5 = (Token*)&number3;



 Number answer = {.type=NUMBER, .value=-5};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(699, "-2+-3", &tokenizer);





 getToken_CMockExpectAndReturn(702, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(703, token1, 0);

 isOperator_CMockExpectAndReturn(704, token1, 1);

 tryEvaluatethenPush_CMockExpect(705, token1, &numStack, &opeStack);

 stackPush_CMockExpect(706, token1, &opeStack);





 getToken_CMockExpectAndReturn(709, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(710, token2, 1);

 stackPush_CMockExpect(711, token2, &numStack);





 getToken_CMockExpectAndReturn(714, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(715, token3, 0);

 isOperator_CMockExpectAndReturn(716, token3, 1);

 tryEvaluatethenPush_CMockExpect(717, token3, &numStack, &opeStack);

 stackPush_CMockExpect(718, token3, &opeStack);





 getToken_CMockExpectAndReturn(721, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(722, token4, 0);

 isOperator_CMockExpectAndReturn(723, token4, 1);

 tryEvaluatethenPush_CMockExpect(724, token4, &numStack, &opeStack);

 stackPush_CMockExpect(725, token4, &opeStack);





 getToken_CMockExpectAndReturn(728, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(729, token5, 1);

 stackPush_CMockExpect(730, token5, &numStack);

 getToken_CMockExpectAndReturn(731, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(734, &numStack, &opeStack);











 shuntingYard("-2+-3");

}



void test_NEGATIVE_NEGATIVE_NEGATIVE_NEGATIVE_NEGATIVE_2(void){

 Tokenizer tokenizer = {.rawString = "-----2", .startIndex = 0, .length = 6 };



 Operator negative = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&negative;



 Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token2 = (Token*)&negative2;



 Operator negative3 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token3 = (Token*)&negative3;



 Operator negative4 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token4 = (Token*)&negative4;



 Operator negative5 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token5 = (Token*)&negative5;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token6 = (Token*)&number2;



 Number answer = {.type=NUMBER, .value=-2};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(768, "-----2", &tokenizer);





 getToken_CMockExpectAndReturn(771, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(772, token1, 0);

 isOperator_CMockExpectAndReturn(773, token1, 1);

 tryEvaluatethenPush_CMockExpect(774, token1, &numStack, &opeStack);

 stackPush_CMockExpect(775, token1, &opeStack);





 getToken_CMockExpectAndReturn(778, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(779, token2, 0);

 isOperator_CMockExpectAndReturn(780, token2, 1);

 tryEvaluatethenPush_CMockExpect(781, token2, &numStack, &opeStack);

 stackPush_CMockExpect(782, token2, &opeStack);





 getToken_CMockExpectAndReturn(785, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(786, token3, 0);

 isOperator_CMockExpectAndReturn(787, token3, 1);

 tryEvaluatethenPush_CMockExpect(788, token3, &numStack, &opeStack);

 stackPush_CMockExpect(789, token3, &opeStack);





 getToken_CMockExpectAndReturn(792, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(793, token4, 0);

 isOperator_CMockExpectAndReturn(794, token4, 1);

 tryEvaluatethenPush_CMockExpect(795, token4, &numStack, &opeStack);

 stackPush_CMockExpect(796, token4, &opeStack);





 getToken_CMockExpectAndReturn(799, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(800, token5, 0);

 isOperator_CMockExpectAndReturn(801, token5, 1);

 tryEvaluatethenPush_CMockExpect(802, token5, &numStack, &opeStack);

 stackPush_CMockExpect(803, token5, &opeStack);





 getToken_CMockExpectAndReturn(806, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(807, token5, 1);

 stackPush_CMockExpect(808, token5, &numStack);

 getToken_CMockExpectAndReturn(809, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(812, &numStack, &opeStack);











 shuntingYard("-----2");



}



void test_LEFT_PARENTHESIS_10_MULTIPLY_100_RIGHT_PARENTHESIS_DIVIDE_BY_LEFT_PARENTHESIS_LEFT_PARENTHESIS_NEGATIVE_5_MULTIPLY_6_RIGHT_PARENTHESIS_SUBTRACT_LEFT_PARENTHESIS_2_MINUS_30_RIGHT_PARENTHESIS_RIGHT_PARENTHESIS(void) {

 Tokenizer tokenizer = {.rawString = "(10*100)/((-5*6)-(2-30))", .startIndex = 0, .length = 24 };



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token1 = (Token*)&leftBracket;



 Number number10 = {.type= NUMBER, .value=10};

 Token *token2 = (Token*)&number10;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token3 = (Token*)&multiply;



 Number number100 = {.type= NUMBER, .value=100};

 Token *token4 = (Token*)&number100;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token5 = (Token*)&rightBracket;



 Operator divide = {.type= OPERATOR, .id = DIVIDE};

 Token *token6 = (Token*)&divide;



 Operator leftBracket2 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token7 = (Token*)&leftBracket2;



 Operator leftBracket3 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token8 = (Token*)&leftBracket3;



 Operator negative = {.type= OPERATOR, .id = SUBTRACT};

 Token *token9 = (Token*)&negative;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token10 = (Token*)&number5;



 Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};

 Token *token11 = (Token*)&multiply1;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token12 = (Token*)&number6;



 Operator rightBracket1 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token13 = (Token*)&rightBracket1;



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT};

 Token *token14 = (Token*)&subtract;



 Operator leftBracket4 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token15 = (Token*)&leftBracket4;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token16 = (Token*)&number2;



 Operator subtract2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token17 = (Token*)&subtract2;



 Number number30 = {.type= NUMBER, .value=30};

 Token *token18 = (Token*)&number30;



 Operator rightBracket2 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token19 = (Token*)&rightBracket2;



 Operator rightBracket3 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token20 = (Token*)&rightBracket3;



 Number answer = {.type=NUMBER, .value=-500};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(889, "(10*100)/((-5*6)-(2-30))", &tokenizer);





 getToken_CMockExpectAndReturn(892, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(893, token1, 0);

 isOperator_CMockExpectAndReturn(894, token1, 1);

 tryEvaluatethenPush_CMockExpect(895, token1, &numStack, &opeStack);

 stackPush_CMockExpect(896, token1, &opeStack);





 getToken_CMockExpectAndReturn(899, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(900, token2, 1);

 stackPush_CMockExpect(901, token2, &numStack);





 getToken_CMockExpectAndReturn(904, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(905, token3, 0);

 isOperator_CMockExpectAndReturn(906, token3, 1);

 tryEvaluatethenPush_CMockExpect(907, token3, &numStack, &opeStack);

 stackPush_CMockExpect(908, token3, &opeStack);





 getToken_CMockExpectAndReturn(911, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(912, token4, 1);

 stackPush_CMockExpect(913, token4, &numStack);





 getToken_CMockExpectAndReturn(916, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(917, token5, 0);

 isOperator_CMockExpectAndReturn(918, token5, 1);

 tryEvaluatethenPush_CMockExpect(919, token5, &numStack, &opeStack);

 stackPush_CMockExpect(920, token5, &opeStack);





 getToken_CMockExpectAndReturn(923, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(924, token6, 0);

 isOperator_CMockExpectAndReturn(925, token6, 1);

 tryEvaluatethenPush_CMockExpect(926, token6, &numStack, &opeStack);

 stackPush_CMockExpect(927, token6, &opeStack);





 getToken_CMockExpectAndReturn(930, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(931, token7, 0);

 isOperator_CMockExpectAndReturn(932, token7, 1);

 tryEvaluatethenPush_CMockExpect(933, token7, &numStack, &opeStack);

 stackPush_CMockExpect(934, token7, &opeStack);





 getToken_CMockExpectAndReturn(937, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(938, token8, 0);

 isOperator_CMockExpectAndReturn(939, token8, 1);

 tryEvaluatethenPush_CMockExpect(940, token8, &numStack, &opeStack);

 stackPush_CMockExpect(941, token8, &opeStack);





 getToken_CMockExpectAndReturn(944, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(945, token9, 0);

 isOperator_CMockExpectAndReturn(946, token9, 1);

 tryEvaluatethenPush_CMockExpect(947, token9, &numStack, &opeStack);

 stackPush_CMockExpect(948, token9, &opeStack);





 getToken_CMockExpectAndReturn(951, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(952, token10, 1);

 stackPush_CMockExpect(953, token10, &numStack);





 getToken_CMockExpectAndReturn(956, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(957, token11, 0);

 isOperator_CMockExpectAndReturn(958, token11, 1);

 tryEvaluatethenPush_CMockExpect(959, token11, &numStack, &opeStack);

 stackPush_CMockExpect(960, token11, &opeStack);





 getToken_CMockExpectAndReturn(963, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(964, token12, 1);

 stackPush_CMockExpect(965, token12, &numStack);





 getToken_CMockExpectAndReturn(968, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(969, token13, 0);

 isOperator_CMockExpectAndReturn(970, token13, 1);

 tryEvaluatethenPush_CMockExpect(971, token13, &numStack, &opeStack);

 stackPush_CMockExpect(972, token13, &opeStack);





 getToken_CMockExpectAndReturn(975, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(976, token14, 0);

 isOperator_CMockExpectAndReturn(977, token14, 1);

 tryEvaluatethenPush_CMockExpect(978, token14, &numStack, &opeStack);

 stackPush_CMockExpect(979, token14, &opeStack);





 getToken_CMockExpectAndReturn(982, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(983, token15, 0);

 isOperator_CMockExpectAndReturn(984, token15, 1);

 tryEvaluatethenPush_CMockExpect(985, token15, &numStack, &opeStack);

 stackPush_CMockExpect(986, token15, &opeStack);





 getToken_CMockExpectAndReturn(989, &tokenizer, token16);

 isNumber_CMockExpectAndReturn(990, token16, 1);

 stackPush_CMockExpect(991, token16, &numStack);





 getToken_CMockExpectAndReturn(994, &tokenizer, token17);

 isNumber_CMockExpectAndReturn(995, token17, 0);

 isOperator_CMockExpectAndReturn(996, token17, 1);

 tryEvaluatethenPush_CMockExpect(997, token17, &numStack, &opeStack);

 stackPush_CMockExpect(998, token17, &opeStack);





 getToken_CMockExpectAndReturn(1001, &tokenizer, token18);

 isNumber_CMockExpectAndReturn(1002, token18, 1);

 stackPush_CMockExpect(1003, token18, &numStack);





 getToken_CMockExpectAndReturn(1006, &tokenizer, token19);

 isNumber_CMockExpectAndReturn(1007, token19, 0);

 isOperator_CMockExpectAndReturn(1008, token19, 1);

 tryEvaluatethenPush_CMockExpect(1009, token19, &numStack, &opeStack);

 stackPush_CMockExpect(1010, token19, &opeStack);





 getToken_CMockExpectAndReturn(1013, &tokenizer, token20);

 isNumber_CMockExpectAndReturn(1014, token20, 0);

 isOperator_CMockExpectAndReturn(1015, token20, 1);

 tryEvaluatethenPush_CMockExpect(1016, token20, &numStack, &opeStack);

 stackPush_CMockExpect(1017, token20, &opeStack);

 getToken_CMockExpectAndReturn(1018, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1021, &numStack, &opeStack);











 shuntingYard("(10*100)/((-5*6)-(2-30))");

}



void test_NEGATIVE_LEFT_PARENTHESIS_NEGATIVE_2_RIGHT_PARENTHESIS(void){

 Tokenizer tokenizer = {.rawString = "-(-2)", .startIndex = 0, .length = 5 };



 Operator negative = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&negative;



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token2 = (Token*)&leftBracket;



 Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token3 = (Token*)&negative2;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token4 = (Token*)&number2;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token5 = (Token*)&rightBracket;



 Number answer = {.type=NUMBER, .value=2};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(1052, "-(-2)", &tokenizer);





 getToken_CMockExpectAndReturn(1055, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1056, token1, 0);

 isOperator_CMockExpectAndReturn(1057, token1, 1);

 tryEvaluatethenPush_CMockExpect(1058, token1, &numStack, &opeStack);

 stackPush_CMockExpect(1059, token1, &opeStack);





 getToken_CMockExpectAndReturn(1062, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1063, token2, 0);

 isOperator_CMockExpectAndReturn(1064, token2, 1);

 tryEvaluatethenPush_CMockExpect(1065, token2, &numStack, &opeStack);

 stackPush_CMockExpect(1066, token2, &opeStack);





 getToken_CMockExpectAndReturn(1069, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1070, token3, 0);

 isOperator_CMockExpectAndReturn(1071, token3, 1);

 tryEvaluatethenPush_CMockExpect(1072, token3, &numStack, &opeStack);

 stackPush_CMockExpect(1073, token3, &opeStack);





 getToken_CMockExpectAndReturn(1076, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1077, token4, 1);

 stackPush_CMockExpect(1078, token4, &numStack);





 getToken_CMockExpectAndReturn(1081, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1082, token5, 0);

 isOperator_CMockExpectAndReturn(1083, token5, 1);

 tryEvaluatethenPush_CMockExpect(1084, token5, &numStack, &opeStack);

 stackPush_CMockExpect(1085, token5, &opeStack);

 getToken_CMockExpectAndReturn(1086, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1089, &numStack, &opeStack);











 shuntingYard("-(-2)");





}



void test_NEGATIVE_LEFT_PARENTHESIS_POSITIVE_LEFT_PARENTHESIS_NEGATIVE_LEFT_PARENTHESIS__NEGATIVE_1_RIGHT_PARENTHESIS_MULTIPLY_3_RIGHT_PARENTHESIS_SUBTRACT_FOUR_RIGHT_PARENTHESIS(void){

 Tokenizer tokenizer = {.rawString = "-(+(-(-1)*3)-4)", .startIndex = 0, .length = 15 };



 Operator negative = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&negative;



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token2 = (Token*)&leftBracket;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token3 = (Token*)&plus;



 Operator leftBracket2 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token4 = (Token*)&leftBracket2;



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT};

 Token *token5 = (Token*)&subtract;



 Operator leftBracket3 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token6 = (Token*)&leftBracket3;



 Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token7 = (Token*)&negative2;



 Number number1 = {.type= NUMBER, .value=1};

 Token *token8 = (Token*)&number1;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token9 = (Token*)&rightBracket;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token10 = (Token*)&multiply;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token11 = (Token*)&number3;



 Operator rightBracket1 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token12 = (Token*)&rightBracket1;



 Operator subtract2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token13 = (Token*)&subtract2;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token14 = (Token*)&number4;



 Operator rightBracket2 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token15 = (Token*)&rightBracket2;



 Number answer = {.type=NUMBER, .value=1};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(1152, "-(+(-(-1)*3)-4)", &tokenizer);





 getToken_CMockExpectAndReturn(1155, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1156, token1, 0);

 isOperator_CMockExpectAndReturn(1157, token1, 1);

 tryEvaluatethenPush_CMockExpect(1158, token1, &numStack, &opeStack);

 stackPush_CMockExpect(1159, token1, &opeStack);





 getToken_CMockExpectAndReturn(1162, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1163, token2, 0);

 isOperator_CMockExpectAndReturn(1164, token2, 1);

 tryEvaluatethenPush_CMockExpect(1165, token2, &numStack, &opeStack);

 stackPush_CMockExpect(1166, token2, &opeStack);





 getToken_CMockExpectAndReturn(1169, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1170, token3, 0);

 isOperator_CMockExpectAndReturn(1171, token3, 1);

 tryEvaluatethenPush_CMockExpect(1172, token3, &numStack, &opeStack);

 stackPush_CMockExpect(1173, token3, &opeStack);





 getToken_CMockExpectAndReturn(1176, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1177, token4, 0);

 isOperator_CMockExpectAndReturn(1178, token4, 1);

 tryEvaluatethenPush_CMockExpect(1179, token4, &numStack, &opeStack);

 stackPush_CMockExpect(1180, token4, &opeStack);





 getToken_CMockExpectAndReturn(1183, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1184, token5, 0);

 isOperator_CMockExpectAndReturn(1185, token5, 1);

 tryEvaluatethenPush_CMockExpect(1186, token5, &numStack, &opeStack);

 stackPush_CMockExpect(1187, token5, &opeStack);





 getToken_CMockExpectAndReturn(1190, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(1191, token6, 0);

 isOperator_CMockExpectAndReturn(1192, token6, 1);

 tryEvaluatethenPush_CMockExpect(1193, token6, &numStack, &opeStack);

 stackPush_CMockExpect(1194, token6, &opeStack);





 getToken_CMockExpectAndReturn(1197, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(1198, token7, 0);

 isOperator_CMockExpectAndReturn(1199, token7, 1);

 tryEvaluatethenPush_CMockExpect(1200, token7, &numStack, &opeStack);

 stackPush_CMockExpect(1201, token7, &opeStack);





 getToken_CMockExpectAndReturn(1204, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(1205, token8, 1);

 stackPush_CMockExpect(1206, token8, &numStack);





 getToken_CMockExpectAndReturn(1209, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(1210, token9, 0);

 isOperator_CMockExpectAndReturn(1211, token9, 1);

 tryEvaluatethenPush_CMockExpect(1212, token9, &numStack, &opeStack);

 stackPush_CMockExpect(1213, token9, &opeStack);





 getToken_CMockExpectAndReturn(1216, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(1217, token10, 0);

 isOperator_CMockExpectAndReturn(1218, token10, 1);

 tryEvaluatethenPush_CMockExpect(1219, token10, &numStack, &opeStack);

 stackPush_CMockExpect(1220, token10, &opeStack);





 getToken_CMockExpectAndReturn(1223, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(1224, token11, 1);

 stackPush_CMockExpect(1225, token11, &numStack);





 getToken_CMockExpectAndReturn(1228, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(1229, token12, 0);

 isOperator_CMockExpectAndReturn(1230, token12, 1);

 tryEvaluatethenPush_CMockExpect(1231, token12, &numStack, &opeStack);

 stackPush_CMockExpect(1232, token12, &opeStack);





 getToken_CMockExpectAndReturn(1235, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(1236, token13, 0);

 isOperator_CMockExpectAndReturn(1237, token13, 1);

 tryEvaluatethenPush_CMockExpect(1238, token13, &numStack, &opeStack);

 stackPush_CMockExpect(1239, token13, &opeStack);





 getToken_CMockExpectAndReturn(1242, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(1243, token14, 1);

 stackPush_CMockExpect(1244, token14, &numStack);





 getToken_CMockExpectAndReturn(1247, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(1248, token15, 0);

 isOperator_CMockExpectAndReturn(1249, token15, 1);

 tryEvaluatethenPush_CMockExpect(1250, token15, &numStack, &opeStack);

 stackPush_CMockExpect(1251, token15, &opeStack);

 getToken_CMockExpectAndReturn(1252, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1255, &numStack, &opeStack);



 shuntingYard("-(+(-(-1)*3)-4)");

}



void test_operator_evaluate_should_calculate_2_PLUS_3(void){



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Number answer = {.type=NUMBER, .value=5};

 Token *ansToken = (Token*)&answer;



 stackPop_CMockExpectAndReturn(1274, &opeStack, token2);

 stackPop_CMockExpectAndReturn(1275, &numStack, token1);

 stackPop_CMockExpectAndReturn(1276, &numStack, token3);

 calculate_CMockExpectAndReturn(1277, &plus, &number2, &number3, ansToken);

 stackPush_CMockExpect(1278, ansToken, &numStack);





 operatorEvaluate1(&numStack,&opeStack);

}
