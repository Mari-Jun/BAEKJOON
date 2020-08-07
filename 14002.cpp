#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

vector<pair<int,int>> GetData(int);
void FindLIS(vector<pair<int, int>>&);
int BinarySearch(vector<int>&, int);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int num;
	cin >> num;
	auto data = GetData(num);
	FindLIS(data);
	return 0;
}

vector<pair<int, int>> GetData(int num)
{
	vector<pair<int, int>> data(num);
	
	for (auto& d : data)
	{
		cin >> d.first;
	}

	return data;
}

void FindLIS(vector<pair<int, int>>& data)
{
	//LIS ������ ���� ���� �ʱⰪ lis[0] = 0;
	vector<int> lis(1, 0);

	for (int index = 0; index < data.size(); index++)
	{
		//lis�� ���� ������ ���� ���� index�� ����Ű�� �ִ� data ���� ���մϴ�.
		if (data[index].first > lis[lis.size() - 1])
		{
			lis.push_back(data[index].first);
			data[index].second = lis.size() - 1;
		}
		else
		{
			//�� ��ġ�� Ž���մϴ�.
			data[index].second = BinarySearch(lis, data[index].first);
		}
	}


	int lis_size = lis.size() - 1;
	cout << lis_size << '\n';
	stack<int> result;

	for (vector<pair<int, int>>::const_reverse_iterator iter = data.crbegin(); iter != data.crend(); iter++)
	{
		if (lis_size == (*iter).second)
		{
			result.push((*iter).first);
			lis_size--;

			if (lis_size == 0)
				break;
		}
	}

	while (!result.empty())
	{
		cout << result.top() << ' ';
		result.pop();
	}

}

int BinarySearch(vector<int>& lis, int data)
{
	int left = 0, right = lis.size() - 1;

	while (left < right)
	{
		int mid = (left + right) / 2;
		//�����Ͱ� �� ū���
		if (lis[mid] < data)
		{
			left = mid + 1;
		}
		//�����Ͱ� �� �������
		else if (lis[mid] > data)
		{
			right = mid - 1;
		}
		//�������
		else
		{
			return mid;
		}
	}

	//���� ����Ű�� �ִ� ��ġ���� �����Ͱ� ū ���
	if (lis[left] < data)
	{
		lis[left + 1] = min(lis[left + 1], data);
		return left + 1;
	}
	else
	{
		lis[left] = min(lis[left], data);
		return left;
	}
}