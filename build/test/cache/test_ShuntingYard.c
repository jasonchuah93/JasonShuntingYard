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

 getToken_CMockExpectAndReturn(47, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(48, token1, 1);

 stackPush_CMockExpect(49, token1, &numStack);



 getToken_CMockExpectAndReturn(51, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(52, token2, 0);

 isOperator_CMockExpectAndReturn(53, token2, 1);

 tryEvaluatethenPush_CMockExpect(54, token2, &numStack, &opeStack);

 stackPush_CMockExpect(55, token2, &opeStack);



 getToken_CMockExpectAndReturn(57, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(58, token3, 1);

 stackPush_CMockExpect(59, token3, &numStack);

 getToken_CMockExpectAndReturn(60, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(63, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(64, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(65, ansToken, 1);

 stackPush_CMockExpect(66, ansToken, &numStack);

 getToken_CMockExpectAndReturn(67, &tokenizer, ((void *)0));



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





 initTokenizer_CMockExpectAndReturn(96, "2+3*4", &tokenizer);



 getToken_CMockExpectAndReturn(98, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(99, token1, 1);

 stackPush_CMockExpect(100, token1, &numStack);



 getToken_CMockExpectAndReturn(102, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(103, token2, 0);

 isOperator_CMockExpectAndReturn(104, token2, 1);

 tryEvaluatethenPush_CMockExpect(105, token2, &numStack, &opeStack);

 stackPush_CMockExpect(106, token2, &opeStack);



 getToken_CMockExpectAndReturn(108, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(109, token3, 1);

 stackPush_CMockExpect(110, token3, &numStack);



 getToken_CMockExpectAndReturn(112, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(113, token4, 0);

 isOperator_CMockExpectAndReturn(114, token4, 1);

 tryEvaluatethenPush_CMockExpect(115, token4, &numStack, &opeStack);

 stackPush_CMockExpect(116, token4, &opeStack);



 getToken_CMockExpectAndReturn(118, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(119, token5, 1);

 stackPush_CMockExpect(120, token5, &numStack);

 getToken_CMockExpectAndReturn(121, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(123, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(124, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(125, ansToken, 1);

 stackPush_CMockExpect(126, ansToken, &numStack);

 getToken_CMockExpectAndReturn(127, &tokenizer, ((void *)0));



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





 initTokenizer_CMockExpectAndReturn(156, "2*3+4", &tokenizer);



 getToken_CMockExpectAndReturn(158, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(159, token1, 1);

 stackPush_CMockExpect(160, token1, &numStack);



 getToken_CMockExpectAndReturn(162, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(163, token2, 0);

 isOperator_CMockExpectAndReturn(164, token2, 1);

 tryEvaluatethenPush_CMockExpect(165, token2, &numStack, &opeStack);

 stackPush_CMockExpect(166, token2, &opeStack);



 getToken_CMockExpectAndReturn(168, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(169, token3, 1);

 stackPush_CMockExpect(170, token3, &numStack);



 getToken_CMockExpectAndReturn(172, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(173, token4, 0);

 isOperator_CMockExpectAndReturn(174, token4, 1);

 tryEvaluatethenPush_CMockExpect(175, token4, &numStack, &opeStack);

 stackPush_CMockExpect(176, token4, &opeStack);



 getToken_CMockExpectAndReturn(178, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(179, token5, 1);

 stackPush_CMockExpect(180, token5, &numStack);

 getToken_CMockExpectAndReturn(181, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(183, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(184, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(185, ansToken, 1);

 stackPush_CMockExpect(186, ansToken, &numStack);

 getToken_CMockExpectAndReturn(187, &tokenizer, ((void *)0));



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





 initTokenizer_CMockExpectAndReturn(228, "2+3*4+5*6", &tokenizer);



 getToken_CMockExpectAndReturn(230, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(231, token1, 1);

 stackPush_CMockExpect(232, token1, &numStack);



 getToken_CMockExpectAndReturn(234, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(235, token2, 0);

 isOperator_CMockExpectAndReturn(236, token2, 1);

 tryEvaluatethenPush_CMockExpect(237, token2, &numStack, &opeStack);

 stackPush_CMockExpect(238, token2, &opeStack);



 getToken_CMockExpectAndReturn(240, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(241, token3, 1);

 stackPush_CMockExpect(242, token3, &numStack);



 getToken_CMockExpectAndReturn(244, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(245, token4, 0);

 isOperator_CMockExpectAndReturn(246, token4, 1);

 tryEvaluatethenPush_CMockExpect(247, token4, &numStack, &opeStack);

 stackPush_CMockExpect(248, token4, &opeStack);



 getToken_CMockExpectAndReturn(250, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(251, token5, 1);

 stackPush_CMockExpect(252, token5, &numStack);



 getToken_CMockExpectAndReturn(254, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(255, token6, 0);

 isOperator_CMockExpectAndReturn(256, token6, 1);

 tryEvaluatethenPush_CMockExpect(257, token6, &numStack, &opeStack);

 stackPush_CMockExpect(258, token6, &opeStack);



 getToken_CMockExpectAndReturn(260, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(261, token7, 1);

 stackPush_CMockExpect(262, token7, &numStack);



 getToken_CMockExpectAndReturn(264, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(265, token8, 0);

 isOperator_CMockExpectAndReturn(266, token8, 1);

 tryEvaluatethenPush_CMockExpect(267, token8, &numStack, &opeStack);

 stackPush_CMockExpect(268, token8, &opeStack);



 getToken_CMockExpectAndReturn(270, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(271, token9, 1);

 stackPush_CMockExpect(272, token9, &numStack);

 getToken_CMockExpectAndReturn(273, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(275, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(276, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(277, ansToken, 1);

 stackPush_CMockExpect(278, ansToken, &numStack);

 getToken_CMockExpectAndReturn(279, &tokenizer, ((void *)0));





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





 initTokenizer_CMockExpectAndReturn(321, "2*3+4*5+6", &tokenizer);



 getToken_CMockExpectAndReturn(323, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(324, token1, 1);

 stackPush_CMockExpect(325, token1, &numStack);



 getToken_CMockExpectAndReturn(327, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(328, token2, 0);

 isOperator_CMockExpectAndReturn(329, token2, 1);

 tryEvaluatethenPush_CMockExpect(330, token2, &numStack, &opeStack);

 stackPush_CMockExpect(331, token2, &opeStack);



 getToken_CMockExpectAndReturn(333, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(334, token3, 1);

 stackPush_CMockExpect(335, token3, &numStack);



 getToken_CMockExpectAndReturn(337, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(338, token4, 0);

 isOperator_CMockExpectAndReturn(339, token4, 1);

 tryEvaluatethenPush_CMockExpect(340, token4, &numStack, &opeStack);

 stackPush_CMockExpect(341, token4, &opeStack);



 getToken_CMockExpectAndReturn(343, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(344, token5, 1);

 stackPush_CMockExpect(345, token5, &numStack);



 getToken_CMockExpectAndReturn(347, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(348, token6, 0);

 isOperator_CMockExpectAndReturn(349, token6, 1);

 tryEvaluatethenPush_CMockExpect(350, token6, &numStack, &opeStack);

 stackPush_CMockExpect(351, token6, &opeStack);



 getToken_CMockExpectAndReturn(353, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(354, token7, 1);

 stackPush_CMockExpect(355, token7, &numStack);



 getToken_CMockExpectAndReturn(357, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(358, token8, 0);

 isOperator_CMockExpectAndReturn(359, token8, 1);

 tryEvaluatethenPush_CMockExpect(360, token8, &numStack, &opeStack);

 stackPush_CMockExpect(361, token8, &opeStack);



 getToken_CMockExpectAndReturn(363, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(364, token9, 1);

 stackPush_CMockExpect(365, token9, &numStack);

 getToken_CMockExpectAndReturn(366, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(368, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(369, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(370, ansToken, 1);

 stackPush_CMockExpect(371, ansToken, &numStack);

 getToken_CMockExpectAndReturn(372, &tokenizer, ((void *)0));



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





 initTokenizer_CMockExpectAndReturn(418, "2|3+4*5-6-10", &tokenizer);



 getToken_CMockExpectAndReturn(420, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(421, token1, 1);

 stackPush_CMockExpect(422, token1, &numStack);



 getToken_CMockExpectAndReturn(424, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(425, token2, 0);

 isOperator_CMockExpectAndReturn(426, token2, 1);

 tryEvaluatethenPush_CMockExpect(427, token2, &numStack, &opeStack);

 stackPush_CMockExpect(428, token2, &opeStack);



 getToken_CMockExpectAndReturn(430, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(431, token3, 1);

 stackPush_CMockExpect(432, token3, &numStack);



 getToken_CMockExpectAndReturn(434, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(435, token4, 0);

 isOperator_CMockExpectAndReturn(436, token4, 1);

 tryEvaluatethenPush_CMockExpect(437, token4, &numStack, &opeStack);

 stackPush_CMockExpect(438, token4, &opeStack);



 getToken_CMockExpectAndReturn(440, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(441, token5, 1);

 stackPush_CMockExpect(442, token5, &numStack);



 getToken_CMockExpectAndReturn(444, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(445, token6, 0);

 isOperator_CMockExpectAndReturn(446, token6, 1);

 tryEvaluatethenPush_CMockExpect(447, token6, &numStack, &opeStack);

 stackPush_CMockExpect(448, token6, &opeStack);



 getToken_CMockExpectAndReturn(450, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(451, token7, 1);

 stackPush_CMockExpect(452, token7, &numStack);



 getToken_CMockExpectAndReturn(454, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(455, token8, 0);

 isOperator_CMockExpectAndReturn(456, token8, 1);

 tryEvaluatethenPush_CMockExpect(457, token8, &numStack, &opeStack);

 stackPush_CMockExpect(458, token8, &opeStack);



 getToken_CMockExpectAndReturn(460, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(461, token9, 1);

 stackPush_CMockExpect(462, token9, &numStack);



 getToken_CMockExpectAndReturn(464, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(465, token10, 0);

 isOperator_CMockExpectAndReturn(466, token10, 1);

 tryEvaluatethenPush_CMockExpect(467, token10, &numStack, &opeStack);

 stackPush_CMockExpect(468, token10, &opeStack);



 getToken_CMockExpectAndReturn(470, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(471, token11, 1);

 stackPush_CMockExpect(472, token11, &numStack);

 getToken_CMockExpectAndReturn(473, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(475, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(476, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(477, ansToken, 1);

 stackPush_CMockExpect(478, ansToken, &numStack);

 getToken_CMockExpectAndReturn(479, &tokenizer, ((void *)0));



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





 initTokenizer_CMockExpectAndReturn(513, "(2+3)*4", &tokenizer);



 getToken_CMockExpectAndReturn(515, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(516, token1, 0);

 isOperator_CMockExpectAndReturn(517, token1, 1);

 tryEvaluatethenPush_CMockExpect(518, token1, &numStack, &opeStack);

 stackPush_CMockExpect(519, token1, &opeStack);



 getToken_CMockExpectAndReturn(521, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(522, token2, 1);

 stackPush_CMockExpect(523, token2, &numStack);



 getToken_CMockExpectAndReturn(525, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(526, token3, 0);

 isOperator_CMockExpectAndReturn(527, token3, 1);

 tryEvaluatethenPush_CMockExpect(528, token3, &numStack, &opeStack);

 stackPush_CMockExpect(529, token3, &opeStack);



 getToken_CMockExpectAndReturn(531, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(532, token4, 1);

 stackPush_CMockExpect(533, token4, &numStack);



 getToken_CMockExpectAndReturn(535, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(536, token5, 0);

 isOperator_CMockExpectAndReturn(537, token5, 1);

 tryEvaluatethenPush_CMockExpect(538, token5, &numStack, &opeStack);

 stackPush_CMockExpect(539, token5, &opeStack);



 getToken_CMockExpectAndReturn(541, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(542, token6, 0);

 isOperator_CMockExpectAndReturn(543, token6, 1);

 tryEvaluatethenPush_CMockExpect(544, token6, &numStack, &opeStack);

 stackPush_CMockExpect(545, token6, &opeStack);



 getToken_CMockExpectAndReturn(547, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(548, token7, 1);

 stackPush_CMockExpect(549, token7, &numStack);

 getToken_CMockExpectAndReturn(550, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(552, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(553, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(554, ansToken, 1);

 stackPush_CMockExpect(555, ansToken, &numStack);

 getToken_CMockExpectAndReturn(556, &tokenizer, ((void *)0));



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





 initTokenizer_CMockExpectAndReturn(589, "2*(3+4)", &tokenizer);



 getToken_CMockExpectAndReturn(591, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(592, token1, 1);

 stackPush_CMockExpect(593, token1, &numStack);



 getToken_CMockExpectAndReturn(595, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(596, token2, 0);

 isOperator_CMockExpectAndReturn(597, token2, 1);

 tryEvaluatethenPush_CMockExpect(598, token2, &numStack, &opeStack);

 stackPush_CMockExpect(599, token2, &opeStack);



 getToken_CMockExpectAndReturn(601, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(602, token3, 0);

 isOperator_CMockExpectAndReturn(603, token3, 1);

 tryEvaluatethenPush_CMockExpect(604, token3, &numStack, &opeStack);

 stackPush_CMockExpect(605, token3, &opeStack);



 getToken_CMockExpectAndReturn(607, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(608, token4, 1);

 stackPush_CMockExpect(609, token4, &numStack);



 getToken_CMockExpectAndReturn(611, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(612, token5, 0);

 isOperator_CMockExpectAndReturn(613, token5, 1);

 tryEvaluatethenPush_CMockExpect(614, token5, &numStack, &opeStack);

 stackPush_CMockExpect(615, token5, &opeStack);



 getToken_CMockExpectAndReturn(617, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(618, token6, 1);

 stackPush_CMockExpect(619, token6, &numStack);



 getToken_CMockExpectAndReturn(621, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(622, token7, 0);

 isOperator_CMockExpectAndReturn(623, token7, 1);

 tryEvaluatethenPush_CMockExpect(624, token7, &numStack, &opeStack);

 stackPush_CMockExpect(625, token7, &opeStack);

 getToken_CMockExpectAndReturn(626, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(628, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(629, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(630, ansToken, 1);

 stackPush_CMockExpect(631, ansToken, &numStack);

 getToken_CMockExpectAndReturn(632, &tokenizer, ((void *)0));



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





 initTokenizer_CMockExpectAndReturn(650, "-2", &tokenizer);





 getToken_CMockExpectAndReturn(653, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(654, token1, 0);

 isOperator_CMockExpectAndReturn(655, token1, 1);

 tryEvaluatethenPush_CMockExpect(656, token1, &numStack, &opeStack);

 stackPush_CMockExpect(657, token1, &opeStack);





 getToken_CMockExpectAndReturn(660, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(661, token2, 1);

 stackPush_CMockExpect(662, token2, &numStack);

 getToken_CMockExpectAndReturn(663, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(666, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(667, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(668, ansToken, 1);

 stackPush_CMockExpect(669, ansToken, &numStack);

 getToken_CMockExpectAndReturn(670, &tokenizer, ((void *)0));



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





 initTokenizer_CMockExpectAndReturn(697, "-2+-3", &tokenizer);





 getToken_CMockExpectAndReturn(700, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(701, token1, 0);

 isOperator_CMockExpectAndReturn(702, token1, 1);

 tryEvaluatethenPush_CMockExpect(703, token1, &numStack, &opeStack);

 stackPush_CMockExpect(704, token1, &opeStack);





 getToken_CMockExpectAndReturn(707, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(708, token2, 1);

 stackPush_CMockExpect(709, token2, &numStack);





 getToken_CMockExpectAndReturn(712, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(713, token3, 0);

 isOperator_CMockExpectAndReturn(714, token3, 1);

 tryEvaluatethenPush_CMockExpect(715, token3, &numStack, &opeStack);

 stackPush_CMockExpect(716, token3, &opeStack);





 getToken_CMockExpectAndReturn(719, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(720, token4, 0);

 isOperator_CMockExpectAndReturn(721, token4, 1);

 tryEvaluatethenPush_CMockExpect(722, token4, &numStack, &opeStack);

 stackPush_CMockExpect(723, token4, &opeStack);





 getToken_CMockExpectAndReturn(726, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(727, token5, 1);

 stackPush_CMockExpect(728, token5, &numStack);

 getToken_CMockExpectAndReturn(729, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(732, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(733, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(734, ansToken, 1);

 stackPush_CMockExpect(735, ansToken, &numStack);

 getToken_CMockExpectAndReturn(736, &tokenizer, ((void *)0));



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





 initTokenizer_CMockExpectAndReturn(766, "-----2", &tokenizer);





 getToken_CMockExpectAndReturn(769, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(770, token1, 0);

 isOperator_CMockExpectAndReturn(771, token1, 1);

 tryEvaluatethenPush_CMockExpect(772, token1, &numStack, &opeStack);

 stackPush_CMockExpect(773, token1, &opeStack);





 getToken_CMockExpectAndReturn(776, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(777, token2, 0);

 isOperator_CMockExpectAndReturn(778, token2, 1);

 tryEvaluatethenPush_CMockExpect(779, token2, &numStack, &opeStack);

 stackPush_CMockExpect(780, token2, &opeStack);





 getToken_CMockExpectAndReturn(783, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(784, token3, 0);

 isOperator_CMockExpectAndReturn(785, token3, 1);

 tryEvaluatethenPush_CMockExpect(786, token3, &numStack, &opeStack);

 stackPush_CMockExpect(787, token3, &opeStack);





 getToken_CMockExpectAndReturn(790, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(791, token4, 0);

 isOperator_CMockExpectAndReturn(792, token4, 1);

 tryEvaluatethenPush_CMockExpect(793, token4, &numStack, &opeStack);

 stackPush_CMockExpect(794, token4, &opeStack);





 getToken_CMockExpectAndReturn(797, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(798, token5, 0);

 isOperator_CMockExpectAndReturn(799, token5, 1);

 tryEvaluatethenPush_CMockExpect(800, token5, &numStack, &opeStack);

 stackPush_CMockExpect(801, token5, &opeStack);





 getToken_CMockExpectAndReturn(804, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(805, token5, 1);

 stackPush_CMockExpect(806, token5, &numStack);

 getToken_CMockExpectAndReturn(807, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(810, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(811, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(812, ansToken, 1);

 stackPush_CMockExpect(813, ansToken, &numStack);

 getToken_CMockExpectAndReturn(814, &tokenizer, ((void *)0));



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





 initTokenizer_CMockExpectAndReturn(887, "(10*100)/((-5*6)-(2-30))", &tokenizer);





 getToken_CMockExpectAndReturn(890, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(891, token1, 0);

 isOperator_CMockExpectAndReturn(892, token1, 1);

 tryEvaluatethenPush_CMockExpect(893, token1, &numStack, &opeStack);

 stackPush_CMockExpect(894, token1, &opeStack);





 getToken_CMockExpectAndReturn(897, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(898, token2, 1);

 stackPush_CMockExpect(899, token2, &numStack);





 getToken_CMockExpectAndReturn(902, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(903, token3, 0);

 isOperator_CMockExpectAndReturn(904, token3, 1);

 tryEvaluatethenPush_CMockExpect(905, token3, &numStack, &opeStack);

 stackPush_CMockExpect(906, token3, &opeStack);





 getToken_CMockExpectAndReturn(909, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(910, token4, 1);

 stackPush_CMockExpect(911, token4, &numStack);





 getToken_CMockExpectAndReturn(914, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(915, token5, 0);

 isOperator_CMockExpectAndReturn(916, token5, 1);

 tryEvaluatethenPush_CMockExpect(917, token5, &numStack, &opeStack);

 stackPush_CMockExpect(918, token5, &opeStack);





 getToken_CMockExpectAndReturn(921, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(922, token6, 0);

 isOperator_CMockExpectAndReturn(923, token6, 1);

 tryEvaluatethenPush_CMockExpect(924, token6, &numStack, &opeStack);

 stackPush_CMockExpect(925, token6, &opeStack);





 getToken_CMockExpectAndReturn(928, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(929, token7, 0);

 isOperator_CMockExpectAndReturn(930, token7, 1);

 tryEvaluatethenPush_CMockExpect(931, token7, &numStack, &opeStack);

 stackPush_CMockExpect(932, token7, &opeStack);





 getToken_CMockExpectAndReturn(935, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(936, token8, 0);

 isOperator_CMockExpectAndReturn(937, token8, 1);

 tryEvaluatethenPush_CMockExpect(938, token8, &numStack, &opeStack);

 stackPush_CMockExpect(939, token8, &opeStack);





 getToken_CMockExpectAndReturn(942, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(943, token9, 0);

 isOperator_CMockExpectAndReturn(944, token9, 1);

 tryEvaluatethenPush_CMockExpect(945, token9, &numStack, &opeStack);

 stackPush_CMockExpect(946, token9, &opeStack);





 getToken_CMockExpectAndReturn(949, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(950, token10, 1);

 stackPush_CMockExpect(951, token10, &numStack);





 getToken_CMockExpectAndReturn(954, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(955, token11, 0);

 isOperator_CMockExpectAndReturn(956, token11, 1);

 tryEvaluatethenPush_CMockExpect(957, token11, &numStack, &opeStack);

 stackPush_CMockExpect(958, token11, &opeStack);





 getToken_CMockExpectAndReturn(961, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(962, token12, 1);

 stackPush_CMockExpect(963, token12, &numStack);





 getToken_CMockExpectAndReturn(966, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(967, token13, 0);

 isOperator_CMockExpectAndReturn(968, token13, 1);

 tryEvaluatethenPush_CMockExpect(969, token13, &numStack, &opeStack);

 stackPush_CMockExpect(970, token13, &opeStack);





 getToken_CMockExpectAndReturn(973, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(974, token14, 0);

 isOperator_CMockExpectAndReturn(975, token14, 1);

 tryEvaluatethenPush_CMockExpect(976, token14, &numStack, &opeStack);

 stackPush_CMockExpect(977, token14, &opeStack);





 getToken_CMockExpectAndReturn(980, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(981, token15, 0);

 isOperator_CMockExpectAndReturn(982, token15, 1);

 tryEvaluatethenPush_CMockExpect(983, token15, &numStack, &opeStack);

 stackPush_CMockExpect(984, token15, &opeStack);





 getToken_CMockExpectAndReturn(987, &tokenizer, token16);

 isNumber_CMockExpectAndReturn(988, token16, 1);

 stackPush_CMockExpect(989, token16, &numStack);





 getToken_CMockExpectAndReturn(992, &tokenizer, token17);

 isNumber_CMockExpectAndReturn(993, token17, 0);

 isOperator_CMockExpectAndReturn(994, token17, 1);

 tryEvaluatethenPush_CMockExpect(995, token17, &numStack, &opeStack);

 stackPush_CMockExpect(996, token17, &opeStack);





 getToken_CMockExpectAndReturn(999, &tokenizer, token18);

 isNumber_CMockExpectAndReturn(1000, token18, 1);

 stackPush_CMockExpect(1001, token18, &numStack);





 getToken_CMockExpectAndReturn(1004, &tokenizer, token19);

 isNumber_CMockExpectAndReturn(1005, token19, 0);

 isOperator_CMockExpectAndReturn(1006, token19, 1);

 tryEvaluatethenPush_CMockExpect(1007, token19, &numStack, &opeStack);

 stackPush_CMockExpect(1008, token19, &opeStack);





 getToken_CMockExpectAndReturn(1011, &tokenizer, token20);

 isNumber_CMockExpectAndReturn(1012, token20, 0);

 isOperator_CMockExpectAndReturn(1013, token20, 1);

 tryEvaluatethenPush_CMockExpect(1014, token20, &numStack, &opeStack);

 stackPush_CMockExpect(1015, token20, &opeStack);

 getToken_CMockExpectAndReturn(1016, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1019, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(1020, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(1021, ansToken, 1);

 stackPush_CMockExpect(1022, ansToken, &numStack);

 getToken_CMockExpectAndReturn(1023, &tokenizer, ((void *)0));



 shuntingYard("(10*100)/((-5*6)-(2-30))");

}
