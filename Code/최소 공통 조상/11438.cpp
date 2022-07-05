#include <iostream>
#include <vector>
#include <array>

using namespace std;

constexpr int g_max_level = 18;

array<vector<int>, 100'001> g_connect_nodes;
array<array<int, g_max_level>, 100'001> g_parents;
array<int, 100'001> g_levels;

void CreateTree(int node, int parent_node)
{
	g_levels[node] = g_levels[parent_node] + 1;
	g_parents[node][0] = parent_node;

	for (int level = 1; level < g_max_level; ++level)
		g_parents[node][level] = g_parents[g_parents[node][level - 1]][level - 1];

	for (int child_node : g_connect_nodes[node])
		if (child_node != parent_node)
			CreateTree(child_node, node);
}

int LCA(int node_a, int node_b)
{
	if (g_levels[node_a] < g_levels[node_b])
		swap(node_a, node_b);

	if (g_levels[node_a] != g_levels[node_b])
	{
		for (int level = g_max_level - 1; level >= 0; --level)
			if (g_levels[g_parents[node_a][level]] >= g_levels[node_b])
				node_a = g_parents[node_a][level];
	}

	if (node_a != node_b)
	{
		for (int level = g_max_level - 1; level >= 0; --level)
		{
			if (g_parents[node_a][level] != g_parents[node_b][level])
			{
				node_a = g_parents[node_a][level];
				node_b = g_parents[node_b][level];
			}
		}

		node_a = g_parents[node_a][0];
	}
	
	return node_a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n;

	int a, b;
	for (int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		g_connect_nodes[a].push_back(b);
		g_connect_nodes[b].push_back(a);
	}

	CreateTree(1, 0);

	cin >> m;

	while (m--)
	{
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}

}