#include <iostream>
#include <array>

using namespace std;

array<array<int, 4001>, 4001> g_cache;

int main()
{
	string a, b;
	cin >> a >> b;

	int max_count = 0;

	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < b.size(); ++j)
		{
			if (a[i] == b[j])
			{
				g_cache[i + 1][j + 1] = g_cache[i][j] + 1;
				max_count = max(max_count, g_cache[i + 1][j + 1]);
			}
		}
	}

	cout << max_count;
}