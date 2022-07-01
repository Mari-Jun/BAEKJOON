#include <iostream>
#include <vector>
#include <array>

using namespace std;

array<int, 1'000> g_mod_counts;
array<int, 1'000'000> g_sums;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	g_mod_counts.fill(0);

	int sum = 0;
	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		sum += num;
		sum %= m;
		++g_mod_counts[sum];
		g_sums[i] = sum;
	}

	long long cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		int mod = g_sums[i];
		int& count = g_mod_counts[mod];
		--count;

		if (mod == 0)
			++cnt;
		cnt += count;
	}

	cout << cnt;
}