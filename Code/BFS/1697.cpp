#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool Check[100001];
queue<int> q;

void Solve();
bool Checking(int s);
void BFS();

int main() {
	cin >> N >> K;
	Solve();
	return 0;
}

void Solve() {
	q.push(N);
	Check[N] = true;
	int Sum = 0;
	while (!q.empty()) {
		int Size = q.size();
		while (Size--) {
			BFS();
			if (q.empty())
				break;
		}
		Sum++;
	}
	cout << Sum - 1;
}

bool Checking(int s) {
	if (s < 0 || s>100000 || Check[s])
		return false;
	return true;
}

void BFS() {
	int s = q.front();

	if (s == K) {
		while (!q.empty())
			q.pop();
		return;
	}

	q.pop();

	if (Checking(s + 1)) {
		q.push(s + 1);
		Check[s + 1] = true;
	}
	if (Checking(s * 2)) {
		q.push(s * 2);
		Check[s * 2] = true;
	}
	if (Checking(s - 1)) {
		q.push(s - 1);
		Check[s - 1] = true;
	}
}