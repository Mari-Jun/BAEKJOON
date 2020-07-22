#include <iostream>
#include <queue>

using namespace std;

int S;
bool Visit[1001][1001];
queue<pair<int,int>> q;

int Solve();
void BFS(int Num, int Copy);

int main() {
	cin >> S;
	cout << Solve();
	return 0;
}

int Solve() {

	//ó�� �̸�Ƽ�� 1���� �⺻���� �����Ƿ�
	Visit[1][0] = true;

	//make_pair(�̸�Ƽ�� ����, Ŭ�����忡 ����� �̸�Ƽ�� ��)
	q.push(make_pair(1, 0));

	int Time = 0, Size = 0;

	while (!q.empty()) {

		//���� queue�� ����� �����Ѵ�.
		Size = q.size();

		//�� �ð������� ����� ���� ��� ����Ѵ�.
		while (Size--) {
			BFS(q.front().first, q.front().second);

			//���� ���ϴ� �̸�Ƽ�ܸ�ŭ �����ߴٸ�
			if (q.empty())
				break;

			q.pop();
		}
		if (q.empty())
			break;

		//�� Size��ŭ�� Roop�Ҷ����� �ð��� 1�ʾ� �����մϴ�.
		Time++;
	}

	//�ּ� �ð��� ��ȯ�Ѵ�.
	return Time;
}

void BFS(int Num, int Copy) {
	if (Num == S) {
		//���� ���� ������ ���
		while (!q.empty())
			q.pop();
		return;
	}

	if (Num == 1) {
		//ó���Ҽ� �ִ� ������ 1�� ����ۿ� �����Ƿ�
		if (Copy == 0) {
			q.push(make_pair(Num, Num));
		}
		//�ι�°�� �Ҽ� �ִ� ������ 2�� �ٿ��ֱ� �Դϴ�.
		else {
			q.push(make_pair(Num + Copy, Copy));
			//2���� �̸�Ƽ���� ���������� �����Ƿ� �湮�� üũ�Ѵ�.
			Visit[Num + Copy][Copy] = true;
		}
	}
	else {
		//1�� ������ �����Ѵ�.
		q.push(make_pair(Num, Num));

		//2�� ������ �����Ѵ�.
		if (Num + Copy < 1001 && !Visit[Num + Copy][Copy]) {
			//���� �湮�� ���� ���ٸ� //�ٿ��ֱ⸦ �����մϴ�.
			q.push(make_pair(Num + Copy, Copy));
			Visit[Num + Copy][Copy] = true;
		}

		//3�� ������ �����Ѵ�.
		if (Num > 1 && !Visit[Num - 1][Copy]) {
			//���� �湮�� ���� ���ٸ� �̸�Ƽ�� 1���� �����մϴ�.
			q.push(make_pair(Num - 1, Copy));
			Visit[Num - 1][Copy] = true;
		}
		
	}
}