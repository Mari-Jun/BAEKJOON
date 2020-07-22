#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

multiset<int,greater<int>> s;
int N;

void Input();
int Solve();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Input();
	cout << Solve();
	return 0;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int Num;
		cin >> Num;
		s.insert(Num);
	}
}

int Solve() {
	int Count = 0;
	int Sum = 0;
	int Aver = 0;
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		if (Sum != 0) {
			Count++;
			Aver = (*iter) * Count;
			Sum = max(Sum, Aver);
		}
		else {
			Sum = *iter;
			Count++;
		}
	}
	return Sum;
}