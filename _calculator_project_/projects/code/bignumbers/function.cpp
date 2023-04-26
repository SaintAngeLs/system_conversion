#include "function.h"

#define ll long long

char tolower(char ch)
{
    if(ch>=97)
        return ch;
    return ch + 32;
}
char toupper(char ch)
{
    if(ch<97)
        return ch;
    return ch - 32;
}
char* _strupr(char* str)
{
    int size = strlen(str);

    for(int i = 0;i < size; i++)
        str[i] = toupper(str[i]);
    return str;
}
char digitToHex(int N);
void convertToOther( bignum temp,char* result, int scale)
{
        //std::cout<<"convertToOther\n";
    bignum sc(scale);
    bignum rest;
    int count=0;
    while(temp!=0)
    {
        rest = temp%sc;
        result[count]= digitToHex( std::stoi(rest.to_string()));

        count++;
        //temp = temp-rest;
        temp /= sc;
    }
    result[count]='\0';

    int size = strlen(result);
    //std::cout<<result;
    int size1 = size/2;
    for(int i=0;i<size1;i++)
    {
        char tmpc = result[i];
        result[i]=result[size-1-i];
        result[size-i-1]=tmpc;
    }

}
void _itoa(const bignum& temp, char* result, int scale)
{
    char res [10000];
    strcpy(res,temp.to_string(scale).c_str());
    if((scale == 16)||(scale == 2))
    strcpy(result, res+2);
    else
    {
        if(scale==10)
        strcpy(result, res);
        else {
           convertToOther(temp, res,  scale);
           strcpy(result,res);
        }
    }


}

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


bignum  convertToDecimalFrom2To10(const bignum& a, int sys)
{
   bignum  num = a;
   bignum val = 0;

   bignum base = 1;

   bignum temp = num;
   bignum ten(10);
   bignum zero(0);
    while (temp>zero)
    {

        bignum last_digit = temp % ten;

        temp /= ten;

        val += last_digit * base;

        base *= sys;

    }

    return val;
}


bignum convertToDecimalFrom11To16(char* hex, int sys)
{
   bignum decimal (0), base ( 1);
   bignum sys1(sys);
    ll i = 0, value, length;
    char ch = digitToHex(sys - 1);
    length = strlen(hex);

    for (i = length--; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += bignum(hex[i] - 48) * base;
            base *= sys1;
        }
        else if (hex[i] >= 'A' && hex[i] <= ch)
        {
            decimal +=bignum (hex[i] - 55) * base;
            base *= sys1;
        }
        else if (hex[i] >= 'a' && hex[i] <=  tolower(ch))
        {
            decimal += bignum(hex[i] - 87) * base;
            base *= sys1;
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
