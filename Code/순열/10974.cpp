#include <iostream>
#include <algorithm>

using namespace std;

int N;
int Number[10000];

bool Solve(int Front, int Before);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		Number[i] = i + 1;

	do {
		for (int i = 0; i < N; i++)
			cout << Number[i] << ' ';
		cout << '\n';
	} while (Solve(N - 2, N - 1));

	return 0;
}

bool Solve(int Front, int Before) {

	if (Front == -1)
		return false;

	//���� ���ڰ� ���� ���ں��� ���� ���
	if (Number[Front] < Number[Before]) {

		bool Pass = false;
		//���� �ڿ��� ���� Front������ ū ���� ã�´�.
		for (int Start = N - 1; Start >= Before; Start--) {
			if (Number[Front] < Number[Start]) {
				//ū���� ã�´ٸ� �� ���� Front���� �ٲ۴�.

				int Ret = Number[Front];
				Number[Front] = Number[Start];
				Number[Start] = Ret;

				Pass = true;

				break;
			}
			if (Pass)
				break;
		}


		//���� Before���� ������ ������������ �������ش�.
		sort(Number + Before, Number + N);

		return true;
	}
	//���� ���ڰ� ���� ���ں��� Ŭ ���
	else {
		return Solve(Front - 1, Before - 1);
	}
}