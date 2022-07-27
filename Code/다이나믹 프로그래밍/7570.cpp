#include <iostream>
#include <array>

using namespace std;

array<int, 1'000'001> g_cache;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, max_cnt = 0;
	cin >> n;

	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		max_cnt = max(max_cnt, g_cache[num] = g_cache[num - 1] + 1);
	}

	cout << n - max_cnt;
}