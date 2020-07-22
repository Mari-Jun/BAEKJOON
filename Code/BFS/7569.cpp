#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

struct Point {							//좌표값 저장
	int z;
	int y;
	int x;
};

const int Move[6][3] = { {0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0} };

int Tomato[100][100][100];				//토마토 저장
int M, N, H;							//M : 가로, N : 세로, H : 높이
queue<Point> q;

void Setting();							//맵을 입력받는다.
bool RangeCheck(int z, int y, int x);	//범위를 벗어나는지 검사한다.
bool VisitCheck(int z, int y, int x);	//이미 토마토가 익었는지 확인한다
bool EndCheck();						//모든 토마토가 익었는지 확인한다.

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
					//토마토가 있는 상태면 queue에 넣는다.
					q.push({ z,y,x });
			}
		}
	}	
}

bool RangeCheck(int z, int y, int x) {
	if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= H)
		//범위를 벗어난다면
		return false;
	return true;
}

bool VisitCheck(int z, int y, int x) {
	if (Tomato[z][y][x] == 1 || Tomato[z][y][x] == -1)
		//토마토가 익은 상태이거나 토마토가 없다면
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
		//처음부터 모든 상태가 익어있지 않다면
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

	//q가 empty가 되어서 반복문을 빠져나올 수 있으니
	if (EndCheck())
		cout << Day;
	else
		cout << "-1";
}

void BFS(int z, int y, int x) {
	//가장 최근에 값을 전달한 q를 Pop한다.
	q.pop();

	//6방향을 검사한다.
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