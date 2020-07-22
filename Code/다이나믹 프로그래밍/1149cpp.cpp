#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

const int Max = 1000 * 1100;

int N;
int Cache[1011][3], Map[1000][3];

void Setting();
int DP(int House, int Color);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	int Result = Max;
	for (int Color = 0; Color < 3; Color++)
		Result = min(Result, DP(-1, Color));
	cout << Result;
	return 0;
}

void Setting() {
	cin >> N;
	memset(Cache, -1, sizeof(Cache));
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < 3; j++)
			cin >> Map[i][j];
}

int DP(int House, int Color) {
	if (House == N - 1)
		return 0;

	int& ret = Cache[House + 1][Color];

	if (ret != -1)
		return ret;

	ret = Max;

	for (int i = 0; i < 3; i++)
		if (i != Color)
			ret = min(ret, DP(House + 1, i) + Map[House + 1][Color]);

	return ret;
}