#include <iostream>
#include <set>

using namespace std;

const int Move[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int N;
char Map[25][25];
multiset<int> s;

void Setting();
bool RangeCheck(int y, int x);
int DFS(int y, int x);


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (Map[y][x] == '1') {
				Map[y][x] = '0';
				s.insert(DFS(y, x));
			}
	cout << s.size() << '\n';
	for (multiset<int>::iterator iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << '\n';
	return 0;
}

void Setting() {
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> Map[y][x];
}

bool RangeCheck(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N)
		return false;
	return true;
}

int DFS(int y, int x) {

	int ret = 1;

	for (int i = 0; i < 4; i++)
		if (Map[y + Move[i][0]][x + Move[i][1]] == '1' && RangeCheck(y + Move[i][0], x + Move[i][1])) {
			Map[y + Move[i][0]][x + Move[i][1]] = '0';
			ret += DFS(y + Move[i][0], x + Move[i][1]);
		}

	return ret;
}