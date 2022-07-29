#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g_nums;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x;
	cin >> n;

	g_nums.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> g_nums[i];

	sort(g_nums.begin(), g_nums.end());

	cin >> x;

	int sum = 0, start = 0, end = n - 1, ret = 0;

	while (start < end)
	{
		int added = g_nums[start] + g_nums[end];
		if (added == x)
		{
			++ret;
			++start;
			--end;
		}
		else if (added > x)
		{
			--end;
		}
		else
		{
			++start;
		}
	}

	cout << ret;
}