#include <iostream>

using namespace std;

long long Solve(int N, int M);

int main() {
	int N, M;
	cin >> N >> M;

	cout << Solve(M - 1, M - N);

	return 0;
}

long long Solve(int N, int M) {
	if (N / 2 < M)
		M = (N - M);

	long long Up = 1, Down = 1;

	for (int i = 0; i < M; i++) {
		Up *= (N - i);
		Down *= (M - i);
	}

	return Up / Down;
}