#include <iostream>
#include <queue>

using namespace std;

const int Move[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int N, M;
int Map[1000][1000];
queue<pair<int, int>> q;

void Input();
int Solve();
bool Check(int y, int x);
void BFS(int y, int x);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Input();
	cout << Solve();
	return 0;
}

void Input() {
	cin >> M >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			cin >> Map[y][x];
			if (Map[y][x] == 1)
				q.push(make_pair(y, x));
		}

}

int Solve() {
	if (q.size() == N * M)
		return 0;

	int Day = 0;

	while (!q.empty()) {
		int Size = q.size();
		while (Size--) {
			BFS(q.front().first, q.front().second);
			if (q.empty())
				break;
		}
		Day++;
	}

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (Map[y][x] == 0)
				return -1;

	return Day - 1;
}

bool Check(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M || Map[y][x] == -1 || Map[y][x] == 1)
		return false;
	return true;
}

void BFS(int y, int x) {

	q.pop();

	for (int i = 0; i < 4; i++) {
		int My = y + Move[i][0], Mx = x + Move[i][1];
		if (Check(My, Mx)) {
			q.push(make_pair(My, Mx));
			Map[My][Mx] = 1;
		}
	}
}