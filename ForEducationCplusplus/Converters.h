#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// DECIMAL To...
string decimalToBinary(int num);
string decimalToOctal(int num);
string decimalToHex(int num);
string decimalToSixtyTwoBaseAndLess(int num, int base);

// BINARY TO...
string binaryToOcatl(string binary);
string binaryToHex(string binary);
string binaryToDecimal(string binary);

// OCTAL TO...
string octalToDecimal(string octalNum);
string octalToBinary(string octalNum);
string octalToHex(string octalNum);