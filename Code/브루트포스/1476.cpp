#include <iostream>

using namespace std;

int main() {
	int E, S, M, Y = 0;

	cin >> E >> S >> M;

	while (1) {
		if (Y % 15 == E - 1 && Y % 28 == S - 1 && Y % 19 == M - 1) {
			cout << Y + 1;
			break;
		}
		Y++;
	}
}