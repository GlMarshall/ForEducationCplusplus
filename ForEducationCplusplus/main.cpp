#include "Converters.h"

using namespace std;

void TestFunc();

#pragma region Tasks

void task1() {
	for (int a = 1; a <= 1000; a++) {
		for (int x = 1; x <= 12; x++) {
			int m = 4 * pow(12, 4) + 9 * pow(12, 3) + x * pow(12, 2) + 2 * 12 + 6;
			int n = 4 * pow(12, 4) + 9 * pow(12, 3) + x * pow(12, 2) + 7 * 12 + 0;
			int res = m + a;
			if ((res % n) == 0)
				cout << a << endl;
				break;
		}
	}
 }

void task2() {
	int x, y, p;
	for (p = 10; p < 62; p++) {
		for (x = 0; x < p; x++) {
			for (y = 0; y < p; y++) {
				long long int a = 3 * pow(p, 3) + 2 * pow(p, 2) + x * p + 8;
				long long int b = x * pow(p, 3) + x * pow(p, 2) + x * p + 9;
				long long int c = y * pow(p, 3) + y * pow(p, 2) + 0 + 2;
				if ((a + b) == c) {
					long long int result = y * pow(p, 2) + y * p + x;
					cout << result << endl;
				}
			}
		}
	}
}

void task3() {
	// Find out how to work with very big int
	unsigned long long int calc =
		3 * pow(3125, 8) + 2 * pow(625, 7) - 4 * pow(625, 6) + 3 * pow(125, 5) - 2 * pow(25, 4) - 2024;
	int count = 0;
	while (calc > 0) {
		int rem = calc % 25;
		calc = calc / 25;
		if (rem == 0)
			count++;
	}
	cout << count << endl;
}

// EXAM
void taskExa1() {

}

#pragma endregion


int main() {
	
	taskExa1();

	return 0;
}

void TestFunc()
{
	string inputParam = "345";
	string outputResult = octalToBinary(inputParam);
	string expectedParam = "11100101";

	bool result = outputResult == expectedParam;

	if (result == 1) {
		cout << "Ok" << endl;
		cout <<
			"Expected Param -> " + expectedParam + "\n"
			"Output Param -> " + outputResult + "\n";
	}
	else {
		cout << "Not Ok" << endl;
		cout <<
			"Expected Param -> " + expectedParam + "\n"
			"Output Param -> " + outputResult + "\n";
	}
}