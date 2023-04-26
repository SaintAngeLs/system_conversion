#ifndef FUNCTION_H
#define FUNCTION_H
#include<string.h>
#include"bignum.h"
char digitToHex(int N);
char tolower(char ch);
char toupper(char ch);
char* _strupr(char* str);
void convertToOther(bignum temp,char* result, int scale);
void _itoa(const bignum &temp,char* result, int scale);
int hexToDigit(char ch);
bignum convertToDecimalFrom2To10(const bignum&  a, int sys);
bignum convertToDecimalFrom11To16(char* hex, int sys);
int correctNumSystem(char* str, int scale);
#endif
