#include <iostream>
#include <bitset>
#include <array>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct Room
{
	bitset<4> wall;
	int visit = 0;
};

struct PairCmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
	{
		if (a.first == b.first) 
			return a.second < b.second;
		return a.first > b.first;
	}
};

array<array<Room, 50>, 50> g_rooms;
vector<int> g_area;
set<pair<int, int>, PairCmp> g_destory_walls;

int w, h;

int main()
{
	cin >> w >> h;
	int num;
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			cin >> num;
			g_rooms[y][x].wall = num;
		}
	}

	int room_count = 0, max_room_area = 0, max_break_wall_area = 0;
	queue<pair<int, int>> queue;

	auto CheckRange = [](int y, int x)
	{
		return x >= 0 && y >= 0 && x < w&& y < h;
	};

	auto MoveNextPos = [&queue](int new_y, int new_x, Room& room, int bit)
	{
		if (room.wall[bit] == false)
		{
			if (g_rooms[new_y][new_x].visit == 0)
			{
				queue.emplace(new_y, new_x);
				g_rooms[new_y][new_x].visit = room.visit;
			}
		}
		else
		{
			if (g_rooms[new_y][new_x].visit != 0 && g_rooms[new_y][new_x].visit != room.visit)
				g_destory_walls.emplace(room.visit, g_rooms[new_y][new_x].visit);
		}
	};

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			Room& room = g_rooms[y][x];
			if (room.visit == 0)
			{
				++room_count;

				queue.emplace(y, x);
				room.visit = room_count;

				int area = 0;
				while (queue.empty() == false)
				{
					++area;
					auto [new_y, new_x] = queue.front();
					queue.pop();

					Room& room = g_rooms[new_y][new_x];

					if (CheckRange(new_y, new_x - 1))
						MoveNextPos(new_y, new_x - 1, room, 0);

					if (CheckRange(new_y - 1, new_x))
						MoveNextPos(new_y - 1, new_x, room, 1);

					if (CheckRange(new_y, new_x + 1))
						MoveNextPos(new_y, new_x + 1, room, 2);

					if (CheckRange(new_y + 1, new_x))
						MoveNextPos(new_y + 1, new_x, room, 3);
				}

				g_area.push_back(area);
				max_room_area = max(max_room_area, area);
			}
		}
	}

	for (auto [room1, room2] : g_destory_walls)
		max_break_wall_area = max(max_break_wall_area, g_area[room1 - 1] + g_area[room2 - 1]);

	cout << room_count << endl;
	cout << max_room_area << endl;
	cout << max_break_wall_area << endl;
}