#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

struct DirectionInfo
{
	int time;
	char direction;
};

queue<DirectionInfo> g_dir_infos;
bool g_map[101][101];
int n;

int main()
{
	cin >> n;
	int k;
	cin >> k;

	while (k--)
	{
		int col, row;
		cin >> col >> row;
		g_map[col][row] = true;
	}

	int l;
	cin >> l;

	while (l--)
	{
		int time;
		char dir;
		cin >> time >> dir;
		g_dir_infos.emplace(DirectionInfo{ time, dir });
	}

	static const int move_pos[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	int x = 1, y = 1;
	int move_index = 0;
	int time = 0;
	list<pair<int, int>> snail_list = { {1, 1} };

	while (true)
	{
		++time;
		y += move_pos[move_index][0];
		x += move_pos[move_index][1];

		if (y <= 0 || x <= 0 || y > n || x > n)
			break;

		if (find(snail_list.begin(), snail_list.end(), make_pair(y, x)) != snail_list.end())
			break;

		if (g_map[y][x] == false)
			snail_list.pop_back();
		else
			g_map[y][x] = false;

		snail_list.push_front(make_pair(y, x));

		if (g_dir_infos.empty() == false)
		{
			DirectionInfo info = g_dir_infos.front();
			if (info.time == time)
			{
				g_dir_infos.pop();
				if (info.direction == 'L')
					move_index = (move_index + 3) % 4;
				else
					move_index = (move_index + 1) % 4;
			}
		}
	}

	cout << time;
}