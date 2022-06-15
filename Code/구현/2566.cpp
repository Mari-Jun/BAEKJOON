#include <iostream>
using namespace std;

int Base[9][9];
int Max = 0, RealMax = 0;
int RY = 1, RX = 1;

void Solve() {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> Base[y][x];
			Max = max(Max, Base[y][x]);
			if (Max != RealMax) {
				RealMax = Max;
				RY = y + 1;
				RX = x + 1;
			}
		}
	}
	cout << Base[RY - 1][RX - 1] << endl;
	cout << RY << ' ' << RX;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solve();
	return 0;
}