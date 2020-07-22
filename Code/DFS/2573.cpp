#include <iostream>
#include <memory.h>

using namespace std;

const int Move[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int N, M;
int Map[300][300];
bool Check[300][300];
int Min[300][300];

void Setting();
bool RangeCheck(int y, int x);
void DFS(int y, int x);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	int Year = 0;
	while (1) {
		memset(Check, false, sizeof(Check));
		memset(Min, 0, sizeof(Min));
		int Count = 0;
		for (int y = 0; y < N; y++) 
			for (int x = 0; x < M; x++) 
				if (Map[y][x] > 0 && !Check[y][x]) {
					Check[y][x] = true;
					DFS(y, x);
					Count++;
				}
		Year++;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				Map[y][x] -= Min[y][x];
			
		if (Count > 1)
			break;

		if (Count == 0) {
			Year = 1;
			break;
		}

	}
	cout << Year - 1;
	return 0;
}

void Setting() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> Map[y][x];
}

bool RangeCheck(int y, int x) {
	if (Map[y][x] <= 0)
		return false;
	return true;
}

void DFS(int y, int x) {

	for (int i = 0; i < 4; i++) {
		if (RangeCheck(y + Move[i][0], x + Move[i][1])) {
			if (!Check[y + Move[i][0]][x + Move[i][1]]) {
				Check[y + Move[i][0]][x + Move[i][1]] = true;
				DFS(y + Move[i][0], x + Move[i][1]);
			}
		}
		else
			Min[y][x]++;
	}
}