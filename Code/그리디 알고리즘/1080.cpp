#include <iostream>

using namespace std;

int N, M;
string A[50], B[50];

void Setting();
bool CheckAB();
int Reverse();

int main() {
	Setting();
	cout << Reverse();
	return 0;
}

void Setting() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		cin >> A[y];
	for (int y = 0; y < N; y++)
		cin >> B[y];
}

bool CheckAB() {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (A[y][x] != B[y][x])
				return false;
	return true;
}

int Reverse() {
	int Sum = 0;

	if (N < 3 || M < 3) {
		if (CheckAB())
			return 0;
	}
		

	for (int y = 0; y <= N - 3; y++) {
		for (int x = 0; x <= M - 3; x++) {
			if (CheckAB())
				return Sum;
			if (A[y][x] == B[y][x])
				continue;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					if (A[y + i][x + j] == '1')
						A[y + i][x + j] = '0';
					else
						A[y + i][x + j] = '1';
				}		
			Sum++;
		}
	}
	if (CheckAB())
		return Sum;
	else
		return -1;
	return Sum;
}