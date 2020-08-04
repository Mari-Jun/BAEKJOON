#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> InputMap(int, int);
void MovePos(pair<int, int>&, char);
bool BoundaryOut(pair<int, int>&, int, int);
int CountOfMazeOut(vector<vector<char>>&);
bool EscapeMaze(vector<vector<char>>&, pair<int, int>);
void PrintMap(vector<vector<char>>&);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int height, width;
	cin >> height >> width;

	auto map = InputMap(height, width);

	cout << CountOfMazeOut(map);

	return 0;
}

vector<vector<char>> InputMap(int height, int width)
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

void MovePos(pair<int, int>& pos, char text)
{
	switch (text)
	{
	case 'U':
		pos.first--;
		break;
	case 'R':
		pos.second++;
		break;
	case 'D':
		pos.first++;
		break;
	case 'L':
		pos.second--;
		break;
	}
}

bool BoundaryOut(pair<int, int>& pos, int height, int width) 
{
	return (pos.first < 0 || pos.second < 0 || pos.first >= height || pos.second >= width);
}

int CountOfMazeOut(vector<vector<char>>& map)
{

	int escape_count = 0;

	for (auto y = 0; y < map.size(); y++)
	{
		for (auto x = 0; x < map[y].size(); x++)
		{
			//현재 위치가 탈출이 되는 경우
			if (EscapeMaze(map, make_pair(y, x)))
			{
				escape_count++;
			}
		}
	}

	return escape_count;
}

bool EscapeMaze(vector<vector<char>>& map, pair<int, int> pos)
{
	//이미 탈출구가 있어서 O로 변환된 경우
	if (map[pos.first][pos.second] == 'O')
	{
		return true;
	}
	//이미 탈출구가 존재하지 않아 X로 변환된 경우
	else if (map[pos.first][pos.second] == 'X')
	{
		return false;
	}
	//방문만 한 경우
	else if (map[pos.first][pos.second] == 'V')
	{
		//방문만 한 경우는 루프를 돌아 탈출구가 없기 때문에
		return false;
	}
	//아직 방문한 적이 없는 경우
	else
	{
		pair<int, int> m_pos = pos;
		MovePos(m_pos, map[pos.first][pos.second]);

		//방문 상태로 변환합니다.
		map[pos.first][pos.second] = 'V';

		//범위를 벗어난 경우
		if (BoundaryOut(m_pos, map.size(), map[pos.first].size()))
		{
			map[pos.first][pos.second] = 'O';
			return true;
		}
		//범위를 벗어나지 않은 경우
		else
		{
			if (EscapeMaze(map, m_pos))
			{
				map[pos.first][pos.second] = 'O';
				return true;
			}
			else
			{
				map[pos.first][pos.second] = 'X';
				return false;
			}
		}
	}
}

void PrintMap(vector<vector<char>>& map)
{
	for (auto y : map)
	{
		for (auto x : y)
		{
			cout << x;
		}
		cout << endl;
	}
}
