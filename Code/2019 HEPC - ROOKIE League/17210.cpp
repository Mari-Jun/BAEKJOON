#include <iostream>

using namespace std;

int main() {

	long long N;
	cin >> N;

	int First;
	cin >> First;

	if (N > 5)
		cout << "Love is open door";
	else {
		for (int i = 1; i < N; i++) {
			First = 1 - First;
			cout << First << endl;
		}
	}

	return 0;
}