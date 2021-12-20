#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include "function.c"
#include <conio.h>


#define ll long long 


int main()
{
    char output;
    char op[2];
    char result[10000], a1[500], a2[500];
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

                if (*op == 'f')
                    exit(0);

                scanf("%d", &scale);
                puts("");
                scanf("%s", &a1);
        

                ll d = atoll(op);
                ll ia1 = atoll(a1);
                ll temp;
                if(ia1 >= 10000)
                {
                    result_exists = 0; 
                    goto anyres;
                }
                if (isdigit(*op))
                {
                    if (!correctNumSystem(a1, atoi(op)))
                    {
                        correct_system = 0;
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
                        goto res;
                    }

                    puts("");
                    scanf("%s", &a2);

                    if (!correctNumSystem(a2, scale))
                    {
                        correct_system = 0;
                        goto res;
                    }

                    ll ia2 = atoll(a2);

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

                        if (ia2 == 0)
                        {
                                result_exists = 0;
                                printf("\n");
                                printf("Division by zero.  Please, press 'ENTER' to continue.");
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
                            temp = pow(convertToDecimalFrom2To10(ia1, scale), convertToDecimalFrom2To10(ia2, scale));
                        else if (scale >= 11 && scale <= 16)
                            temp = pow(convertToDecimalFrom11To16(a1, scale), convertToDecimalFrom11To16(a2, scale));
                        else
                            result_exists = 0;

                        if (result_exists)
                            _itoa(temp, result, scale);
                    }
                }
        anyres:
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
                    printf("\n");
                    if (output == 2)
                    {
                        exit(0);
                    }
                }

                res:
                if (!correct_system)
                {
                    puts("\nIncorrect number for this number system!\n");
                    //puts("\n");
                    printf("Please, press ENTER to continue.");
                    getchar();
                    getchar();
                    printf("\n");
                    if (output == 2)
                    {
                        exit(0);
                    }
            
                }
            }
              
}