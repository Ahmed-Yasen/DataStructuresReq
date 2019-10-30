#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "string.h"
#include "queue.h"

/*
 *Enable one of the #defines below to use it
 */

/* #define OPEN_REQ_2 */
/* #define OPEN_REQ_4 */

/*
 * @note: requirement 1 used in requirement 2
 * @note: requirement 2 used in requirement 4
 */

ST_queueInfo q;
ST_stackInfo st;


unsigned char checkForBalancedParantheses(char* expression);
long long evaluate(char* expression);

/*
 * non_requirement Functions used in the requirement function
 */

 long long doBinaryOperation(long long firstNum, char operation, long long secondNum);

int main()
{
    createStack(&st, 200);

    #ifdef OPEN_REQ_2
    char str[] = "}(){";
    int ret = checkForBalancedParantheses(str);
    if(ret == 1){
        printf("Balanced\r\n");
    }else{
        printf("Not-Balanced\r\n");
    }
    return 0;
    #endif // OPEN_REQ_2

    #ifdef OPEN_REQ_4

    createQueue(&q, 200);
    char expression[] = "((3+5)*4/2)";
    long long ret = evaluate(expression);

    printf("%u", ret);

    #endif
}
long long evaluate(char* expression){
    unsigned char isparanthesesBalanced = checkForBalancedParantheses(expression);
    unsigned short loopIndex = 0;
    unsigned int tempChar = '#';
    long long calculation = 0;
    unsigned int number;
    char lastSign = '+';
    char sign = '#';

    if(isparanthesesBalanced == 1){
        for(loopIndex = 0; loopIndex < strlen(expression); loopIndex ++){
            enqueue(&q, expression[loopIndex]);
        }

        number = 0;
        do{

            tempChar = '#';
            dequeue(&q, &tempChar);
            switch(tempChar){
            case '0'...'9':{

                number *= 10;
                number += (tempChar - '0');

            }break;
            case '*':
            case '+':
            case '-':
            case '/':
                {
                sign = tempChar;
                calculation = doBinaryOperation(calculation, lastSign, number);
                number = 0;
                lastSign = sign;

            }break;
            }
        }while(tempChar != '#');


        calculation = doBinaryOperation(calculation, lastSign, number);
    }

    return calculation;
}

unsigned char checkForBalancedParantheses(char* expression){
    unsigned short loopIndex;
    int tempChar;
    unsigned char balance = 1;

    for(loopIndex = 0; (loopIndex < strlen(expression)) && balance; loopIndex ++){
        tempChar = '#';
        switch(expression[loopIndex]){
        case '}':{
            pop(&st, &tempChar);
            if('{' != tempChar){
                balance = 0;
            }
        }break;
        case ']':{
            pop(&st, &tempChar);
            if('[' != tempChar){
                balance = 0;
            }
        }break;
        case ')':
        {
            pop(&st, &tempChar);
            if('(' != tempChar){
                balance = 0;
            }
        }break;
        case '{':
        case '[':
        case '(':
        {
            push(&st, expression[loopIndex]);

        }break;
        }
    }
    tempChar = '#';
    pop(&st, &tempChar);
    if(tempChar != '#'){
        balance = 0;
    }
    return balance;
}


/*
unsigned char checkForBalancedParantheses(char* expression){
    short curly = 0, square = 0, regular = 0;
    unsigned char loopIndex;
    int tempChar;
    unsigned char ret = 0;

    for(loopIndex = 0; loopIndex < strlen(expression); loopIndex ++){
        push(&st, expression[loopIndex]);
    }

    for(loopIndex = 0; loopIndex < strlen(expression); loopIndex ++){
        tempChar = 0;
        pop(&st, &tempChar);
        switch(tempChar & (0xFF)){
            case '{':{
                curly ++;
            }break;
            case '[':{
                square ++;
            }break;
            case '(':{
                regular ++;
            }break;
            case '}':{
                curly --;
            }break;
            case ']':{
                square --;
            }break;
            case ')':{
                regular --;
            }
            default:{
                //NOP
            }
        }
    }

    if(!(curly || square || regular)){
        ret = 1;
    }else{
        ret = 0;
    }

    return ret;
}
*/

long long doBinaryOperation(long long firstNum, char operation, long long secondNum){
    long long calculation = 0;
    switch(operation){
    case '*':{
        calculation = firstNum * secondNum;
    }break;
    case '+':{
        calculation = firstNum + secondNum;
    }break;
    case '-':{
        calculation = firstNum - secondNum;
    }break;
    case '/':{
        calculation = firstNum / secondNum;
    }break;
    }

    return calculation;
}
