#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

const int Move[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int N;
int Map[500][500], Cache[501][501];

void Setting();
bool Check(int y, int x);
int Solve(int y, int x);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	int Max = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			Max = max(Max, Solve(y, x));
	cout << Max;
	return 0;
}

void Setting() {
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> Map[y][x];

	memset(Cache, -1, sizeof(Cache));
}

int Solve(int y, int x) {
	int& ret = Cache[y][x];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int i = 0; i < 4; i++) {
		int My = y + Move[i][0], Mx = x + Move[i][1];
		if (Check(My, Mx) && Map[y][x] < Map[My][Mx])
			ret = max(ret, Solve(My, Mx) + 1);
	}

	return ret;
}

bool Check(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}