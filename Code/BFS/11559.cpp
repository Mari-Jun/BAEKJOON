#include <iostream>
#include <queue>

using namespace std;

char field[12][6];
bool visit[12][6];

struct Point
{
	int x, y;
};

static const int move_pos[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int main()
{
	for (int y = 11; y >= 0; --y)
		for (int x = 0; x < 6; ++x)
			cin >> field[y][x];

	int puyo = 0;

	while (true)
	{
		queue<Point> puyo_que;
		fill(&visit[0][0], &visit[11][6], false);

		//°°Àº »ö Ã£±â
		for (int y = 0; y < 12; ++y)
		{
			for (int x = 0; x < 6; ++x)
			{
				if (field[y][x] != '.' && visit[y][x] == false)
				{
					queue<Point> que, visit_que;
					que.push({ x,y });
					visit[y][x] = true;

					while (que.empty() == false)
					{
						Point point = que.front();
						for (int i = 0; i < 4; ++i)
						{
							int new_x = point.x + move_pos[i][0];
							int new_y = point.y + move_pos[i][1];

							if (new_x >= 0 && new_y >= 0 && new_x < 6 && new_y < 12 &&
								visit[new_y][new_x] == false && (field[point.y][point.x] == field[new_y][new_x]))
							{
								que.push({ new_x, new_y });
								visit[new_y][new_x] = true;
							}
						}

						visit_que.push(point);
						que.pop();
					}

					if (visit_que.size() >= 4)
					{
						while (visit_que.empty() == false)
						{
							puyo_que.push(visit_que.front());
							visit_que.pop();
						}
					}
				}
			}
		}

		if (puyo_que.empty())
			break;

		//Puyo ºØ±«
		while (puyo_que.empty() == false)
		{
			Point point = puyo_que.front();
			field[point.y][point.x] = '.';
			puyo_que.pop();
		}

		++puyo;		

		//Drop
		for (int x = 0; x < 6; ++x)
		{
			int empty_y = 12;
			for (int y = 0; y < 12; ++y)
			{
				if (field[y][x] == '.')
					empty_y = min(empty_y, y);
				else
				{
					if (empty_y < 12)
					{
						field[empty_y][x] = field[y][x];
						field[y][x] = '.';
						++empty_y;
					}
				}
			}
		}
	}

	cout << puyo;
}