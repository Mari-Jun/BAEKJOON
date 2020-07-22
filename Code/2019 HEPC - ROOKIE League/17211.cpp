#include <iostream>

using namespace std;

double P[2][2];
double Result[100][2];
double Answer[2];
int N, GB;

void Solve(int Day, int GB, double Per);

int main() {
	cin >> N >> GB;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cin >> P[i][j];

	if (GB == 0) {
		Result[0][0] = P[0][0];
		Result[0][1] = P[0][1];
	}
	else {
		Result[0][0] = P[1][0];
		Result[0][1] = P[1][1];
	}
	
	for (int i = 1; i < N; i++) {
		Result[i][0] = Result[i - 1][0] * P[0][0] + Result[i - 1][1] * P[1][0];
		Result[i][1] = Result[i - 1][1] * P[1][1] + Result[i - 1][0] * P[0][1];

	}

	cout << static_cast<int>((Result[N-1][0] + 0.0005) * 1000) << endl;
	cout << static_cast<int>((Result[N-1][1] + 0.0005) * 1000) << endl;
}

