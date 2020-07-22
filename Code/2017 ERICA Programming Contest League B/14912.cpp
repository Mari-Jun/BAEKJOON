#include <iostream>
#include <string>

using namespace std;

int FindDigitForNumber(int num, int digit);

int main() {

	int number, digit;
	cin >> number >> digit;

	cout << FindDigitForNumber(number, digit);

	return 0;
}

int FindDigitForNumber(int num, int digit) {
	int result = 0;
	for (auto cur = 1; cur <= num; cur++) {
		string cur_str = to_string(cur);
		for (auto i = 0; i < cur_str.length(); i++)
			if (cur_str[i] == digit + '0')
				result++;
	}
	return result;
}