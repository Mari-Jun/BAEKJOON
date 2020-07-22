#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

int N, M, R, Max = 0;
int Item[100], Connect[100][100], Length[100];
queue<int> q;

void Setting();
void DIJ(int First, int Start);
int Checking();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			Length[j] = 1000 * 1000;
		while (!q.empty())
			q.pop();

		q.push(i);
		Length[i] = 0;
		while (!q.empty()) 
			DIJ(i, q.front());
		
		Max = max(Max, Checking());
	}
	cout << Max;
	return 0;
}

void Setting() {
	memset(Connect, 0, sizeof(Connect));

	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
		cin >> Item[i];
	for (int i = 0; i < R; i++) {
		int S, E;
		cin >> S >> E;
		cin >> Connect[S - 1][E - 1];
		Connect[E - 1][S - 1] = Connect[S - 1][E - 1];
	}
}

void DIJ(int First, int Start) {
	q.pop();

	for (int i = 0; i < N; i++) {
		if (Connect[Start][i] != 0 && i!=First) {
			if (Connect[Start][i] + Length[Start] < Length[i]) {
				Length[i] = Length[Start] + Connect[Start][i];
				q.push(i);
			}
		}
	}


}

int Checking() {
	int Sum = 0;
	for (int i = 0; i < N; i++)
		if (Length[i] <= M)
			Sum += Item[i];
	
	return Sum;
}