#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<map<int, bool>> g_node_infos;
vector<bool> g_node_visit;

int g_edge_count = 0;
map<int, int> g_loop_count;

int DFS(int before_node, int cur_node)
{
	int loop_count = 0;

	for (const auto& [next_node, kill] : g_node_infos[cur_node])
	{
		if (g_node_visit[next_node])
		{
			if (next_node != before_node && g_node_infos[cur_node][next_node] == false)
			{
				++loop_count;
				++g_loop_count[next_node];
				++g_edge_count;
				g_node_infos[cur_node][next_node] = true;
				g_node_infos[next_node][cur_node] = true;
			}
		}
		else
		{
			g_node_visit[next_node] = true;
			int count = DFS(cur_node, next_node);
			if (count > 0)
			{
				loop_count += count;
				++g_edge_count;
				g_node_infos[cur_node][next_node] = true;
				g_node_infos[next_node][cur_node] = true;
			}
		}
	}

	if (g_loop_count[cur_node] != 0)
	{
		loop_count -= g_loop_count[cur_node];
		g_loop_count[cur_node] = 0;
	}

	return loop_count;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int v, e;
	cin >> v >> e;

	g_node_infos.resize(v + 1);
	g_node_visit.resize(v + 1);

	for (int i = 0; i < e; ++i)
	{
		int start, end;
		cin >> start >> end;

		g_node_infos[start][end] = false;
		g_node_infos[end][start] = false;
	}

	g_node_visit[1] = true;
	DFS(0, 1);

	cout << e - g_edge_count << endl;

	for (int i = 1; i <= v; ++i)
	{
		for (const auto& [next_node, kill] : g_node_infos[i])
		{
			if (kill == false && i < next_node)
				cout << i << ' ' << next_node << '\n';
		}
	}
}