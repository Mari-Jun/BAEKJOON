#include <iostream>
#include <algorithm>

using namespace std;

long long N, M, Max = 0;
long long Tree[1000000];

void Setting();
bool Cutting(long long MID);
long long Solve();


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	cout << Solve();
	return 0;
}

void Setting() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> Tree[i];
		Max = max(Max, Tree[i]);
	}
}

bool Cutting(long long MID) {
	long long Sum = 0;
	for (int i = 0; i < N; i++) {
		if (Tree[i] > MID) {
			Sum += Tree[i] - MID;
		}
		if (Sum >= M)
			return false;
	}
	return true;
}

long long Solve() {
	long long lo = 0, hi = Max;
	while (lo + 1 < hi) {
		long long Mid = (lo + hi) / 2;
		if (Cutting(Mid))
			hi = Mid;
		else
			lo = Mid;
	}
	return lo;
}