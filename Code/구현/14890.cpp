#include <iostream>
#include <array>

using namespace std;

int n, l;
int route = 0;
array<array<int, 100>, 100> g_map;

void MoveY(int x, int y, int count, bool is_down)
{
	if (is_down && count >= l)
	{
		is_down = false;
		count -= l;
	}

	if (y == n - 1)
	{
		if (is_down == false)
			++route;
	}
	else
	{
		if (g_map[y][x] == g_map[y + 1][x])
		{
			MoveY(x, y + 1, count + 1, is_down);
		}
		else if (g_map[y][x] + 1 == g_map[y + 1][x])
		{
			if(is_down == false && count >= l)
				MoveY(x, y + 1, 1, is_down);
		}
		else if (g_map[y][x] - 1 == g_map[y + 1][x])
		{
			if (is_down == false)
				MoveY(x, y + 1, 1, true);
		}
	}
}

void MoveX(int x, int y, int count, bool is_down)
{
	if (is_down && count >= l)
	{
		is_down = false;
		count -= l;
	}

	if (x == n - 1)
	{
		if (is_down == false)
			++route;
	}
	else
	{
		if (g_map[y][x] == g_map[y][x + 1])
		{
			MoveX(x + 1, y, count + 1, is_down);
		}
		else if (g_map[y][x] + 1 == g_map[y][x + 1])
		{
			if (is_down == false && count >= l)
				MoveX(x + 1, y, 1, is_down);
		}
		else if (g_map[y][x] - 1 == g_map[y][x + 1])
		{
			if (is_down == false)
				MoveX(x + 1, y, 1, true);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> l;
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
			cin >> g_map[y][x];

	for (int y = 0; y < n; ++y)
	{
		MoveX(0, y, 1, false);
	}
	 
	for (int x = 0; x < n; ++x)
	{
		MoveY(x, 0, 1, false);
	}

	cout << route;
}
