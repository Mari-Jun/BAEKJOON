#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Info
{
	int move_count;
	int direction;
	pair<int, int> red_pos;
	pair<int, int> blue_pos;
};

const int move_pos[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int result = -1;

vector<vector<char>> InitMap(int, int);
queue<Info> InitMoveInfo(vector<vector<char>>&, int, int);
void MoveMarble(const vector<vector<char>>&, queue<Info>&);
bool IsMove(const vector<vector<char>>&, pair<int, int>, pair<int, int>);
bool HoleIn(const vector<vector<char>>&, pair<int, int>);

void PrintMap(const vector<vector<char>>& map)
{
	for (auto y : map)
	{
		for (auto x : y)
			cout << x;
		cout << endl;
	}
}

int main()
{
	int height, width;
	cin >> height >> width;

	auto map = InitMap(height, width);
	auto move_info = InitMoveInfo(map, height, width);

	while (!move_info.empty())
	{
		MoveMarble(map, move_info);
	}
	cout << result;

	return 0;
}

vector<vector<char>> InitMap(int height, int width)
{
	vector<vector<char>> map(height, vector<char>(width));

	for (auto& y : map)
	{
		for (auto& x : y)
		{
			cin >> x;
		}
	}

	return map;
}

queue<Info> InitMoveInfo(vector<vector<char>>& map, int height, int width)
{
	Info first_info;
	first_info.direction = -1;
	first_info.move_count = 0;

	for (auto y = 0; y < height; y++)
	{
		for (auto x = 0; x < width; x++)
		{
			if (map[y][x] == 'R')
			{
				first_info.red_pos = make_pair(y, x);
				map[y][x] = '.';
			}	
			else if (map[y][x] == 'B')
			{
				first_info.blue_pos = make_pair(y, x);
				map[y][x] = '.';
			}
		}
	}

	queue<Info> move_info;
	move_info.push(first_info);
	return move_info;
}

void MoveMarble(const vector<vector<char>>& map, queue<Info>& move_info)
{
	Info cur_info = move_info.front();
	move_info.pop();

	for (auto move_direction = 0; move_direction < 4; move_direction++)
	{
		//전에 했던 방향과 같은 방향 또는 그 역방향으로 기우는 경우가 아니라면 실행합니다.
		if (cur_info.direction == -1 || cur_info.direction % 2 != move_direction % 2)
		{
			pair<int, int> red_pos = cur_info.red_pos;
			pair<int, int> blue_pos = cur_info.blue_pos;
			bool red_hole = false;
			bool blue_hole = false;
			//빨간 구슬을 움직이지 않을 때까지 움직입니다.
			while (1)
			{
				bool move = false;

				//빨간 구슬이 구멍에 들어간 경우
				if (!red_hole && HoleIn(map, make_pair(red_pos.first + move_pos[move_direction][0], red_pos.second + move_pos[move_direction][1])))
				{
					red_hole = true;
					red_pos = make_pair(red_pos.first + move_pos[move_direction][0], red_pos.second + move_pos[move_direction][1]);
					move = true;
				}
				//빨간 구슬이 움직이는 경우
				if (!red_hole && IsMove(map, make_pair(red_pos.first + move_pos[move_direction][0], red_pos.second + move_pos[move_direction][1]), blue_pos))
				{
					red_pos = make_pair(red_pos.first + move_pos[move_direction][0], red_pos.second + move_pos[move_direction][1]);
					move = true;
				}

				//파란 구슬이 구멍에 들어간 경우
				if (!blue_hole && HoleIn(map, make_pair(blue_pos.first + move_pos[move_direction][0], blue_pos.second + move_pos[move_direction][1])))
				{
					blue_hole = true;
					blue_pos = make_pair(blue_pos.first + move_pos[move_direction][0], blue_pos.second + move_pos[move_direction][1]);
					move = true;
				}
				//파란 구슬이 움직이는 경우
				if (!blue_hole && IsMove(map, make_pair(blue_pos.first + move_pos[move_direction][0], blue_pos.second + move_pos[move_direction][1]), red_pos))
				{
					blue_pos = make_pair(blue_pos.first + move_pos[move_direction][0], blue_pos.second + move_pos[move_direction][1]);
					move = true;
				}

				//빨간 구슬과 파란 구슬이 모두 움직이지 않는 경우
				if (!move)
				{
					//빨간 구슬만 구멍에 들어간 경우
					if (red_hole && !blue_hole)
					{
						//큐를 비웁니다.
						while (!move_info.empty())
						{
							move_info.pop();
						}
						result = cur_info.move_count + 1;
						return;
					}
					//파란 구슬이 구멍에 들어간 경우
					else if (blue_hole)
					{
						//다른 방법이 있는지 확인하기 위해서 아무것도 실행하지 않습니다.
					}
					//둘다 들어가지 않은 경우
					else
					{
						//큐에 새로운 위치를 입력합니다.
						if (cur_info.move_count != 9 && (cur_info.red_pos != red_pos || cur_info.blue_pos != blue_pos))
						{
							move_info.push({ cur_info.move_count + 1, move_direction, red_pos, blue_pos });
						}
					}			
					break;
				}
			}
		}
	}

}

bool IsMove(const vector<vector<char>>& map, pair<int, int> move_pos, pair<int, int> another_pos)
{
	//벽인 경우 or 빨간 구슬과 파란 구슬이 겹친 경우
	if (map[move_pos.first][move_pos.second] == '#' || move_pos == another_pos)
		return false;

	return true;
}

bool HoleIn(const vector<vector<char>>& map, pair<int, int> pos)
{
	//구멍에 들어간 경우
	if (map[pos.first][pos.second] == 'O')
		return true;
	return false;
}