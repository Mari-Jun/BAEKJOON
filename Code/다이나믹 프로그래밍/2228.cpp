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
		//��Ȯ�� section�� �����ߴٸ�
		if (section == cur_sec) {
			if (select)
				return num_array[cur_num];
			else
				return 0;
		}
		//���õ� section���� ���� �����Ͽ��ٸ�
		else
			return -INT_MAX / 10;
	}

	int& ret = cache[cur_num][cur_sec][select];

	if (ret != -INT_MAX)
		return ret;

	ret = -INT_MAX / 10;
	
	//���� ���� ���õǾ� �ִ� �����Ͻ�
	if (select)
	{
		//��� ����
		ret = max(ret, num_array[cur_num] + FindResult(number, cur_num + 1, section, cur_sec, true));
		//���� ���� �̼���
		ret = max(ret, num_array[cur_num] + FindResult(number, cur_num + 1, section, cur_sec, false));
	}
	//���� ���� ���õǾ� ���� ���� �����Ͻ�
	else
	{
		//���� ������ �ִ� �������� ���� ���
		if (cur_sec < section)
		{
			//���� ���� ����
			ret = max(ret, FindResult(number, cur_num + 1, section, cur_sec + 1, true));
			//���� ���ڵ� �̼���
			ret = max(ret, FindResult(number, cur_num + 1, section, cur_sec, false));
		}
		//���� ������ �ִ� ������ ���
		else
		{
			ret = max(ret, FindResult(number, cur_num + 1, section, cur_sec, false));
		}
	}

	return ret;
}