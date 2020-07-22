#include <iostream>
#include <algorithm>

using namespace std;

const int Block[19][4][2] = { { {0,0},{1,0},{0,1},{1,1} },{{0,0},{0,1},{0,2},{0,3}},{{0,0},{1,0},{2,0},{3,0}} ,{{0,0},{1,0},{2,0},{1,1}},{{0,0},{0,1},{0,2},{1,1}},{{0,0},{1,0},{2,0},{1,-1}},{{0,0},{0,1},{0,2},{-1,1}} ,{{0,0},{1,0},{1,1},{2,1}},{{0,0},{0,1},{-1,1},{-1,2}},{{0,0},{1,0},{1,-1},{2,-1}},{{0,0},{0,1},{1,1},{1,2}},{{0,0},{1,0},{2,0},{2,1}},{{0,0},{1,0},{0,1},{0,2}},{{0,0},{0,1},{1,1},{2,1}},{{0,0},{0,1},{0,2},{-1,2}} ,{{0,0},{1,0},{2,0},{2,-1}},{{0,0},{1,0},{1,1},{1,2}},{{0,0},{0,1},{1,0},{2,0}},{{0,0},{0,1},{0,2},{1,2}} };

int N, M;
int Map[500][500];

void Setting();
bool RangeCheck(int y, int x, int n);
int Solve();


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	cout << Solve();

	return 0;
}

void Setting() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> Map[y][x];
}

bool RangeCheck(int y, int x, int n) {
	//선택한 도형의 범위를 체크한다.
	for (int i = 0; i < 4; i++) {
		if (y + Block[n][i][0] < 0 || y + Block[n][i][0] >= N || x + Block[n][i][1] < 0 || x + Block[n][i][1] >= M)
			return false;
	}
	return true;
}

int Solve() {
	
	int Max = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			//모형의 개수는 19개임으로
			for (int n = 0; n < 19; n++) {
				//범위를 체크한다.
				if (RangeCheck(y, x, n)) {
					int Sum = 0;
					for (int s = 0; s < 4; s++)
						Sum += Map[y + Block[n][s][0]][x + Block[n][s][1]];
					Max = max(Max, Sum);
				}
			}
		}
	}
	return Max;
}