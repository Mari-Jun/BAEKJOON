#include <iostream>
#include <memory.h>

using namespace std;

bool Prime[1000000];

void Setting();
void Solve(int Number);


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(Prime, false, sizeof(Prime));
	Setting();

	int Number;

	while (cin>>Number) {
		if (Number == 0)
			break;
		Solve(Number);
	}

	return 0;
}

void Setting() {
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; j * i <= 1000000; j++) {
			//������׽��� ü�� �̿��� �Ҽ� ���ֱ�
			Prime[i * j - 1] = true;
		}
	}
	//1�� �Ҽ��� �ƴϱ� ������
	Prime[0] = true;
}

void Solve(int Number) {

	for (int Start = Number; Start >= Number/2; Start--) {
		if (!Prime[Start - 1] && !Prime[Number - Start - 1]) {
			cout << Number << " = " << Number - Start << " + " << Start << '\n';
			return;
		}
	}
}