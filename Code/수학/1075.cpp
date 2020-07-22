#include <iostream>

using namespace std;

int main() {

	int N, F;
	
	cin >> N >> F;

	for (int i = 0; i < 100; i++) {
		if ((N / 100 * 100 + i) % F == 0) {
			cout.width(2);
			cout.fill('0');
			cout << (N / 100 * 100 + i) % 100 << endl;
			break;
		}
	}

	return 0;
}