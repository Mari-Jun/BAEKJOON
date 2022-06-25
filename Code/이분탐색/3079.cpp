#include <iostream>
#include <array>
#include <climits>
#include <cmath>

using namespace std;

long long n, m;
array<long long, 100'000> g_times;

long long FindMinTime(long long start, long long end)
{
	if (start >= end)
		return start;

	long long mid = (start + end) / 2;

	long long sum = 0;
	for (int i = 0; i < n; ++i)
		sum += mid / g_times[i];

	if (sum >= m)
		return FindMinTime(start, mid);
	else
		return FindMinTime(mid + 1, end);
}

int main()
{
	cin >> n >> m;

	long long min_time = LLONG_MAX;
	long long max_time = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> g_times[i];
		min_time = min(min_time, g_times[i]);
		max_time = max(max_time, g_times[i]);
	}

	long long loop = static_cast<long long>(ceil(static_cast<long double>(m) / n));
	long long start = min_time * loop;
	long long end = max_time * loop;

	cout << FindMinTime(start, end);
}