#include <iostream>
#include <array>

using namespace std;

array<array<int, 20>, 20> g_distance;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
			cin >> g_distance[y][x];

	int dist = 0;
	bool is_error = false;

	for (int start = 0; start < n; ++start)
	{
		for (int end = start + 1; end < n; ++end)
		{
			bool is_route = true;
			for (int mid = 0; mid < n; ++mid)
			{
				if (mid != start && mid != end)
				{
					if (g_distance[start][end] == g_distance[start][mid] + g_distance[mid][end])
					{
						is_route = false;
						break;
					}
					else if(g_distance[start][end] > g_distance[start][mid] + g_distance[mid][end])
					{
						is_error = true;
						break;
					}
				}
			}

			if (is_error) break;
			if (is_route) dist += g_distance[start][end];
		}
	}

	if (is_error) cout << -1;
	else cout << dist;
}