#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> nums(n);
	for (auto& num : nums)
		cin >> num;

	sort(nums.begin(), nums.end());

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int left = 0, right = n - 1;
		long long sum = 0;
		while (left < right)
		{
			if (left != i && right != i)
			{
				sum = nums[left] + nums[right];
				if (sum == nums[i])
				{
					++cnt;
					break;
				}
				else if (sum < nums[i])
					++left;
				else
					--right;
			}
			else if (left == i)
				++left;
			else if (right == i)
				--right;
		}
	}

	cout << cnt;
}