#include <iostream>
#include <array>
#include <limits>

using namespace std;

array<array<int, 401>, 401> g_distance;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int v, e, start, end, distance;
	cin >> v >> e;

	for (auto& dist : g_distance)
		dist.fill(numeric_limits<int>::max());

	while (e--)
	{
		cin >> start >> end >> distance;
		g_distance[start][end] = distance;
	}

	for (int mid_node = 1; mid_node <= v; ++mid_node)
	{
		for (int start_node = 1; start_node <= v; ++start_node)
		{
			for (int end_node = 1; end_node <= v; ++end_node)
			{
				if (mid_node != start_node && mid_node != end_node &&
					g_distance[start_node][mid_node] != numeric_limits<int>::max() &&
					g_distance[mid_node][end_node] != numeric_limits<int>::max())
				{
					g_distance[start_node][end_node] =
						min(g_distance[start_node][end_node], g_distance[start_node][mid_node] + g_distance[mid_node][end_node]);
				}
			}
		}
	}

	int min_cycle = numeric_limits<int>::max();

	for (int start = 1; start <= v; ++start)
	{
		for (int end = start; end <= v; ++end)
		{
			if (g_distance[start][end] != numeric_limits<int>::max() &&
				g_distance[end][start] != numeric_limits<int>::max())
			{
				if (start == end)
					min_cycle = min(min_cycle, g_distance[start][end]);
				else
					min_cycle = min(min_cycle, g_distance[start][end] + g_distance[end][start]);
			}
		}
	}

	if (min_cycle == numeric_limits<int>::max())
		cout << -1;
	else
		cout << min_cycle;
}