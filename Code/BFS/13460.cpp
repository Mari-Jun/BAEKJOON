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
		//���� �ߴ� ����� ���� ���� �Ǵ� �� ���������� ���� ��찡 �ƴ϶�� �����մϴ�.
		if (cur_info.direction == -1 || cur_info.direction % 2 != move_direction % 2)
		{
			pair<int, int> red_pos = cur_info.red_pos;
			pair<int, int> blue_pos = cur_info.blue_pos;
			bool red_hole = false;
			bool blue_hole = false;
			//���� ������ �������� ���� ������ �����Դϴ�.
			while (1)
			{
				bool move = false;

				//���� ������ ���ۿ� �� ���
				if (!red_hole && HoleIn(map, make_pair(red_pos.first + move_pos[move_direction][0], red_pos.second + move_pos[move_direction][1])))
				{
					red_hole = true;
					red_pos = make_pair(red_pos.first + move_pos[move_direction][0], red_pos.second + move_pos[move_direction][1]);
					move = true;
				}
				//���� ������ �����̴� ���
				if (!red_hole && IsMove(map, make_pair(red_pos.first + move_pos[move_direction][0], red_pos.second + move_pos[move_direction][1]), blue_pos))
				{
					red_pos = make_pair(red_pos.first + move_pos[move_direction][0], red_pos.second + move_pos[move_direction][1]);
					move = true;
				}

				//�Ķ� ������ ���ۿ� �� ���
				if (!blue_hole && HoleIn(map, make_pair(blue_pos.first + move_pos[move_direction][0], blue_pos.second + move_pos[move_direction][1])))
				{
					blue_hole = true;
					blue_pos = make_pair(blue_pos.first + move_pos[move_direction][0], blue_pos.second + move_pos[move_direction][1]);
					move = true;
				}
				//�Ķ� ������ �����̴� ���
				if (!blue_hole && IsMove(map, make_pair(blue_pos.first + move_pos[move_direction][0], blue_pos.second + move_pos[move_direction][1]), red_pos))
				{
					blue_pos = make_pair(blue_pos.first + move_pos[move_direction][0], blue_pos.second + move_pos[move_direction][1]);
					move = true;
				}

				//���� ������ �Ķ� ������ ��� �������� �ʴ� ���
				if (!move)
				{
					//���� ������ ���ۿ� �� ���
					if (red_hole && !blue_hole)
					{
						//ť�� ���ϴ�.
						while (!move_info.empty())
						{
							move_info.pop();
						}
						result = cur_info.move_count + 1;
						return;
					}
					//�Ķ� ������ ���ۿ� �� ���
					else if (blue_hole)
					{
						//�ٸ� ����� �ִ��� Ȯ���ϱ� ���ؼ� �ƹ��͵� �������� �ʽ��ϴ�.
					}
					//�Ѵ� ���� ���� ���
					else
					{
						//ť�� ���ο� ��ġ�� �Է��մϴ�.
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
	//���� ��� or ���� ������ �Ķ� ������ ��ģ ���
	if (map[move_pos.first][move_pos.second] == '#' || move_pos == another_pos)
		return false;

	return true;
}

bool HoleIn(const vector<vector<char>>& map, pair<int, int> pos)
{
	//���ۿ� �� ���
	if (map[pos.first][pos.second] == 'O')
		return true;
	return false;
}