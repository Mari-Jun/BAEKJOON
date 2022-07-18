#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>

using namespace std;

struct RouteInfo
{
	RouteInfo(int city, int dist) : next_city(city), distance(dist) {}
	int next_city;
	int distance;
};

bool operator<(const RouteInfo& a, const RouteInfo& b)
{
	if (a.distance == b.distance)
		return a.next_city > b.next_city;
	return a.distance > b.distance;
}

int n, m, k;
array<vector<RouteInfo>, 1'001> g_routes;
array<vector<int>, 1'001> g_distance_orders;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;

	int start_city, end_city, distance;
	for (int i = 0; i < m; ++i)
	{
		cin >> start_city >> end_city >> distance;
		g_routes[start_city].emplace_back(end_city, distance);
	}

	priority_queue<RouteInfo> queue;
	queue.emplace(1, 0);
	g_distance_orders[1].emplace_back(0);

	while (queue.empty() == false)
	{
		RouteInfo current_route = queue.top();
		queue.pop();
		
		for (const auto& next_route : g_routes[current_route.next_city])
		{
			int new_dist = next_route.distance + current_route.distance;
			if (g_distance_orders[next_route.next_city].size() < k ||
				(g_distance_orders[next_route.next_city].size() == k && 
				g_distance_orders[next_route.next_city][k - 1] > new_dist))
			{
				queue.emplace(next_route.next_city, new_dist);
				g_distance_orders[next_route.next_city].emplace_back(new_dist);
				sort(g_distance_orders[next_route.next_city].begin(), g_distance_orders[next_route.next_city].end());
				if (g_distance_orders[next_route.next_city].size() > k)
					g_distance_orders[next_route.next_city].erase(g_distance_orders[next_route.next_city].begin() + k, g_distance_orders[next_route.next_city].end());
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (g_distance_orders[i].size() < k) cout << -1 << '\n';
		else cout << g_distance_orders[i][k - 1] << '\n';
	}
}