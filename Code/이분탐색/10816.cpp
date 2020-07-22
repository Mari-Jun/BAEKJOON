#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

void Setting();
bool Checking1(int Mid, int Num);
bool Checking2(int Mid, int Num);
void Solve();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	Solve();
	return 0;
}

void Setting() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int Num;
		cin >> Num;
		v.push_back(Num);
	}
	sort(v.begin(), v.end());
}

bool Checking1(int Mid, int Num) {
	if (v[Mid] >= Num)
		return true;
	return false;
}

bool Checking2(int Mid, int Num) {
	if (v[Mid] <= Num)
		return true;
	return false;
}

void Solve() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		int Num;
		cin >> Num;
		int Result = 0;
		int lo = 0, hi = N-1;
		while (lo+1<hi) {
			int Mid = (lo + hi) / 2;
			if (Checking1(Mid, Num + 1))
				hi = Mid;
			else
				lo = Mid;
		}
		Result += lo;
		lo = 0, hi = N - 1;
		while (lo + 1 < hi) {
			int Mid = (lo + hi) / 2;
			if (Checking2(Mid, Num - 1))
				lo = Mid;
			else
				hi = Mid;
		}
		Result -= lo;
		if (Num == v[0])
			Result++;
		if (Num == v[N - 1])
			Result++;
		cout << Result << ' ';
	}
}