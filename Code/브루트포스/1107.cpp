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
	//ù�� ° ������� +,-�� �̿��� ���
	return abs(N - 100);
}

int Second() {
	//���ڸ� ������ +,-�� ����� ���

	int Min = 500000;
	bool Pass = false;

	for (int i = 0; i <= 999999; i++) {
		string Num;
		Num = to_string(i);

		Pass = false;

		//�Է��� ������ �������� Ȯ���մϴ�.
		for (int s = 0; s < Num.length(); s++) {
			if (Broken[Num[s] - '0']) {
				Pass = true;
				break;
			}
		}
				
		//�Է��� �Ұ����ϴٸ� �� ���ڸ� Pass�մϴ�.
		if (Pass)
			continue;


		//�Է��� �����ϴٸ� �� ���ڸ� �����µ� ����� �Է°�, +,-�� �Է��� ���� ���� �ּڰ��� ���մϴ�.
		if (Min >= (int)Num.length() + abs(i - N))
			Min = (int)Num.length() + abs(i - N);

	}

	return Min;
}