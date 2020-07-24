#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>

using namespace std;

const int move_pos[4][2] = { {-1,0}, {0,1},{1,0},{0,-1} };

struct Pos_Info {
	int y;
	int x;
	bool wall;
};

int map[1005][1005];
queue<Pos_Info> pos;
bool visit[1005][1005][2];

void InputMap(int, int);
int FindMinRoute(int, int);
bool CheckPos(int, int, int, int);
void DFS(int, int);

int main()
{
	int height, width;
	cin >> height >> width;

	InputMap(height, width);
	cout << FindMinRoute(height, width);

	return 0;
}

void InputMap(int height, int width)
{
	for (auto y = 0; y < height; y++)
	{
		string str;
		cin >> str;
		for (auto x = 0; x < width; x++)
			map[y][x] = str[x] - '0';
	}
	memset(visit, false, sizeof(visit));
}

int FindMinRoute(int height, int width)
{
	pos.push({ 0,0,false });
	visit[0][0][0] = true;

	int move_count = 1;

	while (1)
	{
		int size = pos.size();

		while (size--)
		{
			if (pos.front().y == height - 1 && pos.front().x == width - 1)
				return move_count;

			DFS(height, width);
		}
		move_count++;

		if (pos.empty())
			return -1;
	}
}

bool CheckPos(int height, int width, int y, int x)
{
	if (y < 0 || y >= height || x < 0 || x >= width)
		return false;
	return true;
}

void DFS(int height, int width)
{
	int y = pos.front().y;
	int x = pos.front().x;
	bool wall = pos.front().wall;

	pos.pop();

	for (int i = 0; i < 4; i++)
	{
		int move_y = y + move_pos[i][0];
		int move_x = x + move_pos[i][1];

		if (CheckPos(height, width, move_y, move_x) && !visit[move_y][move_x][wall])
		{
			if (map[move_y][move_x] == 1 && !wall) 
			{
				visit[move_y][move_x][true] = true;
				pos.push({ move_y,move_x,true });
			}
			else if (map[move_y][move_x] == 0)
			{
				visit[move_y][move_x][wall] = true;
				pos.push({ move_y,move_x,wall });
			}
		}
	}
}