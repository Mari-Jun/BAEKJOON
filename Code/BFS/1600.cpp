#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

const int HMove[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2} };
const int MMove[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

struct Monkey {
	int y;
	int x;
	int Count;
};

int K, W, H;
bool OK = false;
bool Map[200][200];
bool Visit[201][201][32];
queue<Monkey> q;

void Setting();
bool RangeCheck(int y, int x, int Count);
void BFS(int y, int x, int Count);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	int Count = 0;
	while (!q.empty()) {
		int Size = q.size();
		while(Size--){
			BFS(q.front().y, q.front().x, q.front().Count);
			if (q.empty())
				break;
		}
		if (q.empty())
			break;
		Count++;
	}
	if (Count == 0 || !OK)
		Count = -1;
	if (H == 1 && W == 1)
		Count = 0;
	cout << Count;

	return 0;
}

void Setting() {
	cin >> K >> W >> H;
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			cin >> Map[y][x];
	memset(Visit, false, sizeof(Visit));
	q.push({ 0,0,K });
	Visit[0][0][K] = true;
}

bool RangeCheck(int y, int x, int Count) {
	if (y < 0 || y >= H || x < 0 || x >= W || Map[y][x] || Visit[y][x][Count])
		return false;
	return true;
}

void BFS(int y, int x, int Count) {
	q.pop();

	if (y == H - 1 && x == W - 1) {
		OK = true;
		while (!q.empty()) 
			q.pop();
		return;
	}

	if (Count > 0) 
		for (int i = 0; i < 8; i++)
			if (RangeCheck(y + HMove[i][0], x + HMove[i][1], Count - 1)) {
				q.push({ y + HMove[i][0],x + HMove[i][1], Count - 1 });
				Visit[y + HMove[i][0]][x + HMove[i][1]][Count-1] = true;
			}
				
	
	for (int i = 0; i < 4; i++)
		if (RangeCheck(y + MMove[i][0], x + MMove[i][1], Count)) {
			q.push({ y + MMove[i][0],x + MMove[i][1],Count });
			Visit[y + MMove[i][0]][x + MMove[i][1]][Count] = true;
		}	
}