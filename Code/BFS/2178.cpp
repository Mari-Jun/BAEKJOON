#include <iostream>
#include <queue>

using namespace std;

int N, M;
const int Move[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
char Map[100][100];
queue<pair<int, int>> q;

void Input();
bool Check(int y, int x);
int Solve();
void BFS(int y, int x);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Input();
	cout << Solve();
	return 0;
}

void Input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> Map[y][x];
}

bool Check(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M || Map[y][x] == '0')
		return false;
	return true;
}

int Solve() {
	int Count = 0;
	q.push(make_pair(0, 0));
	Map[0][0] = '0';
	while (!q.empty()) {
		int Size = q.size();
		while (Size--) {
			BFS(q.front().first, q.front().second);
			if (q.empty())
				break;
		}
		Count++;
	}
	return Count;
}

void BFS(int y, int x) {
	q.pop();
	if (y == N - 1 && x == M - 1) {
		while (!q.empty())
			q.pop();
		return;
	}

	for (int i = 0; i < 4; i++)
		if (Check(y + Move[i][0], x + Move[i][1])) {
			q.push(make_pair(y + Move[i][0], x + Move[i][1]));
			Map[y + Move[i][0]][x + Move[i][1]] = '0';
		}
}