#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int Floor[300];
int Cache[301][3];

void Setting();
int DP(int F, int Count);

int main() {
	Setting();
	cout << DP(-1, 0);
	return 0;
}

void Setting() {
	memset(Cache, -1, sizeof(Cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Floor[i];
}

int DP(int F, int Count) {

	if (Count == 3)
		return -100000000;

	if (F == N)
		return -100000000;

	if (F == N - 1)
		return 0;

	int& ret = Cache[F + 1][Count];

	if (ret != -1)
		return ret;

	ret = max(DP(F + 2, 1) + Floor[F + 2], DP(F + 1, Count + 1) + Floor[F + 1]);

	return ret;
}