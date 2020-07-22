#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

int N, M, V;
bool Map[1000][1000], Check[1000];
queue<int> q;

void Setting();
void Solve();
void BFS();
void DFS(int Start);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	memset(Check, false, sizeof(Check));
	DFS(V-1);
	memset(Check, false, sizeof(Check));
	Solve();
	return 0;
}

void Setting() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int N1, N2;
		cin >> N1 >> N2;
		Map[N1 - 1][N2 - 1] = true;
		Map[N2 - 1][N1 - 1] = true;
	}
}

void Solve() {
	cout << endl;
	q.push(V - 1);
	Check[V - 1] = true;
	while (!q.empty()) 
		BFS();
}

void BFS() {
	int S = q.front();
	cout << S + 1 << ' ';
	q.pop();
	for(int i=0; i<N; i++)
		if (Map[S][i] && !Check[i]) {
			q.push(i);
			Check[i] = true;
		}
}

void DFS(int Start) {
	Check[Start] = true;
	cout << Start + 1 << ' ';
	for (int i = 0; i < N; i++)
		if (Map[Start][i] && !Check[i])
			DFS(i);
}