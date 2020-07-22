#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, M;
int Map[1000][1000];
int Cache[1000][1000][3];
bool Visit[1000][1000];

const int CMin = -10000000;

const int Move[3][2] = { {1,0},{0,-1},{0,1} };

void Setting();
bool Check(int y, int x);
int DP(int y, int x, int b);

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Setting();

	Visit[0][0] = true;
	
	cout << DP(0, 0, 0);

	return 0;
}

void Setting() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> Map[y][x];

	for (int b = 0; b < 3; b++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				Cache[y][x][b] = CMin;

	memset(Visit, 0, sizeof(Visit));
}

bool Check(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M)
		return false;
	return true;
}

int DP(int y, int x, int b) {
	int& ret = Cache[y][x][b];

	if (ret != CMin)
		return ret;

	if (y == N - 1 && x == M - 1)
		return Map[y][x];


	for (int i = 0; i < 3; i++) {
		if (Check(y + Move[i][0], x + Move[i][1]) && !Visit[y + Move[i][0]][x + Move[i][1]]) {
			Visit[y + Move[i][0]][x + Move[i][1]] = true;
			ret = max(ret, Map[y][x] + DP(y + Move[i][0], x + Move[i][1], i));
			Visit[y + Move[i][0]][x + Move[i][1]] = false;
		}
	}

	return ret;
}