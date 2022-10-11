#include <iostream>
#include <array>
#include <limits>

using namespace std;

array<array<int, 501>, 501> cache;
array<int, 501> file_sizes;
array<int, 501> file_sums;
int n;

constexpr int INF = 1'000'000'000;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;

		file_sums[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> file_sizes[i];
			file_sums[i] = file_sums[i - 1] + file_sizes[i];
		}

		for (int dist = 1; dist <= n; ++dist)
		{
			for (int start = 1; start + dist <= n; ++start)
			{
				cache[start][start + dist] = INF;

				for (int mid = start; mid < start + dist; ++mid)
				{
					cache[start][start + dist] = min(cache[start][start + dist],
						cache[start][mid] + cache[mid + 1][start + dist] + file_sums[start + dist] - file_sums[start - 1]);
				}
			}
		}

		cout << cache[1][n] << endl;
	}
}