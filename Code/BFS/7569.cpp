#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

struct Point {							//��ǥ�� ����
	int z;
	int y;
	int x;
};

const int Move[6][3] = { {0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0} };

int Tomato[100][100][100];				//�丶�� ����
int M, N, H;							//M : ����, N : ����, H : ����
queue<Point> q;

void Setting();							//���� �Է¹޴´�.
bool RangeCheck(int z, int y, int x);	//������ ������� �˻��Ѵ�.
bool VisitCheck(int z, int y, int x);	//�̹� �丶�䰡 �;����� Ȯ���Ѵ�
bool EndCheck();						//��� �丶�䰡 �;����� Ȯ���Ѵ�.

void Solve();
void BFS(int z, int y, int x);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	Solve();
	return 0;
}

void Setting() {
	cin >> M >> N >> H;

	int z, y, x;

	for (z = 0; z < H; z++) {
		for (y = 0; y < N; y++) {
			for (x = 0; x < M; x++) {
				cin >> Tomato[z][y][x];
				if (Tomato[z][y][x] == 1)
					//�丶�䰡 �ִ� ���¸� queue�� �ִ´�.
					q.push({ z,y,x });
			}
		}
	}	
}

bool RangeCheck(int z, int y, int x) {
	if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= H)
		//������ ����ٸ�
		return false;
	return true;
}

bool VisitCheck(int z, int y, int x) {
	if (Tomato[z][y][x] == 1 || Tomato[z][y][x] == -1)
		//�丶�䰡 ���� �����̰ų� �丶�䰡 ���ٸ�
		return false;
	return true;
}

bool EndCheck() {
	int z, y, x;

	for (z = 0; z < H; z++)
		for (y = 0; y < N; y++)
			for (x = 0; x < M; x++)
				if (Tomato[z][y][x] == 0)
					return false;
	return true;
}

void Solve() {
	int Day = 0;

	if (!EndCheck()) {
		//ó������ ��� ���°� �;����� �ʴٸ�
		while (!q.empty()) {
			int Size = q.size();

			while (Size--) {
				BFS(q.front().z, q.front().y, q.front().x);
			}

			Day++;

			if (EndCheck())
				break;
		}
	}

	//q�� empty�� �Ǿ �ݺ����� �������� �� ������
	if (EndCheck())
		cout << Day;
	else
		cout << "-1";
}

void BFS(int z, int y, int x) {
	//���� �ֱٿ� ���� ������ q�� Pop�Ѵ�.
	q.pop();

	//6������ �˻��Ѵ�.
	int zm, ym, xm;
	for (int i = 0; i < 6; i++) {
		zm = z + Move[i][0];
		ym = y + Move[i][1];
		xm = x + Move[i][2];

		if (RangeCheck(zm, ym, xm) && VisitCheck(zm, ym, xm)) {
			Tomato[zm][ym][xm] = 1;
			q.push({ zm,ym,xm });
		}
	}

}