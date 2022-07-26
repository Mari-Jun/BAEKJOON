#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Point
{
	int y, x;
};

vector<vector<char>> g_map;
vector<Point> g_cctvs;

int width, height;

bool ChangePoint(int y, int x)
{
	if (g_map[y][x] == '6')
		return false;
	else if (g_map[y][x] == '0')
		g_map[y][x] = '#';
	return true;
}

void MonitorLeft(int y, int x)
{
	for (x; x >= 0; --x)
	{
		if (ChangePoint(y, x) == false)
			break;
	}
}

void MonitorRight(int y, int x)
{
	for (x; x < width; ++x)
	{
		if (ChangePoint(y, x) == false)
			break;
	}
}

void MonitorUp(int y, int x)
{
	for (y; y >= 0; --y)
	{
		if (ChangePoint(y, x) == false)
			break;
	}
}

void MonitorDown(int y, int x)
{
	for (y; y < height; ++y)
	{
		if (ChangePoint(y, x) == false)
			break;
	}
}

int CheckZeroPoint()
{
	int ret = 0;
	for (const auto& line : g_map)
		ret += count(line.cbegin(), line.cend(), '0');
	return ret;
}

int Simulation(int depth)
{
	if (depth == g_cctvs.size())
		return CheckZeroPoint();

	int min_value = numeric_limits<int>::max();

	auto temp_map = g_map;

	const Point& point = g_cctvs[depth];
	switch (g_map[point.y][point.x])
	{
	case '1': 
		MonitorLeft(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		MonitorUp(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		MonitorRight(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		MonitorDown(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		break;
	case '2': 
		MonitorLeft(point.y, point.x);
		MonitorRight(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		MonitorUp(point.y, point.x);
		MonitorDown(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		break;
	case '3': 
		MonitorLeft(point.y, point.x);
		MonitorUp(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		MonitorUp(point.y, point.x);
		MonitorRight(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		MonitorRight(point.y, point.x);
		MonitorDown(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		MonitorLeft(point.y, point.x);
		MonitorDown(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		break;
	case '4':
		MonitorLeft(point.y, point.x);
		MonitorUp(point.y, point.x);
		MonitorRight(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		MonitorUp(point.y, point.x);
		MonitorRight(point.y, point.x);
		MonitorDown(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		MonitorLeft(point.y, point.x);
		MonitorRight(point.y, point.x);
		MonitorDown(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		MonitorLeft(point.y, point.x);
		MonitorUp(point.y, point.x);
		MonitorDown(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		break;
	case '5':
		MonitorLeft(point.y, point.x);
		MonitorRight(point.y, point.x);
		MonitorUp(point.y, point.x);
		MonitorDown(point.y, point.x);
		min_value = min(min_value, Simulation(depth + 1));
		g_map = temp_map;

		break;
	default: break;
	}

	return min_value;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> height >> width;
	g_map.resize(height, vector<char>(width));

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			cin >> g_map[y][x];
			if (g_map[y][x] != '0' && g_map[y][x] != '6')
				g_cctvs.push_back(Point{ y, x });
		}
	}

	cout << Simulation(0);
}