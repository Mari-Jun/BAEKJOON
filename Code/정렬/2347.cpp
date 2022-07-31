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

	vector<int> nums;
	nums.reserve(n);

	int num;
	while (n--)
	{
		cin >> num;
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());

	int sum = 1;
	auto iter = nums.begin();
	while (iter != nums.end())
	{
		if (*iter <= sum)
		{
			sum += *iter;
			++iter;
		}
		else
		{
			break;
		}
	}

	cout << sum;
}