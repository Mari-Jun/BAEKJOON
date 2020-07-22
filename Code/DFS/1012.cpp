#include <iostream>
#include <memory.h>

using namespace std;

const int Move[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int T, M, N, K;
bool Map[50][50];

void Setting();
bool RangeCheck(int y, int x);
void DFS(int y, int x);


int main() {
	cin >> T;
	while (T--) {
		cin.tie(NULL);
		ios::sync_with_stdio(false);
		Setting();
		int Sum = 0;
		for (int y = 0; y < N; y++) 
			for (int x = 0; x < M; x++) 
				if (Map[y][x]) {
					Map[y][x] = false;
					DFS(y, x);
					Sum++;
				}
		cout << Sum << '\n';
	}
	return 0;
}

void Setting() {
	memset(Map, false, sizeof(Map));
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		Map[y][x] = true;
	}
}

bool RangeCheck(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M || !Map[y][x])
		return false;
	return true;
}

void DFS(int y, int x) {
	for (int i = 0; i < 4; i++)
		if (RangeCheck(y + Move[i][0], x + Move[i][1])) {
			Map[y + Move[i][0]][x + Move[i][1]] = false;
			DFS(y + Move[i][0], x + Move[i][1]);
		}
}