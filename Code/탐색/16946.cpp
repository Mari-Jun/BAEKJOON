#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

using v_map = vector<vector<int>>;
using v_area = vector< vector<pair<int, int>>>;
using v_visit = vector<vector<bool>>;
using s_pos = stack<pair<int, int>>;

const int move_pos[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

v_map InitMap(int, int);
void FindMoveArea(v_map&);
int MoveCount(v_map&, s_pos&, pair<int, int>);
bool IsRightMove(v_map&, pair<int, int>&&, int, int);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int height, width;
	cin >> height >> width;

	auto map = InitMap(height, width);
	FindMoveArea(map);

	return 0;
}

v_map InitMap(int height, int width)
{
	v_map map(height, vector<int>(width));

	for (auto& y : map)
	{
		string line;
		cin >> line;
		for (auto x = 0; x < width; x++)
		{
			y[x] = line[x] - '0';
		}
	}

	return map;
}

void FindMoveArea(v_map& map)
{
	//0������ Ž���� ���ؼ� � �� ������ 0���� �̵��� �� �ִ� ������ ���ؼ� �����մϴ�.
	//<int, int> = <number_of_zero, area_count>
	v_area area(map.size(), vector<pair<int, int>>(map[0].size(), { -1,-1 }));

	//�̵��� ������ ������ ����
	s_pos stack;

	int area_count = 1;

	for (auto y = 0; y < map.size(); y++)
	{
		for (auto x = 0; x < map[y].size(); x++)
		{
			//0�� ��츸 Ž���մϴ�.
			if (map[y][x] == 0)
			{
				int move_count = MoveCount(map, stack, { y,x });

				//����� ��ġ���� ���ÿ��� ���� area�� �Է��մϴ�.
				while (!stack.empty())
				{
					area[stack.top().first][stack.top().second] = { move_count,area_count };
					stack.pop();
				}

				area_count++;
			}
		}
	}

	//���� �μ����� ������ ���մϴ�.
	for (auto y = 0; y < map.size(); y++)
	{
		for (auto x = 0; x < map[y].size(); x++)
		{
			//���̶�� �����մϴ�.
			if (map[y][x] == 1)
			{
				int move_count = 1;
				vector<int> area_count;
				for (int i = 0; i < 4; i++)
				{
					//�̵� �����ϴٸ�
					if (IsRightMove(map, { y + move_pos[i][0], x + move_pos[i][1] }, map.size(), map[y].size()))
					{
						if (area_count.empty() || area_count.end() == find(area_count.begin(), area_count.end(), area[y + move_pos[i][0]][x + move_pos[i][1]].second))
						{
							move_count += area[y + move_pos[i][0]][x + move_pos[i][1]].first;
							area_count.push_back(area[y + move_pos[i][0]][x + move_pos[i][1]].second);
						}
					}
				}
				cout << move_count % 10;
			}
			//���� �ƴ϶��
			else
			{
				cout << "0";
			}
		}
		cout << '\n';
	}
}

int MoveCount(v_map& map, s_pos& stack, pair<int, int> pos)
{
	//���� ��ġ�� stack�� �����մϴ�.
	stack.push(pos);

	//���� ��ġ�� map�� -1�� ���������� �湮������ �˸��ϴ�.
	map[pos.first][pos.second] = -1;

	int count = 1;

	for (int i = 0; i < 4; i++)
	{
		//�̵� �����ϰ� �湮���� ���� ���¶��
		if (IsRightMove(map, { pos.first + move_pos[i][0],pos.second + move_pos[i][1] }, map.size(), map[pos.first].size())
			&& map[pos.first + move_pos[i][0]][pos.second + move_pos[i][1]] == 0)
		{
			count += MoveCount(map, stack, { pos.first + move_pos[i][0],pos.second + move_pos[i][1] });
		}
	}

	return count;
}

bool IsRightMove(v_map& map, pair<int, int>&& pos, int height, int width)
{
	//�� ��ü�� ��� ���
	if (pos.first < 0 || pos.second < 0 || pos.first >= height || pos.second >= width)
		return false;

	//�� pos�� 1�Ǵ� -1�� ��� (-1�� �湮�� ����)
	if (map[pos.first][pos.second] == 1)
		return false;

	return true;
}