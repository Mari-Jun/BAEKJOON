#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

long long n, m;
array<int, 10010> g_loop_times;

long long Search(long long start, long long end)
{
	if (start == end)
	{
		long long count = 0;
		for (int i = 0; i < m; ++i)
		{
			count += (start / g_loop_times[i]);
			if (start % g_loop_times[i] != 0)
				++count;
		}

		for (int i = 0; i < m; ++i)
		{
			if (start % g_loop_times[i] == 0)
			{
				if (++count == n)
					return i + 1;
			}
		}

		return m;
	}

	long long mid = (start + end) / 2;
	long long count = 0;

	for (int i = 0; i < m; ++i)
		count += (mid / g_loop_times[i]) + 1;

	if(count >= n)
		return Search(start, mid);
	else
		return Search(mid + 1, end);
}

int main()
{
	cin >> n >> m;

	int max_time = 0;

	for (int i = 0; i < m; ++i)
	{
		cin >> g_loop_times[i];
		max_time = max(max_time, g_loop_times[i]);
	}

	cout << Search(0, (n / m + 1) * max_time);

}