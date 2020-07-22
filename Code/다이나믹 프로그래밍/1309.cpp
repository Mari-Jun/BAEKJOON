#include <iostream>
using namespace std;

const int MOD = 9901;
int N;
long long Num[100001];


int main() {
	Num[0] = 3;
	Num[1] = 7;
	cin >> N;
	if (N > 1)
		for (int i = 2; i < N; i++)
			Num[i] = (Num[i - 1] * 2 + Num[i - 2]) % MOD;
	cout << Num[N - 1];

	return 0;
}