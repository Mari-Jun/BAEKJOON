#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, c;
vector<int> g_house_pos;

int FindMaxDistance(int start, int end, int last_distance)
{
	int mid = (start + end) / 2;

	int cnt = 1, min_distance = INT_MAX;
	int before_pos = g_house_pos[0];
	for (int i = 1; i < n; ++i)
	{
		int distance = g_house_pos[i] - before_pos;
		if (distance >= mid)
		{
			++cnt;
			min_distance = min(min_distance, distance);
			before_pos = g_house_pos[i];
		}
	}

	if (start >= end)
	{
		if (cnt == c)
			return min_distance;
		else
			return last_distance;
	}
	
	if (cnt >= c)
		return FindMaxDistance(mid + 1, end, min_distance);
	else
		return FindMaxDistance(start, mid, last_distance);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> c;

	g_house_pos.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		int pos;
		cin >> pos;
		g_house_pos.push_back(pos);
	}

	sort(g_house_pos.begin(), g_house_pos.end());

	cout << FindMaxDistance(1, (g_house_pos.back() - g_house_pos.front()) / (c - 1), 1);
}