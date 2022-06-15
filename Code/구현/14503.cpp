#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int x_pos, y_pos, dir;

	int map[50][50];

	cin >> y_pos >> x_pos >> dir;

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			cin >> map[y][x];

	int cnt = 1;
	map[y_pos][x_pos] = 2;

	static const int move_pos[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

	bool is_move = true;

	while (is_move)
	{
		is_move = false;
		for (int i = 0; i < 4; ++i)
		{
			dir = (dir + 3) % 4;
			int new_y = y_pos + move_pos[dir][0];
			int new_x = x_pos + move_pos[dir][1];
			
			if (map[new_y][new_x] == 0)
			{
				is_move = true;
				y_pos = new_y; x_pos = new_x;
				map[new_y][new_x] = 2;
				++cnt;
				break;
			}
		}

		if (is_move == false)
		{
			int move_dir = (dir + 2) % 4;
			int new_y = y_pos + move_pos[move_dir][0];
			int new_x = x_pos + move_pos[move_dir][1];

			if (map[new_y][new_x] != 1)
			{
				y_pos = new_y; x_pos = new_x;
				if (map[new_y][new_x] == 0)
				{
					map[new_y][new_x] = 2;
					++cnt;
				}
				is_move = true;
			}
		}
	}
	
	cout << cnt;
}