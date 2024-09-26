#include "Converters.h"
#include <string>
#include <vector>

using namespace std;

constexpr int MAX_BASE = 62;
constexpr char hexValues[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void mySwap(char& char1, char& char2);
void myReverseString(string& base_str);
//vector<string> myGourpingStringByStep(string& base_str, int step);
int myPower(int base, int exponent);

// DECIMAL TO ...
string  decimalToBinary(int num)
{
	string result = "";

	while (num > 0) {
		int remainder = num % 2;
		result = to_string(remainder) + result;
		num = num / 2;
	}
	return result;
}

string decimalToOctal(int num)
{
	if (num == 0)
		return to_string(0);

	string result = "";

	while (num > 0) {
		int remainder = num % 8;
		result = result + to_string(remainder);
		num = num / 8;
	}

	myReverseString(result);

	return result;
}

string decimalToHex(int num)
{
	if (num == 0)
		return to_string(0);

	//char hexValues[] = "0123456789ABCDEF";
	string result = "";

	while (num > 0) {
		int remainder = num % 16;
		result = result + hexValues[remainder];
		num /= 16;
	}
	myReverseString(result);
	return result;
}

string decimalToSixtyTwoBaseAndLess(int num, int base)
{
	if (base > MAX_BASE)
		return "Base cannot be greater than 62";

	int sign;
	if (num < 0) {
		sign = -1;
	}
	else if (num == 0){
		return to_string(hexValues[0]);
	}
	else {
		sign = 1;
	}

	string result_str = "";

	while (num > 0) {
		int remainder = num % base;
		result_str = result_str + hexValues[remainder];
		num /= base;
	}

	myReverseString(result_str);

	return result_str;
}

// BINARY TO ...
string binaryToOcatl(string binary)
{
	vector<string> groupedBinStr = myGourpingStringByStep(binary, 3);
	string result = "";

	for (int i = 0; i < groupedBinStr.size(); i++) {
		string converVaectorItem = binaryToDecimal(groupedBinStr[i]);
		result += converVaectorItem;
	}
	return result;
}

// TODO
string binaryToHex(string binary)
{
	vector<string> groupedBinStr = myGourpingStringByStep(binary, 3);
	string result = "";
	return string();
}

string binaryToDecimal(string binary)
{
	int result = 0;
	string resultStr = "";
	for (int i = binary.size() - 1; i >= 0; i--) {
		char charVar = binary[binary.size() - i - 1];
		result = result + stoi(&charVar) * myPower(2, i);
	}
	resultStr = to_string(result);
	return resultStr;
}

// Service Functions
void  mySwap(char& char1, char& char2) {
	char temp = char1;
	char1 = char2;
	char2 = temp;
}

void myReverseString(string& base_str)
{
	int base_str_len = base_str.length();
	for (int i = 0; i < base_str_len / 2; ++i)
		mySwap(base_str[i], base_str[base_str_len - i - 1]);
}

// TODO Optimize this algorithm
// Sooooooooooooooooooooo Budge and Doubtful
vector<string> myGourpingStringByStep(string& base_str, int step)
{
	int base_str_len = base_str.length();
	string buff_str;
	vector<string> result_list;
	for (int i = 0; i <= base_str_len; i++) {
		if (i % step == 0 && buff_str != "") {
			// I can't reverse the base_str cuz this will reverse an outer string
			myReverseString(buff_str);
			result_list.push_back(buff_str);
			buff_str = "";
		}
		if (i != base_str_len) {
			buff_str += base_str[base_str_len - i - 1];
		}
	}
	// Think about this bodge
	if (buff_str != "") {
		if (buff_str.length() < step) {
			int insert_value = step - buff_str.length();
			buff_str.insert(buff_str.end(), insert_value, '0');
		}
		myReverseString(buff_str);
		result_list.push_back(buff_str);
	}
	reverse(result_list.begin(), result_list.end());
	return result_list;
}

int myPower(int base, int exponent) {
	int result = 1;
	if (exponent == 0)
		return result;
	for (int i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}