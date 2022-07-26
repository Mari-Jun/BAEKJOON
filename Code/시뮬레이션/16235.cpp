#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <array>

using namespace std;

int width;
array<array<int, 10>, 10> g_map;
array<array<int, 10>, 10> g_food;
array<array<deque<int>, 10>, 10> g_tree;
array<array<int, 10>, 10> g_five_tree_count;

void SpringAndSummer()
{
	for (int y = 0; y < width; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			vector<int> eat_tree;

			int new_food = 0;

			for (int tree_age : g_tree[y][x])
			{
				if (g_map[y][x] >= tree_age)
				{
					eat_tree.push_back(tree_age + 1);
					g_map[y][x] -= tree_age;
				}
				else
				{
					new_food += tree_age / 2;
				}
			}

			g_map[y][x] += new_food;
			g_tree[y][x].clear();

			for (int tree_age : eat_tree)
			{
				g_tree[y][x].push_back(tree_age);
				if (tree_age % 5 == 0)
					++g_five_tree_count[y][x];
			}
		}
	}
}

void NewTree(int y, int x, int count)
{
	static const int move_pos[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
	for (int i = 0; i < 8; ++i)
	{
		int new_y = y + move_pos[i][0];
		int new_x = x + move_pos[i][1];
		if (new_y >= 0 && new_x >= 0 && new_y < width && new_x < width)
		{
			for (int i = 0; i < count; ++i)
				g_tree[new_y][new_x].push_front(1);
		}
	}
}

void FallAndWinter()
{
	for (int y = 0; y < width; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (g_five_tree_count[y][x] > 0)
			{
				NewTree(y, x, g_five_tree_count[y][x]);
				g_five_tree_count[y][x] = 0;
			}
			g_map[y][x] += g_food[y][x];
		}
	}
}

int Simulation(int year)
{
	while (year--)
	{
		SpringAndSummer();
		FallAndWinter();
	}

	int ret = 0;

	for (int y = 0; y < width; ++y)
		for (int x = 0; x < width; ++x)
			ret += g_tree[y][x].size();

	return ret;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tree_count, year;
	cin >> width >> tree_count >> year;
	
	for (int y = 0; y < width; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			g_map[y][x] = 5;
			cin >> g_food[y][x];
		}
	}

	int tree_x, tree_y, tree_age;
	while (tree_count--)
	{
		cin >> tree_y >> tree_x >> tree_age;
		g_tree[tree_y - 1][tree_x - 1].push_back(tree_age);
	}

	cout << Simulation(year);
}