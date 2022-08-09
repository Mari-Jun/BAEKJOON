#include <iostream>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;

int height, width;
array<array<char, 51>, 51> g_map;

static const int move_pos[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

struct Point
{
	int y, x;
};

bool CheckRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < height && x < width);
}

bool ExecuteExpandEvent(queue<Point>& queue, char expand_text)
{
	int size = queue.size();
	while (size--)
	{
		Point point = queue.front();
		queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int new_y = point.y + move_pos[i][0];
			int new_x = point.x + move_pos[i][1];

			if (CheckRange(new_y, new_x))
			{
				if (g_map[new_y][new_x] == '.' || (g_map[new_y][new_x] == 'S' && expand_text == '*'))
				{
					g_map[new_y][new_x] = expand_text;
					queue.emplace(Point{ new_y, new_x });
				}
				else if (g_map[new_y][new_x] == 'D' && expand_text == 'S')
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<Point> water_queue;
	queue<Point> go_queue;

	cin >> height >> width;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; ++x)
		{
			cin >> g_map[y][x];
			if (g_map[y][x] == 'S')
				go_queue.emplace(Point{ y,x });
			else if (g_map[y][x] == '*')
				water_queue.emplace(Point{ y,x });
		}
	}

	bool is_arrive = false;
	int move_cnt = 0;
	while (go_queue.empty() == false && is_arrive == false)
	{
		++move_cnt;

		ExecuteExpandEvent(water_queue, '*');
		if (ExecuteExpandEvent(go_queue, 'S'))
			is_arrive = true;
	}

	if (is_arrive)
	{
		cout << move_cnt;
	}
	else
	{
		cout << "KAKTUS";
	}
}