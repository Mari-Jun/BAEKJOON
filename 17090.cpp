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
			//���� ��ġ�� Ż���� �Ǵ� ���
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
	//�̹� Ż�ⱸ�� �־ O�� ��ȯ�� ���
	if (map[pos.first][pos.second] == 'O')
	{
		return true;
	}
	//�̹� Ż�ⱸ�� �������� �ʾ� X�� ��ȯ�� ���
	else if (map[pos.first][pos.second] == 'X')
	{
		return false;
	}
	//�湮�� �� ���
	else if (map[pos.first][pos.second] == 'V')
	{
		//�湮�� �� ���� ������ ���� Ż�ⱸ�� ���� ������
		return false;
	}
	//���� �湮�� ���� ���� ���
	else
	{
		pair<int, int> m_pos = pos;
		MovePos(m_pos, map[pos.first][pos.second]);

		//�湮 ���·� ��ȯ�մϴ�.
		map[pos.first][pos.second] = 'V';

		//������ ��� ���
		if (BoundaryOut(m_pos, map.size(), map[pos.first].size()))
		{
			map[pos.first][pos.second] = 'O';
			return true;
		}
		//������ ����� ���� ���
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
