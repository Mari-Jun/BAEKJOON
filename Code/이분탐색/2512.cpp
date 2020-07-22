#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int Base[10000];

void Setting();
bool Cut(int Mid);
int Solve();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	cout << Solve();
	return 0;
}

void Setting() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Base[i];
	cin >> M;
}

bool Cut(int Mid) {
	int Sum = 0;
	for (int i = 0; i < N; i++) {
		if (Base[i] <= Mid)
			Sum += Base[i];
		else
			Sum += Mid;
		if (Sum >= M)
			return true;
	}
	return false;
}

int Solve() {
	int Sum = 0, Max = 0;
	for (int i = 0; i < N; i++) {
		Sum += Base[i];
		Max = max(Base[i], Max);
	}
	if (Sum <= M)
		return Max;

	int lo = 0; int hi = 100000;
	while (lo + 1 < hi) {
		int Mid = (lo + hi) / 2;
		if (Cut(Mid))
			hi = Mid;
		else
			lo = Mid;
	}
	Sum = 0;
	for (int i = 0; i < N; i++) {
		if (Base[i] <= hi)
			Sum += Base[i];
		else
			Sum += hi;
	}
	if (Sum == M)
		return hi;
	return lo;
}