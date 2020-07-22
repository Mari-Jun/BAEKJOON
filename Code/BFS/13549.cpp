#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<pair<int, int>> q;
bool Check[100001];

bool Checking(int N);
bool BFS();

int main() {
	cin >> N >> K;

	q.push(make_pair(N, 0));

	while (!BFS());

	cout << q.front().second;

	return 0;
}

bool Checking(int N) {
	if (N < 0 || N>100000 || Check[N])
		return false;
	return true;
}

bool BFS() { 
	if (q.front().first == K) 
		return true;

	int Num = q.front().first;
	int Time = q.front().second;
	q.pop();

	if (Checking(Num * 2)) {
		q.push(make_pair(Num * 2, Time));
		Check[Num * 2] = true;
	}

	if (Checking(Num - 1)) {
		q.push(make_pair(Num - 1, Time + 1));
		Check[Num - 1] = true;
	}
		
	if (Checking(Num + 1)) {
		q.push(make_pair(Num + 1, Time + 1));
		Check[Num + 1] = true;
	}

	return false;
}