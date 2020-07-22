#include <iostream>
#include <algorithm>

using namespace std;

const int Move[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int R, C;
char Base[20][20];
bool Check[20][20];
bool ALCheck[26];

void Setting();
bool RangeCheck(int y, int x);
int Solve(int y, int x);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	cout << Solve(0, 0);
	return 0;
}

void Setting() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> Base[r][c];
		}
	}
}

bool RangeCheck(int y, int x) {
	if (y < 0 || y >= R || x < 0 || x >= C || Check[y][x] || ALCheck[Base[y][x]-'A'])
		return false;
	return true;
}

int Solve(int y, int x) {
	int ret = 1;

	Check[y][x] = true;
	ALCheck[Base[y][x] - 'A'] = true;

	int My, Mx;
	for (int i = 0; i < 4; i++) {
		My = y + Move[i][0];
		Mx = x + Move[i][1];
		if (RangeCheck(My, Mx)) {
			ret = max(ret, 1 + Solve(My, Mx));
		}
	}

	ALCheck[Base[y][x] - 'A'] = false;
	Check[y][x] = false;

	return ret;
}