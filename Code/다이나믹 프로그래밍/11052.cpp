#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int P[1000];
int Cache[1000];

void Setting();
int DP(int Num);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	cout << DP(N);
	return 0;
}

void Setting() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> P[i];

	memset(Cache, -1, sizeof(Cache));
}

int DP(int Num) {

	if (Num == 0)
		return 0;
	
	int& ret = Cache[Num - 1];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < Num; i++) 
		ret = max(ret, P[i] + DP(Num - i - 1));

	return ret;
}