#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int n;
array<int, 1000> cache;
array<int, 1000> nums;

int GetMaxLength(int index)
{
	int& ret = cache[index];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int i = index + 1; i < n; ++i)
	{
		if (nums[index] < nums[i])
			ret = max(ret, 1 + GetMaxLength(i));
	}

	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	cache.fill(-1);

	int max_length = 0;

	for (int i = 0; i < n; ++i)
	{
		max_length = max(max_length, GetMaxLength(i));
	}

	cout << max_length;
}