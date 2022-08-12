#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

array<array<int, 31>, 11> g_map;
int min_value = 4;
int height, width, num;

bool FindPath(int x)
{
	int input_x = x;

	for (int y = 1; y <= height; ++y)
	{
		if (g_map[x][y] != 0)
			x = g_map[x][y];
	}

	return input_x == x;
}

void FindMinValue(int x, int y, int count)
{
	bool find_path = true;
	for (int new_x = 1; new_x <= width; ++new_x)
		if (FindPath(new_x) == false)
		{
			find_path = false;
			break;
		}

	if (find_path)
	{
		min_value = min(count, min_value);
		return;
	}

	if (++count < min_value)
	{
		for (int new_x = x; new_x < width; ++new_x)
		{
			for (int new_y = (new_x == x) ? y + 1 : 1; new_y <= height; ++new_y)
			{
				if (g_map[new_x][new_y] == 0 && g_map[new_x + 1][new_y] == 0)
				{
					g_map[new_x][new_y] = new_x + 1;
					g_map[new_x + 1][new_y] = new_x;
					FindMinValue(new_x, new_y, count);
					g_map[new_x][new_y] = 0;
					g_map[new_x + 1][new_y] = 0;
				}
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> width >> num >> height;

	int a, b;
	while (num--)
	{
		cin >> a >> b;
		g_map[b][a] = b + 1;
		g_map[b + 1][a] = b;
	}

	FindMinValue(1, 0, 0);
	if (min_value < 4)
		cout << min_value;
	else
		cout << -1;
}