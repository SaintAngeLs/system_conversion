#pragma once

char digitToHex(int N);
int hexToDigit(char ch);
long long convertToDecimalFrom2To10(long long a, int sys);
long long convertToDecimalFrom11To16(char* hex, int sys);
int correctNumSystem(char* str, int scale);