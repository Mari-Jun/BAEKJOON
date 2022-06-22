#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Shark
{
	int speed = 0;
	int direction = 0;
	int size = 0;
};

struct SharkInfo : public Shark
{
	int row = 0;
	int column = 0;
};

int r, c, m;
array<array<Shark, 101>, 101> g_map;
vector<SharkInfo> g_move_sharks;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c >> m;

	g_move_sharks.reserve(m);
	while (m--)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		g_map[c][r] = Shark{ s, d, z };
		g_move_sharks.emplace_back(SharkInfo{ s, d, z, r, c });
	}

	int player = 0, player_row = 0;
	int player_size = 0;

	while (g_move_sharks.empty() == false && player < c)
	{
		//ÀÌµ¿
		++player;
		player_row = 0;

		for (int i = 1; i <= r; ++i)
		{
			if (g_map[player][i].size != 0)
			{
				player_size += g_map[player][i].size;
				g_map[player][i] = Shark();
				player_row = i;
				break;
			}
		}

		g_map.fill(array<Shark, 101>());

		set<pair<int, int>> move_sharks;

		for (auto& info : g_move_sharks)
		{
			int column = info.column;
			int row = info.row;	

			if (column == player && row == player_row)
				continue;

			int move_count = info.speed;
			while (move_count > 0)
			{
				switch (info.direction)
				{
				case 1:
				{
					if (row - 1 <= move_count)
					{
						info.direction = 2;
						move_count -= (row - 1);
						row = 1;
					}
					else
					{
						row -= move_count;
						move_count = 0;
					}
					break;
				}
				case 2:
				{
					if (r - row <= move_count)
					{
						info.direction = 1;
						move_count -= (r - row);
						row = r;
					}
					else
					{
						row += move_count;
						move_count = 0;
					}
					break;
				}
				case 3:
				{
					if (c - column <= move_count)
					{
						info.direction = 4;
						move_count -= (c - column);
						column = c;
					}
					else
					{
						column += move_count;
						move_count = 0;
					}
					break;
				}
				case 4:
				{
					if (column - 1 <= move_count)
					{
						info.direction = 3;
						move_count -= (column - 1);
						column = 1;
					}
					else
					{
						column -= move_count;
						move_count = 0;
					}
					break;
				}
				default: break;
				}
			}

			Shark& shark = g_map[column][row];

			if (shark.direction == 0)
				shark = Shark{ info.speed, info.direction, info.size };
			else
			{
				if (info.size > shark.size)
					shark = Shark{ info.speed, info.direction, info.size };
			}

			move_sharks.emplace(row, column);
		}

		g_move_sharks.clear();

		for (const auto& [row, column] : move_sharks)
		{
			const auto& shark = g_map[column][row];
			g_move_sharks.emplace_back(SharkInfo{ shark, row, column });
		}
	}

	cout << player_size << endl;
}