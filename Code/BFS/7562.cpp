#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

const int M[8][2]{ {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2} };

int T;
int L;
int Y1, X1, Y2, X2;
queue<pair<int, int>> q;
bool Check[301][301];

void Setting();
bool RangeCheck(int y, int x);
void BFS();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		Setting();
		int Sum = 0;
		while (!q.empty()) {
			int Size = q.size();
			while (Size--) {
				BFS();
				if (q.empty())
					break;
			}
			if (q.empty())
				break;
			Sum++;
		}
		cout << Sum << '\n';
	}
	return 0;
}

void Setting() {
	cin >> L >> Y1 >> X1 >> Y2 >> X2;
	memset(Check, false, sizeof(Check));
	while (!q.empty())
		q.pop();
	q.push(make_pair(Y1, X1));
	Check[Y1][X1] = true;
}

bool RangeCheck(int y, int x) {
	if (y < 0 || x < 0 || y >= L || x >= L || Check[y][x])
		return false;
	return true;
}

void BFS() {
	int y = q.front().first, x = q.front().second;
	q.pop();

	if (y == Y2 && x == X2) {
		while (!q.empty())
			q.pop();
		return;
	}
	
	for (int i = 0; i < 8; i++) {
		if (RangeCheck(y + M[i][0], x + M[i][1])) {
			q.push(make_pair(y + M[i][0], x + M[i][1]));
			Check[y + M[i][0]][x + M[i][1]] = true;
		}
	}
}