#include <iostream>
#include <queue>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g_edges;
array<int, 20001> g_node_info;
queue<int> g_node_queue;
int g_count = 0;

bool BFS(int start_node)
{
	for (int end_node : g_edges[start_node])
	{
		if (g_node_info[end_node] == -1)
		{
			g_node_info[end_node] = g_count;
			g_node_queue.push(end_node);
		}
		else if (g_node_info[end_node] != g_count)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k;
	cin >> k;

	while (k--)
	{
		g_edges.clear();

		int v, e;
		cin >> v >> e;
		g_edges.resize(v + 1);
		fill(g_node_info.begin(), g_node_info.begin() + v + 1, -1);

		while (e--)
		{
			int start, end;
			cin >> start >> end;

			g_edges[start].push_back(end);
			g_edges[end].push_back(start);
		}

	

		bool exit = false;

		for (int node = 1; node <= v; ++node)
		{
			if (g_node_info[node] != -1)
				continue;

			g_node_queue.push(node);
			g_node_info[node] = g_count = 0;

			while (g_node_queue.empty() == false)
			{
				g_count = (g_count + 1) % 2;

				int size = g_node_queue.size();
				for (int i = 0; i < size; ++i)
				{
					int start_node = g_node_queue.front();
					g_node_queue.pop();
					if (BFS(start_node) == false)
					{
						exit = true;
						break;
					}
				}

				if (exit)
					break;
			}

			while (g_node_queue.empty() == false)
				g_node_queue.pop();

			if (exit)
				break;
		}

		if (exit)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}