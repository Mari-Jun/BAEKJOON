#include <iostream>
#include <array>

using namespace std;

int n;
array<array<int, 20>, 20> g_map;

pair<int, bool> MoveLeft()
{
	bool is_move = false;
	int ret = 0;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			if (g_map[y][x] == 0)
				for (int i = x + 1; i < n; ++i)
					if (g_map[y][i] != 0)
					{
						swap(g_map[y][x], g_map[y][i]);
						is_move = true;
						break;
					}

			if (g_map[y][x] != 0)
				for (int i = x + 1; i < n; ++i)
					if (g_map[y][i] != 0)
					{
						if (g_map[y][x] == g_map[y][i])
						{
							g_map[y][x] *= 2;
							ret = max(ret, g_map[y][x]);
							is_move = true;
							g_map[y][i] = 0;
						}
						break;
					}
		}
	}

	return { ret, is_move };
}

pair<int, bool> MoveRight()
{
	bool is_move = false;
	int ret = 0;

	for (int y = 0; y < n; ++y)
	{
		for (int x = n - 1; x >= 0; --x)
		{
			if (g_map[y][x] == 0)
				for (int i = x - 1; i >= 0; --i)
					if (g_map[y][i] != 0)
					{
						swap(g_map[y][x], g_map[y][i]);
						is_move = true;
						break;
					}

			if (g_map[y][x] != 0)
				for (int i = x - 1; i >= 0; --i)
					if (g_map[y][i] != 0)
					{
						if (g_map[y][x] == g_map[y][i])
						{
							g_map[y][x] *= 2;
							ret = max(ret, g_map[y][x]);
							is_move = true;
							g_map[y][i] = 0;
						}
						break;
					}
		}
	}

	return { ret, is_move };
}

pair<int, bool> MoveUp()
{
	bool is_move = false;
	int ret = 0;

	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < n; ++y)
		{
			if (g_map[y][x] == 0)
				for (int i = y + 1; i < n; ++i)
					if (g_map[i][x] != 0)
					{
						swap(g_map[y][x], g_map[i][x]);
						is_move = true;
						break;
					}

			if (g_map[y][x] != 0)
				for (int i = y + 1; i < n; ++i)
					if (g_map[i][x] != 0)
					{
						if (g_map[y][x] == g_map[i][x])
						{
							g_map[y][x] *= 2;
							ret = max(ret, g_map[y][x]);
							is_move = true;
							g_map[i][x] = 0;
						}
						break;
					}
		}
	}

	return { ret, is_move };
}

pair<int, bool> MoveDown()
{
	bool is_move = false;
	int ret = 0;

	for (int x = 0; x < n; ++x)
	{
		for (int y = n - 1; y >= 0; --y)
		{
			if (g_map[y][x] == 0)
				for (int i = y - 1; i >= 0; --i)
					if (g_map[i][x] != 0)
					{
						swap(g_map[y][x], g_map[i][x]);
						is_move = true;
						break;
					}

			if (g_map[y][x] != 0)
				for (int i = y - 1; i >= 0; --i)
					if (g_map[i][x] != 0)
					{
						if (g_map[y][x] == g_map[i][x])
						{
							g_map[y][x] *= 2;
							ret = max(ret, g_map[y][x]);
							is_move = true;
							g_map[i][x] = 0;
						}
						break;
					}
		}
	}

	return { ret, is_move };
}

int Simulation(int depth)
{
	int ret = 0;
	if (depth == 5)
		return ret;

	auto copy_map = g_map;

	auto left = MoveLeft();
	if (left.second)
	{
		ret = max(ret, left.first);
		ret = max(ret, Simulation(depth + 1));
		g_map = copy_map;
	}

	auto right = MoveRight();
	if (right.second)
	{
		ret = max(ret, right.first);
		ret = max(ret, Simulation(depth + 1));
		g_map = copy_map;
	}

	auto up = MoveUp();
	if (up.second)
	{
		ret = max(ret, up.first);
		ret = max(ret, Simulation(depth + 1));
		g_map = copy_map;
	}

	auto down = MoveDown();
	if (down.second)
	{
		ret = max(ret, down.first);
		ret = max(ret, Simulation(depth + 1));
		g_map = copy_map;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	int max_value = 0;

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
		{
			cin >> g_map[y][x];
			max_value = max(max_value, g_map[y][x]);
		}

	cout << max(max_value, Simulation(0));
}