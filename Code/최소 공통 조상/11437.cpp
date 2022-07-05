#include <iostream>
#include <array>
#include <vector>

using namespace std;

array<vector<int>, 50'001> g_connect;

array<int, 50'001> g_parents;
array<int, 50'001> g_levels;

void CreateTree(int node, int parent_node)
{
	g_parents[node] = parent_node;
	g_levels[node] = g_levels[parent_node] + 1;

	for (int child_node : g_connect[node])
		if (child_node != parent_node)
			CreateTree(child_node, node);
}

int LCA(int node_a, int node_b)
{
	int a_level = g_levels[node_a];
	int b_level = g_levels[node_b];

	while (a_level != b_level)
	{
		if (a_level > b_level)
		{
			node_a = g_parents[node_a];
			a_level = g_levels[node_a];
		}
		else
		{
			node_b = g_parents[node_b];
			b_level = g_levels[node_b];
		}
	}

	while (node_a != node_b)
	{
		node_a = g_parents[node_a];
		node_b = g_parents[node_b];
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

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		g_connect[a].push_back(b);
		g_connect[b].push_back(a);
	}

	CreateTree(1, 0);

	cin >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
}