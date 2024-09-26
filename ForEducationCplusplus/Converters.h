#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string decimalToBinary(int num);
string decimalToOctal(int num);
string decimalToHex(int num);
string decimalToSixtyTwoBaseAndLess(int num, int base);

string binaryToOcatl(string binary);
string binaryToHex(string binary);
string binaryToDecimal(string binary);



vector<string> myGourpingStringByStep(string& base_str, int step);