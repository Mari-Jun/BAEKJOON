#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	for (auto num = 1; num <= max(a, b); num++) {
		if (a % num == 0 && b % num == 0)
			cout << num << ' ' << a / num << ' ' << b / num << '\n';
	}

	return 0;
}