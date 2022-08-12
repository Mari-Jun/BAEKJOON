#include <iostream>
#include <array>
#include <queue>
#include <string>

using namespace std;

struct Point
{
	Point(int y, int x, int count)
		: y(y), x(x), count(count) {}

	int y, x;
	int count;
};

bool operator<(const Point& a, const Point b)
{
	if (a.count == b.count)
	{
		if (a.y == b.y)
			return a.x < b.x;
		return a.y < b.y;
	}
	return a.count > b.count;
}

int n;
array<array<int, 50>, 50> g_map;

constexpr int move_pos[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

void Input()
{
	cin >> n;
	for (int y = 0; y < n; ++y)
	{
		string line;
		cin >> line;
		for (int x = 0; x < n; ++x)
			g_map[y][x] = (line[x]) - '0';
	}
}

bool CheckRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < n && x < n;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();

	priority_queue<Point> queue;
	queue.emplace(0, 0, 0);
	g_map[0][0] = 2;

	bool find_path = false;
	int result = 0;

	while (queue.empty() == false && find_path == false)
	{
		Point point = queue.top();
		queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int new_y = point.y + move_pos[i][0];
			int new_x = point.x + move_pos[i][1];
			int new_count = point.count;

			if (CheckRange(new_y, new_x) && g_map[new_y][new_x] != 2)
			{
				if (new_y == n - 1 && new_x == n - 1)
				{
					find_path = true;
					result = new_count;
					break;
				}
				if (g_map[new_y][new_x] == 0)
					++new_count;
				
				g_map[new_y][new_x] = 2;

				queue.emplace(new_y, new_x, new_count);
			}
		}
	}

	cout << result;
}