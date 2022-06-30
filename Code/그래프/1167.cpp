#include <iostream>
#include <vector>

using namespace std;

struct EdgeInfo
{
	int next_node;
	int distance;
};

vector<vector<EdgeInfo>> g_edges;
vector<bool> g_visits;
int g_max_distance = 0;

int FindMaxDist(int cur_node)
{
	int ret = 0;

	for (auto& edge_info : g_edges[cur_node])
	{
		if (g_visits[edge_info.next_node] == false)
		{
			g_visits[edge_info.next_node] = true;

			edge_info.distance += FindMaxDist(edge_info.next_node);
			g_max_distance = max(g_max_distance, ret + edge_info.distance);
			ret = max(ret, edge_info.distance);
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int v;
	cin >> v;

	g_edges.resize(v + 1);
	g_visits.resize(v + 1, false);

	for (int i = 0; i < v; ++i)
	{
		int start, next, distance;
		cin >> start;

		while (true)
		{
			cin >> next;
			if (next == -1)
				break;
			cin >> distance;

			g_edges[start].emplace_back(EdgeInfo{ next, distance });
		}
	}

	for (int node = 1; node <= v; ++node)
	{
		if (g_visits[node] == false)
		{
			g_visits[node] = true;
			FindMaxDist(node);
		}
	}

	cout << g_max_distance;
}