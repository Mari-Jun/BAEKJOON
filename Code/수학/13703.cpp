#include <iostream>
#include <memory.h>

using namespace std;

int K, N;
unsigned long long Live = 0;
unsigned long long Die[130][70];

unsigned long long Solve(int Depth, int Count);

int main() {
	cin >> K >> N;
	Live = ((unsigned long long)1 << N);
	memset(Die, -1, sizeof(Die));
	cout << Live - Solve(K, N);
	return 0;
}

unsigned long long Solve(int Depth, int Count) {
	if (Depth == 0)
		return (unsigned long long)1 << (Count);

	if (Count == 0)
		return 0;

	unsigned long long & ret = Die[Depth][Count];

	if (ret != -1)
		return ret;

	ret = 0;

	ret += Solve(Depth - 1, Count - 1);
	ret += Solve(Depth + 1, Count - 1);

	return ret;
}