#include <iostream>

using namespace std;

int n;
int num[1000];
int cache[1000][2];

int DP(int index, bool is_up)
{
	int& ret  = cache[index][is_up];

	if (ret != -1)
		return ret;

	ret = 1;
	
	for (int i = 1; i < n - index; ++i)
	{
		//현재 위치보다 큰지?
		if (num[index] < num[index + i] && is_up)
			ret = max(ret, 1 + DP(index + i, true));

		//현재 위치보다 작은지?
		if (num[index] > num[index + i])
			ret = max(ret, 1 + DP(index + i, false));

	}

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> num[i];

	fill(&cache[0][0], &cache[999][2], -1);

	int max_length = 0;
	for (int i = 0; i < n; ++i)
	{
		max_length = max(max_length, DP(i, true));
		max_length = max(max_length, DP(i, false));
	}

	cout << max_length;
}