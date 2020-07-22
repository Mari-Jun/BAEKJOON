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

	//앞의 숫자가 뒤의 숫자보다 작을 경우
	if (Number[Front] < Number[Before]) {

		bool Pass = false;
		//제일 뒤에서 부터 Front값보다 큰 값을 찾는다.
		for (int Start = N - 1; Start >= Before; Start--) {
			if (Number[Front] < Number[Start]) {
				//큰값을 찾는다면 그 값과 Front값을 바꾼다.

				int Ret = Number[Front];
				Number[Front] = Number[Start];
				Number[Start] = Ret;

				Pass = true;

				break;
			}
			if (Pass)
				break;
		}


		//그후 Before부터 끝까지 오름차순으로 정렬해준다.
		sort(Number + Before, Number + N);

		return true;
	}
	//앞의 숫자가 뒤의 숫자보다 클 경우
	else {
		return Solve(Front - 1, Before - 1);
	}
}