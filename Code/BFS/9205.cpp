#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Point
{
	int x, y, beer_count;
};


int map[1400][1400];
bool store[1400][1400];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_case;
	cin >> test_case;

	auto ChangePos = [](int pos)
	{
		if (pos > 0)
			return static_cast<int>(ceilf(static_cast<float>(pos) / 50.0f + 656.0f));
		else
			return static_cast<int>(floorf(static_cast<float>(pos) / 50.0f + 656.0f));
	};

	while (test_case--)
	{
		fill(&map[0][0], &map[1399][1400], 0);
		fill(&store[0][0], &store[1399][1400], false);

		int combini;
		cin >> combini;

		int house_x, house_y;
		int festival_x, festival_y;

		cin >> house_x >> house_y;
		house_x = ChangePos(house_x);
		house_y = ChangePos(house_y);

		while (combini--)
		{
			int x, y;
			cin >> x >> y;
			x = ChangePos(x); 
			y = ChangePos(y); 

			store[x][y] = true;
		}

		cin >> festival_x >> festival_y;
		festival_x = ChangePos(festival_x);
		festival_y = ChangePos(festival_y);

		queue<Point> queue;
		queue.push({ house_x, house_y, 20 });

		map[house_x][house_y] = 20;

		static const int move_pos[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

		bool find_festival = false;
		while (queue.empty() == false && find_festival == false)
		{
			int size = queue.size();

			while (size--)
			{
				Point front = queue.front();
				if (front.beer_count > 0)
				{
					for (int i = 0; i < 4; ++i)
					{
						int new_x = front.x + move_pos[i][0];
						int new_y = front.y + move_pos[i][1];

						if (new_x < 0 || new_y < 0 || new_x > 1313 || new_y > 1313)
							continue;

						int new_beer = front.beer_count - 1;

						if (new_x == festival_x && new_y == festival_y)
						{
							find_festival = true;
							break;
						}

						if (store[new_x][new_y])
							new_beer = 20;

						if (map[new_x][new_y] < new_beer)
						{
							map[new_x][new_y] = new_beer;
							queue.push({ new_x, new_y, new_beer });
						}
					}
				}
				queue.pop();
			}
		}

		if (find_festival)
			cout << "happy\n";
		else
			cout << "sad\n";
	}
}