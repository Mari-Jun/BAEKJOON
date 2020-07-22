#include <iostream>
#include <memory.h>

using namespace std;

long long cache[100010][4];

void ResetCache();
long long Calcul(int number, int before_num);

int main() {

	ResetCache();
	int test_case = 0;
	cin >> test_case;

	while (test_case--) {
	
		int number = 0;
		cin >> number;
		cout << Calcul(number, 0) << endl;
	}	

	return 0;
}

void ResetCache() {
	memset(cache, -1, sizeof(cache));
}

long long Calcul(int number, int before_num) {
	if (number == 0)
		return 1;

	long long& ret = cache[number][before_num];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int minus = 1; minus <= 3; minus++) {
		if (number - minus >= 0 && minus != before_num) {
			ret += Calcul(number - minus, minus);
			ret %= 1000000009;
		}
	}

	return ret;
}