#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int N;
multiset<pair<int, int>> s;

void Input();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Input();
	int Early = -1, Select = 0;
	int* C = 0;
	(*C)++;


	for (multiset<pair<int, int>>::iterator iter = s.begin(); iter != s.end(); iter++) {
		int Begin = (*iter).second, End = (*iter).first;

		if (Early <= Begin) {
			Early = End;
			Select++;
		}
	}
	cout << Select;
	return 0;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int Begin, End;
		cin >> Begin >> End;
		s.insert(make_pair(End,Begin));
	}
}