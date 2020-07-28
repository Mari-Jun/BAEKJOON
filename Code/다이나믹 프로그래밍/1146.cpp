#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int cache[102][102][102];
bool visit[102];

void Init();
int SearchLine(int cur_num, int number, int first, int second);

int main()
{
	int number;
	cin >> number;

	Init();
	
	int sum = 0;

	for (auto first = 0; first < number; first++)
	{
		for (auto second = 0; second < number; second++)
		{
			if (first != second)
			{
				visit[first] = true;
				visit[second] = true;
				sum += SearchLine(2, number, first, second);
				sum %= 1000000;
				visit[first] = false;
				visit[second] = false;
			}
		}
	}

	if (number == 1)
		sum = 1;
	
	cout << sum;


	return 0;
}

void Init()
{
	memset(cache, -1, sizeof(cache));
	memset(visit, false, sizeof(visit));
}

int SearchLine(int cur_num, int number, int first, int second)
{
	//마지막까지 온 경우 (줄을 생성한 경우)
	if (cur_num == number)
		return 1;

	int left_count = 0;
	for (int num = 0; num < second; num++)
	{
		if (!visit[num])
			left_count++;
	}
	
	int& ret = cache[cur_num][second][left_count];

	if (ret != -1)
	{
		return ret;
	}

	ret = 0;

	//두번째가 클 경우 두번째보다 작은 사람이 와야함
	if (first < second)
	{
		for (int next = 0; next < second; next++)
		{
			if (!visit[next])
			{
				visit[next] = true;
				ret += SearchLine(cur_num + 1, number, second, next);
				ret %= 1000000;
				visit[next] = false;
			}
		}
	}
	//첫번째가 클 경우 두번째보다 큰 사람이 와야함
	else
	{
		for (int next = second + 1; next < number; next++)
		{
			if (!visit[next])
			{
				visit[next] = true;
				ret += SearchLine(cur_num + 1, number, second, next);
				ret %= 1000000;
				visit[next] = false;
			}
		}
	}

	return ret;

}