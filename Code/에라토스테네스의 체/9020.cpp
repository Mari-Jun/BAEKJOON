#include <iostream>
#include <memory.h>

using namespace std;

bool Prime[10000];



void Setting();
void Solve(int Number);


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(Prime, false, sizeof(Prime));
	Setting();

	int T, Number;

	cin >> T;
	while (T--) {
		cin >> Number;
		Solve(Number);
	}

	return 0;
}

void Setting() {
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j * i <= 10000; j++) {
			//에레토네스의 체를 이용한 소수 없애기
			Prime[i * j - 1] = true;
		}
	}
	//1은 소수가 아니기 때문에
	Prime[0] = true;
}

void Solve(int Number) {

	for (int Start = Number / 2; Start <= Number; Start++) {
		if (!Prime[Start - 1] && !Prime[Number - Start - 1]) {
			cout << Number - Start << ' ' << Start << '\n';
			return;
		}
	}
}