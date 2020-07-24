#include <iostream>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;

const int move_knight[8][2] = { {-2,-1},{-1,-2} ,{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1} };

bool visit[8][8];
queue<pair<int, int>> cur_point;
string start_point, end_point;

void InitComponent();
void PrintResult(int move_num);
bool RangeCheck(int x, int y);
int FindDFS();

int main() {

	while (cin >> start_point >> end_point) {
		InitComponent();
				
		visit[start_point[0] - 'a'][start_point[1] - '1'] = true;
		cur_point.push(make_pair(start_point[0] - 'a', start_point[1] - '1'));

		PrintResult(FindDFS());
	}
	return 0;
}

void InitComponent() {
	memset(visit, false, sizeof(visit));
	while (!cur_point.empty())
		cur_point.pop();
}

void PrintResult(int move_num) {
	cout << "To get from " << start_point << " to " << end_point << " takes " << move_num << " knight moves." << endl;
}

bool RangeCheck(int x, int y) {
	if (x < 0 || x >= 8 || y < 0 || y >= 8)
		return false;
	return !visit[x][y];
}

int FindDFS() {

	int move_count = 0;

	if (start_point == end_point)
		return move_count;

	while (1) {

		int queue_size = cur_point.size();

		while (queue_size--) {

			int cur_x = cur_point.front().first;
			int cur_y = cur_point.front().second;
			cur_point.pop();

			for (int i = 0; i < 8; i++) {
				if (RangeCheck(cur_x + move_knight[i][0], cur_y + move_knight[i][1])) {
					if ((cur_x + move_knight[i][0] == end_point[0] - 'a') && (cur_y + move_knight[i][1] == end_point[1] - '1')) {
						move_count++;
						return move_count;
					}

					cur_point.push(make_pair(cur_x + move_knight[i][0], cur_y + move_knight[i][1]));
					visit[cur_x + move_knight[i][0]][cur_y + move_knight[i][1]] = true;
				}
			}
		}

		move_count++;
	}

}