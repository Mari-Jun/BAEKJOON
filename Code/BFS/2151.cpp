#include <iostream>
#include <array>
#include <queue>

using namespace std;

int n;
array<array<char, 50>, 50> g_house;
array<array<array<bool, 5>, 50>, 50> g_visit;

struct Point
{
	Point(int y, int x, int dy, int dx, int count)
		: y(y), x(x), dy(dy), dx(dx), mirror_count(count) {}
	int y, x, dy, dx;
	int mirror_count;
};

bool operator<(const Point& a, const Point& b)
{
	if (a.mirror_count == b.mirror_count)
	{
		if (a.y == b.y)
			return a.x > b.x;
		else
			return a.y > b.y;
	}
	return a.mirror_count > b.mirror_count;
}

bool CheckRange(int y, int x, int dy, int dx)
{
	return y >= 0 && x >= 0 && x < n && y < n&& g_visit[y][x][2 + dy * 2 + dx] == false;
}

void CheckVisit(int y, int x, int dy, int dx)
{
	g_visit[y][x][2 + dy * 2 + dx] = true;
}

void ChangeDirection(int& y, int& x, bool turn_left)
{
	if (y == 0)
	{
		if (turn_left)
			x == 1 ? y = -1 : y = 1;
		else
			x == 1 ? y = 1 : y = -1;
		x = 0;
	}
	else
	{
		if (turn_left)
			y == 1 ? x = -1 : x = 1;
		else
			y == 1 ? x = 1 : x = -1;
		y = 0;
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	bool get_start = false;
	Point start_point{ 0,0, 0, 0,0 };
	Point end_point{ 0,0, 0, 0,0 };

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			cin >> g_house[y][x];
			if (g_house[y][x] == '#')
			{
				if (get_start == false)
				{
					get_start = true;
					start_point = Point{ y,x,0, 0, 0 };
				}
				else
				{
					end_point = Point{ y,x,0, 0, 0 };
				}
			}
		}
	}

	priority_queue<Point> queue;
	start_point.dy = 1; start_point.dx = 0;
	CheckVisit(start_point.y, start_point.x, start_point.dy, start_point.dx);
	queue.emplace(start_point);
	start_point.dy = -1; start_point.dx = 0;
	CheckVisit(start_point.y, start_point.x, start_point.dy, start_point.dx);
	queue.emplace(start_point);
	start_point.dy = 0; start_point.dx = 1;
	CheckVisit(start_point.y, start_point.x, start_point.dy, start_point.dx);
	queue.emplace(start_point);
	start_point.dy = 0; start_point.dx = -1;
	CheckVisit(start_point.y, start_point.x, start_point.dy, start_point.dx);
	queue.emplace(start_point);

	int result = 0;
	while (queue.empty() == false)
	{
		Point point = queue.top();
		queue.pop();

		//cout << point.y << ", " << point.x << " : " << point.mirror_count << endl;

		int new_y = point.y + point.dy;
		int new_x = point.x + point.dx;

		if (CheckRange(new_y, new_x, point.dy, point.dx) && g_house[new_y][new_x] != '*')
		{
			CheckVisit(new_y, new_x, point.dy, point.dx);
			if (g_house[new_y][new_x] == '#')
			{
				if (new_y == end_point.y && new_x == end_point.x)
				{
					result = point.mirror_count;
					break;
				}
			}
			else if (g_house[new_y][new_x] == '!')
			{
				int dyl = point.dy, dxl = point.dx;
				int dyr = point.dy, dxr = point.dx;
				ChangeDirection(dyl, dxl, true);
				queue.emplace(new_y, new_x, dyl, dxl, point.mirror_count + 1);
				ChangeDirection(dyr, dxr, false);
				queue.emplace(new_y, new_x, dyr, dxr, point.mirror_count + 1);
				queue.emplace(new_y, new_x, point.dy, point.dx, point.mirror_count);
			}
			else
			{
				queue.emplace(new_y, new_x, point.dy, point.dx, point.mirror_count);
			}
		}
	}

	cout << result;
}