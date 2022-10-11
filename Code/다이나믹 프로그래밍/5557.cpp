#include <iostream>
#include <array>

using namespace std;

array<int, 101> nums;
array<array<long long, 21>, 101> cache;
int n;

long long FindValue(int sum, int index)
{
	if (index == n) return sum == nums[index];

	long long& ret = cache[index][sum];

	if (ret != -1) return ret;

	ret = 0;

	{
		int new_sum = sum + nums[index];
		if (new_sum >= 0 && new_sum <= 20)
			ret += FindValue(new_sum, index + 1);
	}

	{
		int new_sum = sum - nums[index];
		if (new_sum >= 0 && new_sum <= 20)
			ret += FindValue(new_sum, index + 1);
	}

	return ret;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> nums[i];

	array<long long, 21> line;
	line.fill(-1);
	cache.fill(line);

	cout << FindValue(nums[1], 2);
}