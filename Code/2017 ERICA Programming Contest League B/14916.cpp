#include <iostream>
#include <algorithm>

using namespace std;

int FindMinNum(int number);

int main() {

	int number;
	cin >> number;
	cout << FindMinNum(number);

	return 0;
}

int FindMinNum(int number) {

	int count = 100000;
	
	for (int i = 0; i * 5 <= number; i++) {
		if ((number - i * 5) % 2 == 0)
			count = min(count, i + (number - i * 5) / 2);
	}

	if (count == 100000)
		return -1;
	return count;
}