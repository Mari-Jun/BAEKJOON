#include <iostream>
#include <memory.h>
using namespace std;

const int MOD = 10007;

int Cache[1001][1001];
int N, K;

void Setting();
int Find(int N, int K);

int main() {
	cin >> N >> K;
	Setting();
	cout << Find(N, K);
	return 0;
}

void Setting() {
	memset(Cache, -1, sizeof(Cache));
	for (int i = 0; i <= 1000; i++) 
		Cache[i][0] = Cache[i][i] = 1;
}

int Find(int N, int K) {
	int& ret = Cache[N][K];
	if (ret != -1)
		return ret;
	return ret = (Find(N - 1, K) + Find(N - 1, K - 1)) % MOD;
}