#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include <io.h>
#include <process.h>
int main()
{
    char input;
   
    printf("Please, press 1 if you want to work with integer numbers (less than 1*10^4).\n\n");
    printf("Please, press 2 if you want to work with big integer numbers (less and greater then 1*10^4).\n\n");
    scanf("%c", &input);
    printf("\n");

    switch(input)
    {

    case '1':
        //chdir("../numbers/");
        //system(".\\main_n.exe");
		chdir("../../../calculator/calculator_/x64/Debug");
		system(".\\numbers.exe");
        break;
    case '2':
		chdir("../../../calculator/calculator_/x64/Debug");
		system(".\\bignumbers.exe");
        
        break;
    default:
        printf("The number you input is now equal to 1 or 2. ");
        printf("Please, press 'ENTER' to continue.");
        getchar();
		getchar();
        exit(1);
    }
}