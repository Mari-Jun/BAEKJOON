#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

struct Point
{
	int x, y;
};

int height, width;
vector<vector<int>> g_map;
vector<Point> g_virus;
vector<Point> g_new_virus;

bool CheckRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < height && x < width;
}

void VirusSimulation(int y, int x)
{
	static const int move_pos[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	for (int i = 0; i < 4; ++i)
	{
		int new_y = y + move_pos[i][0];
		int new_x = x + move_pos[i][1];
		if (CheckRange(new_y, new_x) && g_map[new_y][new_x] == 0)
		{
			g_map[new_y][new_x] = 2;
			g_new_virus.emplace_back(Point{ new_x, new_y });
			VirusSimulation(new_y, new_x);
		}
	}
}

int CreateWalls(int depth, int y, int x)
{
	int ret = 0;

	if (depth < 3)
	{
		for (y; y < height; ++y)
		{
			for (x; x < width; ++x)
			{
				if (g_map[y][x] == 0)
				{
					g_map[y][x] = 1;
					ret = max(ret, CreateWalls(depth + 1, y, x));
					g_map[y][x] = 0;
				}
			}
			x = 0;
		}
	}
	else
	{
		for (const auto& point : g_virus)
		{
			VirusSimulation(point.y, point.x);
		}

		ret = 0;
		for (const auto& line : g_map)
			ret += count(line.cbegin(), line.cend(), 0);

		for (const auto& point : g_new_virus)
			g_map[point.y][point.x] = 0;
		g_new_virus.clear();
	}

	return ret;
}



int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> height >> width;
	g_map.resize(height, vector<int>(width));

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			cin >> g_map[y][x];
			if (g_map[y][x] == 2)
				g_virus.emplace_back(Point{ x, y });
		}
	}

	cout << CreateWalls(0, 0, 0);
}