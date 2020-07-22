#include <iostream>

using namespace std;

int main() {

	int a, d, k;
	cin >> a >> d >> k;

	int result = (k - a) / d;
	int nokori = (k - a) % d;

	if (k == a)
		cout << "1";
	else if (result <= 0 || nokori != 0)
		cout << "X";
	else
		cout << result + 1;

	return 0;
}