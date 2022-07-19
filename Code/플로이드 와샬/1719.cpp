#include <iostream>
#include <array>
#include <limits>

using namespace std;

array<array<int, 201>, 201> g_map;
array<array<int, 201>, 201> g_route;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (auto& map : g_map)
		map.fill(numeric_limits<int>::max());
	for (auto& route : g_route)
		route.fill(0);

	int start, end, time;
	while (m--)
	{
		cin >> start >> end >> time;
		g_map[start][end] = g_map[end][start] = time;
		g_route[start][end] = end;
		g_route[end][start] = start;
	}

	for (int mid = 1; mid <= n; ++mid)
	{
		for (int start = 1; start <= n; ++start)
		{
			for (int end = 1; end <= n; ++end)
			{
				if (mid != start && mid != end && start != end &&
					g_map[start][mid] != numeric_limits<int>::max() &&
					g_map[mid][end] != numeric_limits<int>::max())
				{
					if (g_map[start][end] > g_map[start][mid] + g_map[mid][end])
					{
						g_map[start][end] = g_map[start][mid] + g_map[mid][end];
						g_route[start][end] = g_route[start][mid];
					}
				}
			}
		}
	}

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			if (g_route[y][x] == 0)
				cout << '-';
			else
				cout << g_route[y][x];
			cout << ' ';
		}
		cout << '\n';
	}
}