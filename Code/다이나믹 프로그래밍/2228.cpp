#include <iostream>
#include <memory.h>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int cache[105][55][2];
vector<int> num_array(102);

void Init(int);
int FindResult(int, int, int, int, bool);

int main()
{
	int number, section;
	cin >> number >> section;
	
	Init(number);

	cout << max(FindResult(number, 0, section, 1, true), FindResult(number, 0, section, 0, false));

	return 0;
}

void Init(int number)
{
	for (auto index = 0; index < number; index++)
	{
		cin >> num_array[index];
	}
	for (int i = 0; i < 105; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			for (int k = 0; k < 2; k++)
				cache[i][j][k] = -INT_MAX;
		}
	}
}

int FindResult(int number, int cur_num, int section, int cur_sec, bool select)
{
	if (number - 1 == cur_num)
	{
		//정확히 section을 구분했다면
		if (section == cur_sec) {
			if (select)
				return num_array[cur_num];
			else
				return 0;
		}
		//제시된 section보다 적게 구분하였다면
		else
			return -INT_MAX / 10;
	}

	int& ret = cache[cur_num][cur_sec][select];

	if (ret != -INT_MAX)
		return ret;

	ret = -INT_MAX / 10;
	
	//현재 값이 선택되어 있는 상태일시
	if (select)
	{
		//계속 선택
		ret = max(ret, num_array[cur_num] + FindResult(number, cur_num + 1, section, cur_sec, true));
		//다음 숫자 미선택
		ret = max(ret, num_array[cur_num] + FindResult(number, cur_num + 1, section, cur_sec, false));
	}
	//현재 값이 선택되어 있지 않은 상태일시
	else
	{
		//현재 구간이 최대 구간보다 적은 경우
		if (cur_sec < section)
		{
			//다음 숫자 선택
			ret = max(ret, FindResult(number, cur_num + 1, section, cur_sec + 1, true));
			//다음 숫자도 미선택
			ret = max(ret, FindResult(number, cur_num + 1, section, cur_sec, false));
		}
		//현재 구간이 최대 구간인 경우
		else
		{
			ret = max(ret, FindResult(number, cur_num + 1, section, cur_sec, false));
		}
	}

	return ret;
}