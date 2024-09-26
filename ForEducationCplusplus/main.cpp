#include "Converters.h"

using namespace std;

void TestFunc();

int main() {
	
	TestFunc();

	return 0;
}

void TestFunc()
{
	string inputParam = "10001011";
	string outputResult = binaryToOcatl(inputParam);
	string expectedParam = "213";

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