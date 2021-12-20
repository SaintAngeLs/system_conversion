#include "function.h"

#define ll long long 


char digitToHex(int N)
{
    switch (N)
    {
        case 0: return('0'); break;
        case 1: return('1'); break;
        case 2: return('2'); break;
        case 3: return('3'); break;
        case 4: return('4'); break;
        case 5: return('5'); break;
        case 6: return('6'); break;
        case 7: return('7'); break;
        case 8: return('8'); break;
        case 9: return('9'); break;
        case 10: return('A'); break;
        case 11: return('B'); break;
        case 12: return('C'); break;
        case 13: return('D'); break;
        case 14: return('E'); break;
        case 15: return('F'); break;
        default: return('?');
    }
}


int hexToDigit(char ch)
{
    switch (ch)
    {
        case '0': return(0); break;
        case '1': return(1); break;
        case '2': return(2); break;
        case '3': return(3); break;
        case '4': return(4); break;
        case '5': return(5); break;
        case '6': return(6); break;
        case '7': return(7); break;
        case '8': return(8); break;
        case '9': return(9); break;
        case 'A': return(10); break;
        case 'B': return(11); break;
        case 'C': return(12); break;
        case 'D': return(13); break;
        case 'E': return(14); break;
        case 'F': return(15); break;
        default: return('?');
    }
}


ll convertToDecimalFrom2To10(long long a, int sys)
{
    ll num = a;
    ll val = 0;

    ll base = 1;

    ll temp = num;
    while (temp)
    {
        ll last_digit = temp % 10;
        temp /= 10;

        val += last_digit * base;

        base *= sys;
    }

    return val;
}


ll convertToDecimalFrom11To16(char* hex, int sys)
{
    ll decimal = 0, base = 1;
    ll i = 0, value, length;
    char ch = digitToHex(sys - 1);
    length = strlen(hex);

    for (i = length--; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base *= sys;
        }
        else if (hex[i] >= 'A' && hex[i] <= ch)
        {
            decimal += (hex[i] - 55) * base;
            base *= sys;
        }
        else if (hex[i] >= 'a' && hex[i] <= tolower(ch))
        {
            decimal += (hex[i] - 87) * base;
            base *= sys;
        }
    }

    return decimal;
}


int correctNumSystem(char* str, int scale)
{
    _strupr(str);

    for (int i = 0; i < strlen(str); ++i)
    {
        if (hexToDigit(str[i]) >= scale)
            return 0;
    }

    return 1;
}