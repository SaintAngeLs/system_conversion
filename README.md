# system_conversion

This program is a number system converter that allows you to convert numbers between different number systems, such as binary, decimal, hexadecimal, etc. You can also perform basic arithmetic operations (addition, subtraction, multiplication, division, and modulo) on numbers in different number systems.

# Getting Started
To use this program, you need to compile it using a C compiler that supports C99 standard. The program uses the following C standard libraries: stdio.h, ctype.h, stdlib.h, math.h, and string.h. Additionally, it uses two custom header files: function.h and bignum.h.

Once you have compiled the program, run it in the terminal/command prompt. You will be prompted to choose between two options:

Print results of every operation in the console
Obtain the result of an operation in a separate file and exit
After selecting an option, you will be prompted to enter an arithmetic operation in the format "operation base number1 number2". For example, to add two binary numbers, you would enter "+ 2 1101 1010".

The program supports number systems with bases from 2 to 16. For systems with bases from 2 to 10, the program uses long long integers to store the numbers. For systems with bases from 11 to 16, the program uses a custom class bignum to store the numbers.

The program performs error checking to ensure that the input numbers are valid in their respective number systems.

# Functions
The program provides the following functions:

correctNumSystem(char* num, int sys) - checks whether a number is valid in a given number system.
convertToDecimalFrom2To10(bignum num, ll base) - converts a number from binary to decimal, or from base-3 to base-10.
convertToDecimalFrom11To16(char* num, ll base) - converts a number from hexadecimal to decimal.
# License
This program is licensed under the MIT License. See LICENSE.txt for details.
