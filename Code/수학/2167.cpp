#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int Map[300][300];
int N, M, K;

void Setting();
void Solve();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	Solve();
	return 0;
}

void Setting() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> Map[y][x];

	for(int y=0; y<N; y++)
		for (int x = 0; x < M; x++) {
			if (x != 0)
				Map[y][x] += Map[y][x - 1];
			if (y != 0)
				Map[y][x] += Map[y - 1][x];
			if (x != 0 && y != 0)
				Map[y][x] -= Map[y - 1][x - 1];
		}		
}
void Solve() {
	cin >> K;
	while (K--) {
		int i, j, x, y;
		cin >> j >> i >> y >> x;

		int Answer = Map[y - 1][x - 1];
		if (i - 1 != 0)
			Answer -= Map[y - 1][i - 2];
		if (j - 1 != 0)
			Answer -= Map[j - 2][x - 1];
		if (i - 1 != 0 && j - 1 != 0)
			Answer += Map[j - 2][i - 2];

		cout << Answer << '\n';
	}
}