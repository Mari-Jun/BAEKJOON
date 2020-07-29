#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

long long cache[105][105];
vector<vector<vector<pair<int, int>>>> route(105, vector<vector<pair<int, int>>>(105));

void InputNoRoute(int);

long long FindRoute(pair<int, int>, pair<int, int>, int, int);
bool IsMove(pair<int, int>, pair<int, int>, pair<int, int>);

int main()
{
	memset(cache, -1, sizeof(cache));

	int width, height;
	cin >> width >> height;

	int number;
	cin >> number;

	InputNoRoute(number);

	cout << FindRoute(make_pair(0, 0), make_pair(width, height), 0, width + height);

	return 0;
}

void InputNoRoute(int number)
{
	while (number--)
	{
		int start_x, start_y, end_x, end_y;
		cin >> start_x >> start_y >> end_x >> end_y;

		pair<int, int> max_pos = max(make_pair(start_x, start_y), make_pair(end_x, end_y));
		pair<int, int> min_pos = min(make_pair(start_x, start_y), make_pair(end_x, end_y));

		//시작지점
		route[min_pos.first][min_pos.second].push_back(max_pos);
	}
}

long long FindRoute(pair<int, int> cur_pos, pair<int,int> max_pos, int cur_move, int max_move)
{
	//이동 횟수인 width+height일 경우
	if (cur_move == max_move)
	{
		//학교에 도착한 경우
		if (max_pos == cur_pos)
			return 1;
		else
			return 0;
	}

	long long& ret = cache[cur_pos.first][cur_pos.second];

	if (ret != -1)
		return ret;

	ret = 0;

	//오른쪽으로 이동
	if (IsMove(cur_pos, make_pair(cur_pos.first + 1, cur_pos.second), max_pos))
	{
		ret += FindRoute(make_pair(cur_pos.first + 1, cur_pos.second), max_pos, cur_move + 1, max_move);
	}

	//위쪽으로 이동
	if (IsMove(cur_pos, make_pair(cur_pos.first, cur_pos.second + 1), max_pos))
	{
		ret += FindRoute(make_pair(cur_pos.first, cur_pos.second + 1), max_pos, cur_move + 1, max_move);
	}

	return ret;
}

bool IsMove(pair<int, int> cur_pos, pair<int, int> next_pos, pair<int, int> max_pos)
{
	//맵 밖으로 이동하려는 경우
	if (next_pos.first > max_pos.first || next_pos.second > max_pos.second)
		return false;
	//공사중인경우
	for (int index = 0; index < route[cur_pos.first][cur_pos.second].size(); index++)
	{
		if (route[cur_pos.first][cur_pos.second][index] == next_pos)
			return false;
	}
	return true;
}