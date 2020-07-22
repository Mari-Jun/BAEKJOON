#include <iostream>

using namespace std;

int N, M, K;

int main() {
	cin >> N >> M >> K;
	
	while (K--) {
		if (M * 2 < N)
			N--;
		else
			M--;
	}
	if (N >= M * 2)
		cout << M;
	else
		cout << N / 2;
	return 0;
}