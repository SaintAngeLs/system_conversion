#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<string>
#include "function.h"

#include <conio.h>
#include"bignum.h"

#define ll long long


/*void incorrectSystemExit()
{
// inappropriate system exit possibly important for the testing case
  puts("\nIncorrect number for this number system!");
            printf("\nTo continue press 'ENTER'.");
            getchar();
            getchar();
            puts("");         
}*/

int main()
{

    char output;
    char consequence_1 = '1';
    char consequence_2 = '2';
    char op[20];
    char result[10000],
     a1[500], a2[500];
    int scale;

    printf("Please, press 1 if you want to obtain the results of every operation in this file. \n\n");
    printf("Please, press 2 if you want to obtain the result of operation in one separate file\n(program exits after obtaining the result of operation).\n\n");
    scanf("%c", &output);
    printf("\n"); 
    printf("Please, input the sign of operation, space and the base of the system to execute operation.\nPress 'ENTER'. After that, input the first argument, press 'ENTER' and then input the second agrument, press 'ENTER'.\n\n");      
    
    
    while (1)
    {
        int result_exists = 0;
        int correct_system = 1;

        scanf("%s", &op);

        if (*op == 'q')
            exit(0);

        scanf("%d", &scale);
        puts("");
        scanf("%s", &a1);


        ll d = atoll(op);
        bignum    ia1 = std::string(a1);
        // ll temp;
        bignum temp(1);

        if (isdigit(*op))
        {

            if (!correctNumSystem(a1, atoi(op)))
            {
                correct_system = 0;
                //incorrectSystemExit();
                goto res;
            }

            result_exists = 1;

            if (d >= 2 && d <= 10 && scale >= 2 && scale <= 16)
                temp = convertToDecimalFrom2To10(ia1, d);
            else if (d >= 11 && d <= 16 && scale >= 2 && scale <= 16)
                temp = convertToDecimalFrom11To16(a1, d);
            else
                result_exists = 0;

            if(result_exists)
                _itoa(temp, result, scale);
        }
        else
        {
            if (!correctNumSystem(a1, scale))
            {
                correct_system = 0;
                //incorrectSystemExit();
                
                goto res;
            }

            puts("");
            scanf("%s", &a2);

            if (!correctNumSystem(a2, scale))
            {
                correct_system = 0;
                // incorrectSystemExit();
                goto res;
            }

            bignum ia2= std::string(a2);

            if (*op == '+')
            {
                result_exists = 1;

                if (scale >= 2 && scale <= 10)
                    temp = convertToDecimalFrom2To10(ia1, scale) + convertToDecimalFrom2To10(ia2, scale);
                else if (scale >= 11 && scale <= 16)
                    temp = convertToDecimalFrom11To16(a1, scale) + convertToDecimalFrom11To16(a2, scale);
                else
                    result_exists = 0;

                if(result_exists)
                    _itoa(temp, result, scale);
            }
            
            else if (*op == '*')
            {
                result_exists = 1;

                if (scale >= 2 && scale <= 10)
                    temp = convertToDecimalFrom2To10(ia1, scale) * convertToDecimalFrom2To10(ia2, scale);
                else if (scale >= 11 && scale <= 16)
                    temp = convertToDecimalFrom11To16(a1, scale) * convertToDecimalFrom11To16(a2, scale);
                else
                    result_exists = 0;

                if (result_exists)
                    _itoa(temp, result, scale);
            }
            else if (*op == '/')
            {
                result_exists = 1;

                if (ia2 == bignum(0))
                {
                        result_exists = 0;
                        printf("\n");
                        printf("Division by zero. Please, press 'ENTER' to continue.");
                        getchar();
						getchar();

                }
                else if (scale >= 2 && scale <= 10)
                    temp = convertToDecimalFrom2To10(ia1, scale) / convertToDecimalFrom2To10(ia2, scale);
                else if (scale >= 11 && scale <= 16)
                    temp = convertToDecimalFrom11To16(a1, scale) / convertToDecimalFrom11To16(a2, scale);
                else
                    result_exists = 0;

                if (result_exists)
                    _itoa(temp, result, scale);
            }
            else if (*op == '%')
            {
                result_exists = 1;

                if (scale >= 2 && scale <= 10)
                    temp = convertToDecimalFrom2To10(ia1, scale) % convertToDecimalFrom2To10(ia2, scale);
                else if (scale >= 11 && scale <= 16)
                    temp = convertToDecimalFrom11To16(a1, scale) % convertToDecimalFrom11To16(a2, scale);
                else
                    result_exists = 0;

                if (result_exists)
                        _itoa(temp, result, scale);
            }
            else if (*op == '^')
            {
                result_exists = 1;

                if (scale >= 2 && scale <= 10)
                    temp = convertToDecimalFrom2To10(ia1, scale).pow(std::stoi(convertToDecimalFrom2To10(ia2, scale).to_string()));
                else if (scale >= 11 && scale <= 16)
                    temp = convertToDecimalFrom11To16(a1, scale).pow(std::stoi(convertToDecimalFrom11To16(a2, scale).to_string()));
                else
                    result_exists = 0;

                if (result_exists)
                    _itoa(temp, result, scale);
            }
        }

        if (result_exists)
        {
            _strupr(result);
            printf("\n%s", result);
            puts("\n");
            if (output == 2)
            {
                exit(0);
            }
        }
        else
        {
            puts("\nIncorrect operator/operation!");
            puts("");
            if (output == 2)
            {
                exit(0);
            }
        }

        res:
        if (!correct_system)
        {
            //incorrectSystemExit();
            puts("\nIncorrect number for this number system!");
            printf("\nPlease, press 'ENTER' to continue.");
            getchar();
            getchar();
            puts("");
            if (output == 2)
            {
                exit(0);
            }
            
        }
    }            
    
}
