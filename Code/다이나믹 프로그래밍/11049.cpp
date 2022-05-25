#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int number;
vector<pair<int, int>> matrix;
vector<vector<int>> cache;

int MCM(int start, int end);

int main()
{
	cin >> number;
	matrix.resize(number);
	cache.resize(number, vector<int>(number, -1));

	//행렬을 입력받습니다.
	for (auto& index : matrix)
	{
		cin >> index.first >> index.second;
	}
	
	cout << MCM(0, number - 1);

	return 0;
}

int MCM(int start, int end)
{
	if (start == end)
		return 0;

	int& ret = cache[start][end];

	if (ret != -1)
	{
		return ret;
	}

	ret = numeric_limits<int>::max();

	for (int next = start; next < end; next++)
	{
		ret = min(ret, MCM(start, next) + MCM(next + 1, end) + matrix[start].first * matrix[next].second * matrix[end].second);
	}

	return ret;
}