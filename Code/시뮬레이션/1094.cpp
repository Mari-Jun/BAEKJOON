#include <iostream>

using namespace std;

int X, Count = 0;

int main() {
	cin >> X;

	for (int i = 6; i >= 0; i--) {
		if (X >= 1 << i) {
			Count++;
			X -= 1 << i;
		}
		if (X == 0)
			break;
	}

	cout << Count;
	return 0;
}
