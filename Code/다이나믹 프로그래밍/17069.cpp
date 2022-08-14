#include <iostream>
#include <array>

using namespace std;

int n;
array<array<int, 32>, 32> g_map;
array<array<array<long long, 3>, 32>, 32> g_cache;

bool CheckMovable(int y, int x, int direction)
{
	if (y < n && x < n)
	{
		if (direction != 2)
		{
			return g_map[y][x] == 0;
		}
		else
		{
			return g_map[y][x] == 0 && g_map[y - 1][x] == 0 && g_map[y][x - 1] == 0;
		}
	}
	return false;
}

long long FindPath(int y, int x, int direction)
{
	long long& ret = g_cache[y][x][direction];

	if (y == n - 1 && x == n - 1)
		return 1;

	if (ret != -1)
		return ret;


	int new_y = y, new_x = x;
	ret = 0;

	if (direction == 0)
	{
		++new_x;
		if (CheckMovable(new_y, new_x, 0))
			ret += FindPath(new_y, new_x, 0);

		++new_y;
		if (CheckMovable(new_y, new_x, 2))
			ret += FindPath(new_y, new_x, 2);
	}
	else if (direction == 1)
	{
		++new_y;
		if (CheckMovable(new_y, new_x, 1))
			ret += FindPath(new_y, new_x, 1);

		++new_x;
		if (CheckMovable(new_y, new_x, 2))
			ret += FindPath(new_y, new_x, 2);
	}
	else
	{
		++new_x;
		if (CheckMovable(new_y, new_x, 0))
			ret += FindPath(new_y, new_x, 0);

		--new_x;
		++new_y;
		if (CheckMovable(new_y, new_x, 1))
			ret += FindPath(new_y, new_x, 1);

		++new_x;
		if (CheckMovable(new_y, new_x, 2))
			ret += FindPath(new_y, new_x, 2);
	}

	return ret;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			cin >> g_map[y][x];
			g_cache[y][x].fill(-1);
		}
	}

	cout << FindPath(0, 1, 0);
}