#include <iostream>

using namespace std;

bool Student[30];

int main() {
	for (int i = 0; i < 28; i++) {
		int Num;
		cin >> Num;
		Student[Num - 1] = true;
	}
	for (int i = 0; i < 30; i++)
		if (!Student[i])
			cout << i + 1 << '\n';
	return 0;
}