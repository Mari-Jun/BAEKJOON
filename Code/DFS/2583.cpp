#include <iostream>
#include <memory.h>
#include <set>

using namespace std;

const int Move[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool Map[100][100];
int M, N, K;
multiset<int> s;

void Setting();
bool RangeCheck(int y, int x);
int DFS(int y, int x);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
		
	for (int y = 0; y < M; y++)
		for (int x = 0; x < N; x++) {
			if (RangeCheck(y, x)) {
				Map[y][x] = true;
				s.insert(DFS(y, x));
			}
		}
	cout << s.size() << endl;
	for (multiset<int>::iterator iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';
	return 0;
}

void Setting() {
	memset(Map, false, sizeof(Map));
	cin >> M >> N >> K;
	while (K--) {
		int LUX, LUY, RDX, RDY;
		cin >> LUX >> LUY >> RDX >> RDY;
		for (int y = LUY; y < RDY; y++)
			for (int x = LUX; x < RDX; x++)
				Map[y][x] = true;
	}
}

bool RangeCheck(int y, int x) {
	if (y < 0 || x < 0 || y >= M || x >= N || Map[y][x])
		return false;
	return true;
}

int DFS(int y, int x) {

	int ret = 1;

	for (int i = 0; i < 4; i++) {
		if (RangeCheck(y + Move[i][0], x + Move[i][1])) {
			Map[y + Move[i][0]][x + Move[i][1]] = true;
			ret += DFS(y + Move[i][0], x + Move[i][1]);
		}
	}

	return ret;
}