#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int move_pos[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

vector<vector<int>> InitMap(int, int);
int WallBreakCount(vector<vector<int>>);
bool RangeCheck(int, int, int, int);

int main()
{
	int width, height;
	cin >> width >> height;
	vector<vector<int>> map = InitMap(height, width);
	cout << WallBreakCount(map);

	return 0;
}

vector<vector<int>> InitMap(int height, int width)
{
	vector<vector<int>> map(height, vector<int>(width));

	for (int y = 0; y < height; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < width; x++)
		{
			map[y][x] = str[x] - '0';
		}
	}

	return map;
}

int WallBreakCount(vector<vector<int>> map)
{
	vector<vector<bool>> visit(map.size(), vector<bool>(map[0].size(), false));

	using wall = pair<int, pair<int, int>>;
	//<ºÎ¼ø º®ÀÇ ¼ö, <yÁÂÇ¥, xÁÂÇ¥>>
	priority_queue<wall, vector<wall>, greater<wall>> count;

	count.push(make_pair(0, make_pair(0, 0)));
	visit[0][0] = true;

	while (!count.empty())
	{
		int size = count.size();
		while (size--)
		{
			int wall = count.top().first;
			int y = count.top().second.first;
			int x = count.top().second.second;

			if (y == map.size() - 1 && x == map[0].size() - 1)
				return wall;

			count.pop();
			for (int index = 0; index < 4; index++)
			{
				int move_y = y + move_pos[index][0];
				int move_x = x + move_pos[index][1];
				if (RangeCheck(move_y, move_x, map.size(), map[0].size()) && !visit[move_y][move_x])
				{
					visit[move_y][move_x] = true;
					count.push(make_pair(wall + map[move_y][move_x], make_pair(move_y, move_x)));
				}
			}
		}
	}
	return 0;
}

bool RangeCheck(int y, int x, int height, int width)
{
	if (y < 0 || x < 0 || y >= height || x >= width)
		return false;
	return true;
}