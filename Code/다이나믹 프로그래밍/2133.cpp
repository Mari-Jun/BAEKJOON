#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 31> cache;
	cache.fill(0);
	cache[0] = 1;

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		if (i >= 2)
		{
			cache[i] += cache[i - 2] * 3;
		}

		for (int j = 4; j <= 30; j += 2)
		{
			if (i >= j)
			{
				cache[i] += cache[i - j] * 2;
			}
		}
	}

	cout << cache[n];
}