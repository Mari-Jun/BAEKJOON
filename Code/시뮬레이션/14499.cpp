#include <iostream>
#include <array>

using namespace std;

array<array<int, 20>, 20> g_map;
array<array<int, 3>, 4> g_dice;

int height, width, dice_x, dice_y;

bool CheckMapRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < height && x < width;
}

bool MoveEast()
{
	if (CheckMapRange(dice_y, dice_x + 1))
	{
		++dice_x;
		int temp = g_dice[1][2];
		g_dice[1][2] = g_dice[1][1];
		g_dice[1][1] = g_dice[1][0];
		g_dice[1][0] = g_dice[3][1];
		g_dice[3][1] = temp;
		return true;
	}
	return false;
}

bool MoveWest()
{
	if (CheckMapRange(dice_y, dice_x - 1))
	{
		--dice_x;
		int temp = g_dice[1][0];
		g_dice[1][0] = g_dice[1][1];
		g_dice[1][1] = g_dice[1][2];
		g_dice[1][2] = g_dice[3][1];
		g_dice[3][1] = temp;
		return true;
	}
	return false;
}

bool MoveNorth()
{
	if (CheckMapRange(dice_y - 1, dice_x))
	{
		--dice_y;
		int temp = g_dice[0][1];
		g_dice[0][1] = g_dice[1][1];
		g_dice[1][1] = g_dice[2][1];
		g_dice[2][1] = g_dice[3][1];
		g_dice[3][1] = temp;
		return true;
	}
	return false;
}

bool MoveSouth()
{
	if (CheckMapRange(dice_y + 1, dice_x))
	{
		++dice_y;
		int temp = g_dice[3][1];
		g_dice[3][1] = g_dice[2][1];
		g_dice[2][1] = g_dice[1][1];
		g_dice[1][1] = g_dice[0][1];
		g_dice[0][1] = temp;
		return true;
	}
	return false;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k;

	cin >> height >> width >> dice_y >> dice_x >> k;

	for (int y = 0; y < height; ++y)
		for (int x = 0; x < width; ++x)
			cin >> g_map[y][x];

	for (auto& dice : g_dice)
		dice.fill(0);

	int dir;
	while (k--)
	{
		cin >> dir;

		bool is_moved = false;

		switch (dir)
		{
		case 1: is_moved = MoveEast(); break;
		case 2: is_moved = MoveWest(); break;
		case 3: is_moved = MoveNorth(); break;
		case 4: is_moved = MoveSouth(); break;
		default: break;
		}

		if (is_moved)
		{
			if (g_map[dice_y][dice_x] == 0)
				g_map[dice_y][dice_x] = g_dice[3][1];
			else
			{
				g_dice[3][1] = g_map[dice_y][dice_x];
				g_map[dice_y][dice_x] = 0;
			}

			cout << g_dice[1][1] << '\n';
		}
	}
}