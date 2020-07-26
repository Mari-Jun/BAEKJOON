#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using p_long = pair<long long, long long>;

vector<int> InitHeight(int);
vector<int> NumberOfBuliding(vector<int>);
bool Outer(p_long, p_long, p_long);

int main()
{
	int number;
	cin >> number;

	if (number == 1)
	{
		cout << 0;
	}
	else
	{
		vector<int> height = InitHeight(number);
		vector<int> buliding = NumberOfBuliding(height);

		int max_num = 0;
		for (auto index : buliding)
		{
			max_num = max(max_num, index);
		}
		cout << max_num;
	}

	return 0;
}

vector<int> InitHeight(int number)
{
	vector<int> height(number);

	for (auto& index : height)
		cin >> index;

	return height;
}

vector<int> NumberOfBuliding(vector<int> height)
{
	vector<int> buliding(height.size(), 2);

	//ó�� ������ ������ ������ ������ ���̴� ������ �����Ƿ�
	buliding[0] = 1;
	buliding[buliding.size() - 1] = 1;

	for (auto start = 0; start < height.size() - 2; start++)
	{		
		for (auto end = start + 2; end < height.size(); end++)
		{
			bool outer = true;
	
			for (auto mid = start + 1; mid < end; mid++)
			{
				//������ ���� 0�Ǵ� �������
				if (!Outer(make_pair(start, height[start]), make_pair(mid, height[mid]), make_pair(end, height[end])))
				{
					outer = false;
				}
			}

			//Start�������� End���� ������ ��� ������ ���� ������
			if (outer)
			{
				buliding[start]++;
				buliding[end]++;
			}
		}
	}
	return buliding;
}

bool Outer(p_long start, p_long mid, p_long end)
{
	long long outer = (mid.first - start.first) * (end.second - start.second) - (mid.second - start.second) * (end.first - start.first);
	return (outer > 0);
}