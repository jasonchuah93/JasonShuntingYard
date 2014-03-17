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





 initTokenizer_CMockExpectAndReturn(47, "2+3", &tokenizer);

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

 getToken_CMockExpectAndReturn(65, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(66, ansToken, 1);

 stackPush_CMockExpect(67, ansToken, &numStack);

 getToken_CMockExpectAndReturn(68, &tokenizer, ((void *)0));



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

 getToken_CMockExpectAndReturn(125, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(126, ansToken, 1);

 stackPush_CMockExpect(127, ansToken, &numStack);

 getToken_CMockExpectAndReturn(128, &tokenizer, ((void *)0));



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

 getToken_CMockExpectAndReturn(185, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(186, ansToken, 1);

 stackPush_CMockExpect(187, ansToken, &numStack);

 getToken_CMockExpectAndReturn(188, &tokenizer, ((void *)0));



 shuntingYard("2*3+4");

}



void test_evaluate_LEFT_PARENTHESIS_2_PLUS_3_RIGHT_PARENTHESIS_MULTIPLY_4(void){



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





 initTokenizer_CMockExpectAndReturn(233, "2+3*4+5*6", &tokenizer);



 getToken_CMockExpectAndReturn(235, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(236, token1, 1);

 stackPush_CMockExpect(237, token1, &numStack);



 getToken_CMockExpectAndReturn(239, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(240, token2, 0);

 isOperator_CMockExpectAndReturn(241, token2, 1);

 tryEvaluatethenPush_CMockExpect(242, token2, &numStack, &opeStack);

 stackPush_CMockExpect(243, token2, &opeStack);



 getToken_CMockExpectAndReturn(245, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(246, token3, 1);

 stackPush_CMockExpect(247, token3, &numStack);



 getToken_CMockExpectAndReturn(249, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(250, token4, 0);

 isOperator_CMockExpectAndReturn(251, token4, 1);

 tryEvaluatethenPush_CMockExpect(252, token4, &numStack, &opeStack);

 stackPush_CMockExpect(253, token4, &opeStack);



 getToken_CMockExpectAndReturn(255, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(256, token5, 1);

 stackPush_CMockExpect(257, token5, &numStack);



 getToken_CMockExpectAndReturn(259, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(260, token6, 0);

 isOperator_CMockExpectAndReturn(261, token6, 1);

 tryEvaluatethenPush_CMockExpect(262, token6, &numStack, &opeStack);

 stackPush_CMockExpect(263, token6, &opeStack);



 getToken_CMockExpectAndReturn(265, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(266, token7, 1);

 stackPush_CMockExpect(267, token7, &numStack);



 getToken_CMockExpectAndReturn(269, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(270, token8, 0);

 isOperator_CMockExpectAndReturn(271, token8, 1);

 tryEvaluatethenPush_CMockExpect(272, token8, &numStack, &opeStack);

 stackPush_CMockExpect(273, token8, &opeStack);



 getToken_CMockExpectAndReturn(275, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(276, token9, 1);

 stackPush_CMockExpect(277, token9, &numStack);

 getToken_CMockExpectAndReturn(278, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(280, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(281, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(282, ansToken, 1);

 stackPush_CMockExpect(283, ansToken, &numStack);

 getToken_CMockExpectAndReturn(284, &tokenizer, ((void *)0));





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





 initTokenizer_CMockExpectAndReturn(326, "2*3+4*5+6", &tokenizer);



 getToken_CMockExpectAndReturn(328, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(329, token1, 1);

 stackPush_CMockExpect(330, token1, &numStack);



 getToken_CMockExpectAndReturn(332, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(333, token2, 0);

 isOperator_CMockExpectAndReturn(334, token2, 1);

 tryEvaluatethenPush_CMockExpect(335, token2, &numStack, &opeStack);

 stackPush_CMockExpect(336, token2, &opeStack);



 getToken_CMockExpectAndReturn(338, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(339, token3, 1);

 stackPush_CMockExpect(340, token3, &numStack);



 getToken_CMockExpectAndReturn(342, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(343, token4, 0);

 isOperator_CMockExpectAndReturn(344, token4, 1);

 tryEvaluatethenPush_CMockExpect(345, token4, &numStack, &opeStack);

 stackPush_CMockExpect(346, token4, &opeStack);



 getToken_CMockExpectAndReturn(348, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(349, token5, 1);

 stackPush_CMockExpect(350, token5, &numStack);



 getToken_CMockExpectAndReturn(352, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(353, token6, 0);

 isOperator_CMockExpectAndReturn(354, token6, 1);

 tryEvaluatethenPush_CMockExpect(355, token6, &numStack, &opeStack);

 stackPush_CMockExpect(356, token6, &opeStack);



 getToken_CMockExpectAndReturn(358, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(359, token7, 1);

 stackPush_CMockExpect(360, token7, &numStack);



 getToken_CMockExpectAndReturn(362, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(363, token8, 0);

 isOperator_CMockExpectAndReturn(364, token8, 1);

 tryEvaluatethenPush_CMockExpect(365, token8, &numStack, &opeStack);

 stackPush_CMockExpect(366, token8, &opeStack);



 getToken_CMockExpectAndReturn(368, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(369, token9, 1);

 stackPush_CMockExpect(370, token9, &numStack);

 getToken_CMockExpectAndReturn(371, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(373, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(374, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(375, ansToken, 1);

 stackPush_CMockExpect(376, ansToken, &numStack);

 getToken_CMockExpectAndReturn(377, &tokenizer, ((void *)0));



 shuntingYard("2*3+4*5+6");



}



void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_DIVIDE_10(void){

 Tokenizer tokenizer = {.rawString = "2|3+4*5-6/10", .startIndex = 0, .length = 11};



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



 Operator divide = {.type= OPERATOR, .id = DIVIDE};

 Token *token10 = (Token*)&subtract;



 Number number10 = {.type= NUMBER, .value=10};

 Token *token11 = (Token*)&number10;



 Number answer = {.type=NUMBER, .value=22.5};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(423, "2|3+4*5-6/10", &tokenizer);



 getToken_CMockExpectAndReturn(425, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(426, token1, 1);

 stackPush_CMockExpect(427, token1, &numStack);



 getToken_CMockExpectAndReturn(429, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(430, token2, 0);

 isOperator_CMockExpectAndReturn(431, token2, 1);

 tryEvaluatethenPush_CMockExpect(432, token2, &numStack, &opeStack);

 stackPush_CMockExpect(433, token2, &opeStack);



 getToken_CMockExpectAndReturn(435, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(436, token3, 1);

 stackPush_CMockExpect(437, token3, &numStack);



 getToken_CMockExpectAndReturn(439, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(440, token4, 0);

 isOperator_CMockExpectAndReturn(441, token4, 1);

 tryEvaluatethenPush_CMockExpect(442, token4, &numStack, &opeStack);

 stackPush_CMockExpect(443, token4, &opeStack);



 getToken_CMockExpectAndReturn(445, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(446, token5, 1);

 stackPush_CMockExpect(447, token5, &numStack);



 getToken_CMockExpectAndReturn(449, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(450, token6, 0);

 isOperator_CMockExpectAndReturn(451, token6, 1);

 tryEvaluatethenPush_CMockExpect(452, token6, &numStack, &opeStack);

 stackPush_CMockExpect(453, token6, &opeStack);



 getToken_CMockExpectAndReturn(455, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(456, token7, 1);

 stackPush_CMockExpect(457, token7, &numStack);



 getToken_CMockExpectAndReturn(459, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(460, token8, 0);

 isOperator_CMockExpectAndReturn(461, token8, 1);

 tryEvaluatethenPush_CMockExpect(462, token8, &numStack, &opeStack);

 stackPush_CMockExpect(463, token8, &opeStack);



 getToken_CMockExpectAndReturn(465, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(466, token9, 1);

 stackPush_CMockExpect(467, token9, &numStack);



 getToken_CMockExpectAndReturn(469, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(470, token10, 0);

 isOperator_CMockExpectAndReturn(471, token10, 1);

 tryEvaluatethenPush_CMockExpect(472, token10, &numStack, &opeStack);

 stackPush_CMockExpect(473, token10, &opeStack);



 getToken_CMockExpectAndReturn(475, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(476, token11, 1);

 stackPush_CMockExpect(477, token11, &numStack);

 getToken_CMockExpectAndReturn(478, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(480, &numStack, &opeStack);

 getToken_CMockExpectAndReturn(481, &tokenizer, ansToken);

 isNumber_CMockExpectAndReturn(482, ansToken, 1);

 stackPush_CMockExpect(483, ansToken, &numStack);

 getToken_CMockExpectAndReturn(484, &tokenizer, ((void *)0));



 shuntingYard("2|3+4*5-6/10");



}



void test_LEFT_PARENTHESIS_2_PLUS_3_LEFTPARENTHESIS_MULTIPLY_4(void){

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





 initTokenizer_CMockExpectAndReturn(518, "(2+3)*4", &tokenizer);



 getToken_CMockExpectAndReturn(520, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(521, token1, 0);

 isOperator_CMockExpectAndReturn(522, token1, 1);

 tryEvaluatethenPush_CMockExpect(523, token1, &numStack, &opeStack);

 stackPush_CMockExpect(524, token1, &opeStack);



 getToken_CMockExpectAndReturn(526, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(527, token2, 1);

 stackPush_CMockExpect(528, token2, &numStack);

 shuntingYard1("(2+3)*4");



}
