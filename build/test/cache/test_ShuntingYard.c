#include "unity.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
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



 initTokenizer_CMockExpectAndReturn(22, ((void *)0), &tokenizer);



 check=shuntingYard(((void *)0));

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

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





 initTokenizer_CMockExpectAndReturn(46, "2+3", &tokenizer);



 getToken_CMockExpectAndReturn(48, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(49, token1, 1);

 stackPush_CMockExpect(50, token1, &numStack);



 getToken_CMockExpectAndReturn(52, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(53, token2, 0);

 isOperator_CMockExpectAndReturn(54, token2, 1);

 tryEvaluatethenPush_CMockExpect(55, token2, &numStack, &opeStack);

 stackPush_CMockExpect(56, token2, &opeStack);



 getToken_CMockExpectAndReturn(58, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(59, token3, 1);

 stackPush_CMockExpect(60, token3, &numStack);

 getToken_CMockExpectAndReturn(61, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(64, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(97, "2+3*4", &tokenizer);



 getToken_CMockExpectAndReturn(99, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(100, token1, 1);

 stackPush_CMockExpect(101, token1, &numStack);



 getToken_CMockExpectAndReturn(103, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(104, token2, 0);

 isOperator_CMockExpectAndReturn(105, token2, 1);

 tryEvaluatethenPush_CMockExpect(106, token2, &numStack, &opeStack);

 stackPush_CMockExpect(107, token2, &opeStack);



 getToken_CMockExpectAndReturn(109, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(110, token3, 1);

 stackPush_CMockExpect(111, token3, &numStack);



 getToken_CMockExpectAndReturn(113, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(114, token4, 0);

 isOperator_CMockExpectAndReturn(115, token4, 1);

 tryEvaluatethenPush_CMockExpect(116, token4, &numStack, &opeStack);

 stackPush_CMockExpect(117, token4, &opeStack);



 getToken_CMockExpectAndReturn(119, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(120, token5, 1);

 stackPush_CMockExpect(121, token5, &numStack);

 getToken_CMockExpectAndReturn(122, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(124, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(157, "2*3+4", &tokenizer);



 getToken_CMockExpectAndReturn(159, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(160, token1, 1);

 stackPush_CMockExpect(161, token1, &numStack);



 getToken_CMockExpectAndReturn(163, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(164, token2, 0);

 isOperator_CMockExpectAndReturn(165, token2, 1);

 tryEvaluatethenPush_CMockExpect(166, token2, &numStack, &opeStack);

 stackPush_CMockExpect(167, token2, &opeStack);



 getToken_CMockExpectAndReturn(169, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(170, token3, 1);

 stackPush_CMockExpect(171, token3, &numStack);



 getToken_CMockExpectAndReturn(173, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(174, token4, 0);

 isOperator_CMockExpectAndReturn(175, token4, 1);

 tryEvaluatethenPush_CMockExpect(176, token4, &numStack, &opeStack);

 stackPush_CMockExpect(177, token4, &opeStack);



 getToken_CMockExpectAndReturn(179, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(180, token5, 1);

 stackPush_CMockExpect(181, token5, &numStack);

 getToken_CMockExpectAndReturn(182, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(184, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(229, "2+3*4+5*6", &tokenizer);



 getToken_CMockExpectAndReturn(231, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(232, token1, 1);

 stackPush_CMockExpect(233, token1, &numStack);



 getToken_CMockExpectAndReturn(235, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(236, token2, 0);

 isOperator_CMockExpectAndReturn(237, token2, 1);

 tryEvaluatethenPush_CMockExpect(238, token2, &numStack, &opeStack);

 stackPush_CMockExpect(239, token2, &opeStack);



 getToken_CMockExpectAndReturn(241, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(242, token3, 1);

 stackPush_CMockExpect(243, token3, &numStack);



 getToken_CMockExpectAndReturn(245, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(246, token4, 0);

 isOperator_CMockExpectAndReturn(247, token4, 1);

 tryEvaluatethenPush_CMockExpect(248, token4, &numStack, &opeStack);

 stackPush_CMockExpect(249, token4, &opeStack);



 getToken_CMockExpectAndReturn(251, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(252, token5, 1);

 stackPush_CMockExpect(253, token5, &numStack);



 getToken_CMockExpectAndReturn(255, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(256, token6, 0);

 isOperator_CMockExpectAndReturn(257, token6, 1);

 tryEvaluatethenPush_CMockExpect(258, token6, &numStack, &opeStack);

 stackPush_CMockExpect(259, token6, &opeStack);



 getToken_CMockExpectAndReturn(261, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(262, token7, 1);

 stackPush_CMockExpect(263, token7, &numStack);



 getToken_CMockExpectAndReturn(265, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(266, token8, 0);

 isOperator_CMockExpectAndReturn(267, token8, 1);

 tryEvaluatethenPush_CMockExpect(268, token8, &numStack, &opeStack);

 stackPush_CMockExpect(269, token8, &opeStack);



 getToken_CMockExpectAndReturn(271, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(272, token9, 1);

 stackPush_CMockExpect(273, token9, &numStack);

 getToken_CMockExpectAndReturn(274, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(276, &numStack, &opeStack);













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





 initTokenizer_CMockExpectAndReturn(322, "2*3+4*5+6", &tokenizer);



 getToken_CMockExpectAndReturn(324, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(325, token1, 1);

 stackPush_CMockExpect(326, token1, &numStack);



 getToken_CMockExpectAndReturn(328, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(329, token2, 0);

 isOperator_CMockExpectAndReturn(330, token2, 1);

 tryEvaluatethenPush_CMockExpect(331, token2, &numStack, &opeStack);

 stackPush_CMockExpect(332, token2, &opeStack);



 getToken_CMockExpectAndReturn(334, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(335, token3, 1);

 stackPush_CMockExpect(336, token3, &numStack);



 getToken_CMockExpectAndReturn(338, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(339, token4, 0);

 isOperator_CMockExpectAndReturn(340, token4, 1);

 tryEvaluatethenPush_CMockExpect(341, token4, &numStack, &opeStack);

 stackPush_CMockExpect(342, token4, &opeStack);



 getToken_CMockExpectAndReturn(344, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(345, token5, 1);

 stackPush_CMockExpect(346, token5, &numStack);



 getToken_CMockExpectAndReturn(348, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(349, token6, 0);

 isOperator_CMockExpectAndReturn(350, token6, 1);

 tryEvaluatethenPush_CMockExpect(351, token6, &numStack, &opeStack);

 stackPush_CMockExpect(352, token6, &opeStack);



 getToken_CMockExpectAndReturn(354, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(355, token7, 1);

 stackPush_CMockExpect(356, token7, &numStack);



 getToken_CMockExpectAndReturn(358, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(359, token8, 0);

 isOperator_CMockExpectAndReturn(360, token8, 1);

 tryEvaluatethenPush_CMockExpect(361, token8, &numStack, &opeStack);

 stackPush_CMockExpect(362, token8, &opeStack);



 getToken_CMockExpectAndReturn(364, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(365, token9, 1);

 stackPush_CMockExpect(366, token9, &numStack);

 getToken_CMockExpectAndReturn(367, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(369, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(419, "2|3+4*5-6-10", &tokenizer);



 getToken_CMockExpectAndReturn(421, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(422, token1, 1);

 stackPush_CMockExpect(423, token1, &numStack);



 getToken_CMockExpectAndReturn(425, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(426, token2, 0);

 isOperator_CMockExpectAndReturn(427, token2, 1);

 tryEvaluatethenPush_CMockExpect(428, token2, &numStack, &opeStack);

 stackPush_CMockExpect(429, token2, &opeStack);



 getToken_CMockExpectAndReturn(431, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(432, token3, 1);

 stackPush_CMockExpect(433, token3, &numStack);



 getToken_CMockExpectAndReturn(435, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(436, token4, 0);

 isOperator_CMockExpectAndReturn(437, token4, 1);

 tryEvaluatethenPush_CMockExpect(438, token4, &numStack, &opeStack);

 stackPush_CMockExpect(439, token4, &opeStack);



 getToken_CMockExpectAndReturn(441, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(442, token5, 1);

 stackPush_CMockExpect(443, token5, &numStack);



 getToken_CMockExpectAndReturn(445, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(446, token6, 0);

 isOperator_CMockExpectAndReturn(447, token6, 1);

 tryEvaluatethenPush_CMockExpect(448, token6, &numStack, &opeStack);

 stackPush_CMockExpect(449, token6, &opeStack);



 getToken_CMockExpectAndReturn(451, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(452, token7, 1);

 stackPush_CMockExpect(453, token7, &numStack);



 getToken_CMockExpectAndReturn(455, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(456, token8, 0);

 isOperator_CMockExpectAndReturn(457, token8, 1);

 tryEvaluatethenPush_CMockExpect(458, token8, &numStack, &opeStack);

 stackPush_CMockExpect(459, token8, &opeStack);



 getToken_CMockExpectAndReturn(461, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(462, token9, 1);

 stackPush_CMockExpect(463, token9, &numStack);



 getToken_CMockExpectAndReturn(465, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(466, token10, 0);

 isOperator_CMockExpectAndReturn(467, token10, 1);

 tryEvaluatethenPush_CMockExpect(468, token10, &numStack, &opeStack);

 stackPush_CMockExpect(469, token10, &opeStack);



 getToken_CMockExpectAndReturn(471, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(472, token11, 1);

 stackPush_CMockExpect(473, token11, &numStack);

 getToken_CMockExpectAndReturn(474, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(476, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(514, "(2+3)*4", &tokenizer);



 getToken_CMockExpectAndReturn(516, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(517, token1, 0);

 isOperator_CMockExpectAndReturn(518, token1, 1);

 tryEvaluatethenPush_CMockExpect(519, token1, &numStack, &opeStack);

 stackPush_CMockExpect(520, token1, &opeStack);



 getToken_CMockExpectAndReturn(522, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(523, token2, 1);

 stackPush_CMockExpect(524, token2, &numStack);



 getToken_CMockExpectAndReturn(526, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(527, token3, 0);

 isOperator_CMockExpectAndReturn(528, token3, 1);

 tryEvaluatethenPush_CMockExpect(529, token3, &numStack, &opeStack);

 stackPush_CMockExpect(530, token3, &opeStack);



 getToken_CMockExpectAndReturn(532, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(533, token4, 1);

 stackPush_CMockExpect(534, token4, &numStack);



 getToken_CMockExpectAndReturn(536, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(537, token5, 0);

 isOperator_CMockExpectAndReturn(538, token5, 1);

 tryEvaluatethenPush_CMockExpect(539, token5, &numStack, &opeStack);

 stackPush_CMockExpect(540, token5, &opeStack);



 getToken_CMockExpectAndReturn(542, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(543, token6, 0);

 isOperator_CMockExpectAndReturn(544, token6, 1);

 tryEvaluatethenPush_CMockExpect(545, token6, &numStack, &opeStack);

 stackPush_CMockExpect(546, token6, &opeStack);



 getToken_CMockExpectAndReturn(548, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(549, token7, 1);

 stackPush_CMockExpect(550, token7, &numStack);

 getToken_CMockExpectAndReturn(551, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(553, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(590, "2*(3+4)", &tokenizer);



 getToken_CMockExpectAndReturn(592, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(593, token1, 1);

 stackPush_CMockExpect(594, token1, &numStack);



 getToken_CMockExpectAndReturn(596, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(597, token2, 0);

 isOperator_CMockExpectAndReturn(598, token2, 1);

 tryEvaluatethenPush_CMockExpect(599, token2, &numStack, &opeStack);

 stackPush_CMockExpect(600, token2, &opeStack);



 getToken_CMockExpectAndReturn(602, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(603, token3, 0);

 isOperator_CMockExpectAndReturn(604, token3, 1);

 tryEvaluatethenPush_CMockExpect(605, token3, &numStack, &opeStack);

 stackPush_CMockExpect(606, token3, &opeStack);



 getToken_CMockExpectAndReturn(608, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(609, token4, 1);

 stackPush_CMockExpect(610, token4, &numStack);



 getToken_CMockExpectAndReturn(612, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(613, token5, 0);

 isOperator_CMockExpectAndReturn(614, token5, 1);

 tryEvaluatethenPush_CMockExpect(615, token5, &numStack, &opeStack);

 stackPush_CMockExpect(616, token5, &opeStack);



 getToken_CMockExpectAndReturn(618, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(619, token6, 1);

 stackPush_CMockExpect(620, token6, &numStack);



 getToken_CMockExpectAndReturn(622, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(623, token7, 0);

 isOperator_CMockExpectAndReturn(624, token7, 1);

 tryEvaluatethenPush_CMockExpect(625, token7, &numStack, &opeStack);

 stackPush_CMockExpect(626, token7, &opeStack);

 getToken_CMockExpectAndReturn(627, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(629, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(651, "-2", &tokenizer);





 getToken_CMockExpectAndReturn(654, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(655, token1, 0);

 isOperator_CMockExpectAndReturn(656, token1, 1);

 tryEvaluatethenPush_CMockExpect(657, token1, &numStack, &opeStack);

 stackPush_CMockExpect(658, token1, &opeStack);





 getToken_CMockExpectAndReturn(661, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(662, token2, 1);

 stackPush_CMockExpect(663, token2, &numStack);

 getToken_CMockExpectAndReturn(664, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(667, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(698, "-2+-3", &tokenizer);





 getToken_CMockExpectAndReturn(701, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(702, token1, 0);

 isOperator_CMockExpectAndReturn(703, token1, 1);

 tryEvaluatethenPush_CMockExpect(704, token1, &numStack, &opeStack);

 stackPush_CMockExpect(705, token1, &opeStack);





 getToken_CMockExpectAndReturn(708, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(709, token2, 1);

 stackPush_CMockExpect(710, token2, &numStack);





 getToken_CMockExpectAndReturn(713, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(714, token3, 0);

 isOperator_CMockExpectAndReturn(715, token3, 1);

 tryEvaluatethenPush_CMockExpect(716, token3, &numStack, &opeStack);

 stackPush_CMockExpect(717, token3, &opeStack);





 getToken_CMockExpectAndReturn(720, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(721, token4, 0);

 isOperator_CMockExpectAndReturn(722, token4, 1);

 tryEvaluatethenPush_CMockExpect(723, token4, &numStack, &opeStack);

 stackPush_CMockExpect(724, token4, &opeStack);





 getToken_CMockExpectAndReturn(727, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(728, token5, 1);

 stackPush_CMockExpect(729, token5, &numStack);

 getToken_CMockExpectAndReturn(730, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(733, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(767, "-----2", &tokenizer);





 getToken_CMockExpectAndReturn(770, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(771, token1, 0);

 isOperator_CMockExpectAndReturn(772, token1, 1);

 tryEvaluatethenPush_CMockExpect(773, token1, &numStack, &opeStack);

 stackPush_CMockExpect(774, token1, &opeStack);





 getToken_CMockExpectAndReturn(777, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(778, token2, 0);

 isOperator_CMockExpectAndReturn(779, token2, 1);

 tryEvaluatethenPush_CMockExpect(780, token2, &numStack, &opeStack);

 stackPush_CMockExpect(781, token2, &opeStack);





 getToken_CMockExpectAndReturn(784, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(785, token3, 0);

 isOperator_CMockExpectAndReturn(786, token3, 1);

 tryEvaluatethenPush_CMockExpect(787, token3, &numStack, &opeStack);

 stackPush_CMockExpect(788, token3, &opeStack);





 getToken_CMockExpectAndReturn(791, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(792, token4, 0);

 isOperator_CMockExpectAndReturn(793, token4, 1);

 tryEvaluatethenPush_CMockExpect(794, token4, &numStack, &opeStack);

 stackPush_CMockExpect(795, token4, &opeStack);





 getToken_CMockExpectAndReturn(798, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(799, token5, 0);

 isOperator_CMockExpectAndReturn(800, token5, 1);

 tryEvaluatethenPush_CMockExpect(801, token5, &numStack, &opeStack);

 stackPush_CMockExpect(802, token5, &opeStack);





 getToken_CMockExpectAndReturn(805, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(806, token5, 1);

 stackPush_CMockExpect(807, token5, &numStack);

 getToken_CMockExpectAndReturn(808, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(811, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(888, "(10*100)/((-5*6)-(2-30))", &tokenizer);





 getToken_CMockExpectAndReturn(891, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(892, token1, 0);

 isOperator_CMockExpectAndReturn(893, token1, 1);

 tryEvaluatethenPush_CMockExpect(894, token1, &numStack, &opeStack);

 stackPush_CMockExpect(895, token1, &opeStack);





 getToken_CMockExpectAndReturn(898, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(899, token2, 1);

 stackPush_CMockExpect(900, token2, &numStack);





 getToken_CMockExpectAndReturn(903, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(904, token3, 0);

 isOperator_CMockExpectAndReturn(905, token3, 1);

 tryEvaluatethenPush_CMockExpect(906, token3, &numStack, &opeStack);

 stackPush_CMockExpect(907, token3, &opeStack);





 getToken_CMockExpectAndReturn(910, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(911, token4, 1);

 stackPush_CMockExpect(912, token4, &numStack);





 getToken_CMockExpectAndReturn(915, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(916, token5, 0);

 isOperator_CMockExpectAndReturn(917, token5, 1);

 tryEvaluatethenPush_CMockExpect(918, token5, &numStack, &opeStack);

 stackPush_CMockExpect(919, token5, &opeStack);





 getToken_CMockExpectAndReturn(922, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(923, token6, 0);

 isOperator_CMockExpectAndReturn(924, token6, 1);

 tryEvaluatethenPush_CMockExpect(925, token6, &numStack, &opeStack);

 stackPush_CMockExpect(926, token6, &opeStack);





 getToken_CMockExpectAndReturn(929, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(930, token7, 0);

 isOperator_CMockExpectAndReturn(931, token7, 1);

 tryEvaluatethenPush_CMockExpect(932, token7, &numStack, &opeStack);

 stackPush_CMockExpect(933, token7, &opeStack);





 getToken_CMockExpectAndReturn(936, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(937, token8, 0);

 isOperator_CMockExpectAndReturn(938, token8, 1);

 tryEvaluatethenPush_CMockExpect(939, token8, &numStack, &opeStack);

 stackPush_CMockExpect(940, token8, &opeStack);





 getToken_CMockExpectAndReturn(943, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(944, token9, 0);

 isOperator_CMockExpectAndReturn(945, token9, 1);

 tryEvaluatethenPush_CMockExpect(946, token9, &numStack, &opeStack);

 stackPush_CMockExpect(947, token9, &opeStack);





 getToken_CMockExpectAndReturn(950, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(951, token10, 1);

 stackPush_CMockExpect(952, token10, &numStack);





 getToken_CMockExpectAndReturn(955, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(956, token11, 0);

 isOperator_CMockExpectAndReturn(957, token11, 1);

 tryEvaluatethenPush_CMockExpect(958, token11, &numStack, &opeStack);

 stackPush_CMockExpect(959, token11, &opeStack);





 getToken_CMockExpectAndReturn(962, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(963, token12, 1);

 stackPush_CMockExpect(964, token12, &numStack);





 getToken_CMockExpectAndReturn(967, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(968, token13, 0);

 isOperator_CMockExpectAndReturn(969, token13, 1);

 tryEvaluatethenPush_CMockExpect(970, token13, &numStack, &opeStack);

 stackPush_CMockExpect(971, token13, &opeStack);





 getToken_CMockExpectAndReturn(974, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(975, token14, 0);

 isOperator_CMockExpectAndReturn(976, token14, 1);

 tryEvaluatethenPush_CMockExpect(977, token14, &numStack, &opeStack);

 stackPush_CMockExpect(978, token14, &opeStack);





 getToken_CMockExpectAndReturn(981, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(982, token15, 0);

 isOperator_CMockExpectAndReturn(983, token15, 1);

 tryEvaluatethenPush_CMockExpect(984, token15, &numStack, &opeStack);

 stackPush_CMockExpect(985, token15, &opeStack);





 getToken_CMockExpectAndReturn(988, &tokenizer, token16);

 isNumber_CMockExpectAndReturn(989, token16, 1);

 stackPush_CMockExpect(990, token16, &numStack);





 getToken_CMockExpectAndReturn(993, &tokenizer, token17);

 isNumber_CMockExpectAndReturn(994, token17, 0);

 isOperator_CMockExpectAndReturn(995, token17, 1);

 tryEvaluatethenPush_CMockExpect(996, token17, &numStack, &opeStack);

 stackPush_CMockExpect(997, token17, &opeStack);





 getToken_CMockExpectAndReturn(1000, &tokenizer, token18);

 isNumber_CMockExpectAndReturn(1001, token18, 1);

 stackPush_CMockExpect(1002, token18, &numStack);





 getToken_CMockExpectAndReturn(1005, &tokenizer, token19);

 isNumber_CMockExpectAndReturn(1006, token19, 0);

 isOperator_CMockExpectAndReturn(1007, token19, 1);

 tryEvaluatethenPush_CMockExpect(1008, token19, &numStack, &opeStack);

 stackPush_CMockExpect(1009, token19, &opeStack);





 getToken_CMockExpectAndReturn(1012, &tokenizer, token20);

 isNumber_CMockExpectAndReturn(1013, token20, 0);

 isOperator_CMockExpectAndReturn(1014, token20, 1);

 tryEvaluatethenPush_CMockExpect(1015, token20, &numStack, &opeStack);

 stackPush_CMockExpect(1016, token20, &opeStack);

 getToken_CMockExpectAndReturn(1017, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1020, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(1051, "-(-2)", &tokenizer);





 getToken_CMockExpectAndReturn(1054, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1055, token1, 0);

 isOperator_CMockExpectAndReturn(1056, token1, 1);

 tryEvaluatethenPush_CMockExpect(1057, token1, &numStack, &opeStack);

 stackPush_CMockExpect(1058, token1, &opeStack);





 getToken_CMockExpectAndReturn(1061, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1062, token2, 0);

 isOperator_CMockExpectAndReturn(1063, token2, 1);

 tryEvaluatethenPush_CMockExpect(1064, token2, &numStack, &opeStack);

 stackPush_CMockExpect(1065, token2, &opeStack);





 getToken_CMockExpectAndReturn(1068, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1069, token3, 0);

 isOperator_CMockExpectAndReturn(1070, token3, 1);

 tryEvaluatethenPush_CMockExpect(1071, token3, &numStack, &opeStack);

 stackPush_CMockExpect(1072, token3, &opeStack);





 getToken_CMockExpectAndReturn(1075, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1076, token4, 1);

 stackPush_CMockExpect(1077, token4, &numStack);





 getToken_CMockExpectAndReturn(1080, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1081, token5, 0);

 isOperator_CMockExpectAndReturn(1082, token5, 1);

 tryEvaluatethenPush_CMockExpect(1083, token5, &numStack, &opeStack);

 stackPush_CMockExpect(1084, token5, &opeStack);

 getToken_CMockExpectAndReturn(1085, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1088, &numStack, &opeStack);











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





 initTokenizer_CMockExpectAndReturn(1151, "-(+(-(-1)*3)-4)", &tokenizer);





 getToken_CMockExpectAndReturn(1154, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1155, token1, 0);

 isOperator_CMockExpectAndReturn(1156, token1, 1);

 tryEvaluatethenPush_CMockExpect(1157, token1, &numStack, &opeStack);

 stackPush_CMockExpect(1158, token1, &opeStack);





 getToken_CMockExpectAndReturn(1161, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1162, token2, 0);

 isOperator_CMockExpectAndReturn(1163, token2, 1);

 tryEvaluatethenPush_CMockExpect(1164, token2, &numStack, &opeStack);

 stackPush_CMockExpect(1165, token2, &opeStack);





 getToken_CMockExpectAndReturn(1168, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1169, token3, 0);

 isOperator_CMockExpectAndReturn(1170, token3, 1);

 tryEvaluatethenPush_CMockExpect(1171, token3, &numStack, &opeStack);

 stackPush_CMockExpect(1172, token3, &opeStack);





 getToken_CMockExpectAndReturn(1175, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1176, token4, 0);

 isOperator_CMockExpectAndReturn(1177, token4, 1);

 tryEvaluatethenPush_CMockExpect(1178, token4, &numStack, &opeStack);

 stackPush_CMockExpect(1179, token4, &opeStack);





 getToken_CMockExpectAndReturn(1182, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1183, token5, 0);

 isOperator_CMockExpectAndReturn(1184, token5, 1);

 tryEvaluatethenPush_CMockExpect(1185, token5, &numStack, &opeStack);

 stackPush_CMockExpect(1186, token5, &opeStack);





 getToken_CMockExpectAndReturn(1189, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(1190, token6, 0);

 isOperator_CMockExpectAndReturn(1191, token6, 1);

 tryEvaluatethenPush_CMockExpect(1192, token6, &numStack, &opeStack);

 stackPush_CMockExpect(1193, token6, &opeStack);





 getToken_CMockExpectAndReturn(1196, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(1197, token7, 0);

 isOperator_CMockExpectAndReturn(1198, token7, 1);

 tryEvaluatethenPush_CMockExpect(1199, token7, &numStack, &opeStack);

 stackPush_CMockExpect(1200, token7, &opeStack);





 getToken_CMockExpectAndReturn(1203, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(1204, token8, 1);

 stackPush_CMockExpect(1205, token8, &numStack);





 getToken_CMockExpectAndReturn(1208, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(1209, token9, 0);

 isOperator_CMockExpectAndReturn(1210, token9, 1);

 tryEvaluatethenPush_CMockExpect(1211, token9, &numStack, &opeStack);

 stackPush_CMockExpect(1212, token9, &opeStack);





 getToken_CMockExpectAndReturn(1215, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(1216, token10, 0);

 isOperator_CMockExpectAndReturn(1217, token10, 1);

 tryEvaluatethenPush_CMockExpect(1218, token10, &numStack, &opeStack);

 stackPush_CMockExpect(1219, token10, &opeStack);





 getToken_CMockExpectAndReturn(1222, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(1223, token11, 1);

 stackPush_CMockExpect(1224, token11, &numStack);





 getToken_CMockExpectAndReturn(1227, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(1228, token12, 0);

 isOperator_CMockExpectAndReturn(1229, token12, 1);

 tryEvaluatethenPush_CMockExpect(1230, token12, &numStack, &opeStack);

 stackPush_CMockExpect(1231, token12, &opeStack);





 getToken_CMockExpectAndReturn(1234, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(1235, token13, 0);

 isOperator_CMockExpectAndReturn(1236, token13, 1);

 tryEvaluatethenPush_CMockExpect(1237, token13, &numStack, &opeStack);

 stackPush_CMockExpect(1238, token13, &opeStack);





 getToken_CMockExpectAndReturn(1241, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(1242, token14, 1);

 stackPush_CMockExpect(1243, token14, &numStack);





 getToken_CMockExpectAndReturn(1246, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(1247, token15, 0);

 isOperator_CMockExpectAndReturn(1248, token15, 1);

 tryEvaluatethenPush_CMockExpect(1249, token15, &numStack, &opeStack);

 stackPush_CMockExpect(1250, token15, &opeStack);

 getToken_CMockExpectAndReturn(1251, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1254, &numStack, &opeStack);











 shuntingYard("-(+(-(-1)*3)-4)");

}
