#include <iostream>
#include <array>
#include <limits>
#include <algorithm>

using namespace std;

int n, m;

struct Info
{
	int memory, fee;
};

int min_fee = numeric_limits<int>::max();
array<Info, 101> g_info;
array<array<int, 10'001>, 101> g_cache;


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int fee_sum = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> g_info[i].memory;
	for (int i = 1; i <= n; ++i)
	{
		cin >> g_info[i].fee;
		fee_sum += g_info[i].fee;
	}
	
	for (int index = 1; index <= n; ++index)
	{
		for (int fee = 0; fee <= fee_sum; ++fee)
		{
			if (fee - g_info[index].fee >= 0)
			{
				g_cache[index][fee] = max(g_cache[index][fee], g_cache[index - 1][fee - g_info[index].fee] + g_info[index].memory);
			}
			g_cache[index][fee] = max(g_cache[index][fee], g_cache[index - 1][fee]);
		}
	}

	for (int fee = 0; fee <= fee_sum; ++fee)
	{
		if (g_cache[n][fee] >= m)
		{
			cout << fee;
			break;
		}
	}
}