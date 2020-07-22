#include <iostream>
#include <memory.h>

using namespace std;

int N;
bool NumCheck[15][15];

int Solve(int y);

int main() {
	memset(NumCheck, false, sizeof(NumCheck));

	cin >> N;
	
	cout << Solve(-1);

	return 0;

}

int Solve(int y) {
	if (y >= N - 1)
		return 1;
	else {
		int Sum = 0;

		for (int x = 0; x < N; x++) {

			bool Pass = true;

			for (int i = 0; i < y+1; i++)
				if (NumCheck[i][x]) {
					Pass = false;
					break;
				}

			if (Pass) {
				int a = y + 1, b = x;
				while (a >= 0 && b >= 0) {
					if (NumCheck[a][b]) {
						Pass = false;
						break;
					}
					a--;
					b--;
				}
			}

			if (Pass) {
				int a = y + 1, b = x;
				while (a >= 0 && b < N) {
					if (NumCheck[a][b]) {
						Pass = false;
						break;
					}
					a--;
					b++;
				}
			}

			if (!Pass) 
				continue;			

			NumCheck[y + 1][x] = true;

			Sum += Solve(y + 1);

			NumCheck[y + 1][x] = false;
		}
		return Sum;
	}
}