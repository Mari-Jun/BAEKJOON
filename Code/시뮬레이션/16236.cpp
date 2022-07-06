#include <iostream>
#include <queue>
#include <array>
#include <vector>
#include <cmath>

using namespace std;

struct Fish
{
	int y, x;
};

struct FishQueue : public Fish
{
	int distance;
	int size;
};

bool operator<(const FishQueue& a, const FishQueue& b)
{
	if (a.distance == b.distance)
	{
		if (a.y == b.y)
			return a.x > b.x;
		else
			return a.y > b.y;
	}
	return a.distance > b.distance;
}

struct Shark : public Fish
{
	int size;
	int eat_count;
};

int n;
array<array<int, 20>, 20> g_map;
array<array<int, 20>, 20> g_distance_map;
array<queue<Fish>, 7> g_fishes;

void SetDistance(const Shark& shark)
{
	for (auto& dist_map : g_distance_map)
		fill(dist_map.begin(), dist_map.end(), -1);

	queue<Fish> queue;
	queue.push(shark);
	g_distance_map[shark.y][shark.x] = 0;
	int distance = 1;

	static const int move_pos[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

	while (queue.empty() == false)
	{
		int size = queue.size();
		while (size--)
		{
			const Fish& fish = queue.front();

			for (int i = 0; i < 4; ++i)
			{
				int new_y = fish.y + move_pos[i][0];
				int new_x = fish.x + move_pos[i][1];

				if (new_y >= 0 && new_x >= 0 && new_y < n && new_x < n &&
					g_distance_map[new_y][new_x] == -1 && g_map[new_y][new_x] <= shark.size)
				{
					g_distance_map[new_y][new_x] = distance;
					if (g_map[new_y][new_x] != 0)
						g_fishes[g_map[new_y][new_x]].push(Fish{ new_y, new_x });
					queue.push(Fish{ new_y, new_x });
				}
			}

			queue.pop();
		}

		++distance;
	}
}


void Simulation(int x, int y)
{
	Shark shark{ y, x, 2, 0 };
	int time = 0;

	while (true)
	{
		priority_queue<FishQueue> queue;

		SetDistance(shark);

		for (int size = 1; size < min(shark.size, 7); ++size)
		{
			while (g_fishes[size].empty() == false)
			{
				const Fish& fish = g_fishes[size].front();
				queue.push(FishQueue{ fish, g_distance_map[fish.y][fish.x], size });
				g_fishes[size].pop();
			}
		}

		if (queue.empty())
			break;

		const FishQueue& eat_fish = queue.top();
		++shark.eat_count;
		if (shark.eat_count == shark.size)
		{
			shark.eat_count = 0;
			++shark.size;
		}
		time += eat_fish.distance;
		g_map[eat_fish.y][eat_fish.x] = 9;
		g_map[shark.y][shark.x] = 0;
		shark.y = eat_fish.y;
		shark.x = eat_fish.x;

		queue.pop();
	}
	
	cout << time;
}

int main()
{
	cin >> n;

	int shark_x, shark_y;
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
		{
			cin >> g_map[y][x];
			if (g_map[y][x] == 9)
				shark_x = x, shark_y = y;
		}

	Simulation(shark_x, shark_y);
}

