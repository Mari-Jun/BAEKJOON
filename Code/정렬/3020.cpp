#include <iostream>
#include <algorithm>

using namespace std;

int N, H;
int Min = 0, BMin = 0;
int Count = 0;

int Map[500000][2];

void Setting();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	return 0;
}

void Setting() {
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		int Num;
		cin >> Num;
		Map[Num - 1][i % 2]++;
	}

	int Sum = N / 2;
	Min = BMin = Sum;
	Count++;

	for (int i = 0; i < H - 1; i++) {
		Sum -= Map[i][0];
		Sum += Map[H - 2 - i][1];
		Min = min(Min, Sum);
		if (Sum < BMin) {
			Count = 1;
			BMin = Min;
		}
		else if (Sum == BMin) {
			Count++;
		}
	}

	cout << Min << ' ' << Count;
}