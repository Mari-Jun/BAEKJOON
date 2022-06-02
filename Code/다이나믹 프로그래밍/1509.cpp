#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

string g_text;
array<array<int, 2'510>, 2'510> g_cache;

int DP(int start_index, int end_index)
{
	if (end_index == g_text.size())
		return INT_MAX;

	int& ret = g_cache[start_index][end_index];

	if (ret != -1)
		return ret;

	ret = INT_MAX;

	bool is_same = true;
	int start = start_index, end = end_index;

	while (start < end)
	{
		if (g_text[start++] != g_text[end--])
		{
			is_same = false;
			break;
		}
	}

	if (is_same)
	{
		if (end_index == g_text.size() - 1)
			ret = 1;
		else
			ret = 1 + DP(end_index + 1, end_index + 1);
	}

	ret = min(ret, DP(start_index, end_index + 1));

	return ret;
}

int main()
{
	cin >> g_text;

	array<int, 2'510> ar{};
	ar.fill(-1);
	g_cache.fill(ar);

	cout << DP(0, 0);
}