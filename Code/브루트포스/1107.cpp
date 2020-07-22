#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
bool Broken[10];

void Setting();
int First();
int Second();

int main() {
	Setting();
	cout << min(First(), Second());
	return 0;
}

void Setting() {
	cin >> N >> M;
	while (M--) {
		int Num;
		cin >> Num;
		Broken[Num] = true;
	}
}


int First() {
	//첫번 째 방법으로 +,-만 이용한 결과
	return abs(N - 100);
}

int Second() {
	//숫자를 누른후 +,-를 사용한 결과

	int Min = 500000;
	bool Pass = false;

	for (int i = 0; i <= 999999; i++) {
		string Num;
		Num = to_string(i);

		Pass = false;

		//입력이 가능한 숫자인지 확인합니다.
		for (int s = 0; s < Num.length(); s++) {
			if (Broken[Num[s] - '0']) {
				Pass = true;
				break;
			}
		}
				
		//입력이 불가능하다면 이 숫자를 Pass합니다.
		if (Pass)
			continue;


		//입력이 가능하다면 이 숫자를 누르는데 사용한 입력과, +,-의 입력의 합을 구해 최솟값과 비교합니다.
		if (Min >= (int)Num.length() + abs(i - N))
			Min = (int)Num.length() + abs(i - N);

	}

	return Min;
}