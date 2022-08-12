#include <iostream>
#include <array>
#include <vector>

using namespace std;

struct UnionFind
{
	UnionFind(int size)
	{
		is_cycle.resize(size);
		m_size.resize(size, 1);
		m_root.resize(size, -1);
	}

	int Find(int node)
	{
		if (m_root[node] == -1)
			return node;
		else
			return m_root[node] = Find(m_root[node]);
	}

	bool Union(int node_a, int node_b)
	{
		node_a = Find(node_a);
		node_b = Find(node_b);
	
		if (node_a == node_b)
		{
			is_cycle[node_a] = true;
			return false;
		}

		if (m_size[node_a] < m_size[node_b])
			swap(node_a, node_b);

		m_root[node_b] = node_a;
		if (is_cycle[node_a] || is_cycle[node_b])
			is_cycle[node_a] = is_cycle[node_b] = true;
		m_size[node_a] += m_size[node_b];

		return true;
	}

	void FindCycle(int node)
	{
		if (m_root[node] == -1)
			return;

		is_cycle[true];
		FindCycle(m_root[node]);
	}

	bool CheckCycle(int node)
	{
		return is_cycle[node];
	}

	vector<bool> is_cycle;
	vector<int> m_size;
	vector<int> m_root;
};

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, a, b, cnt, test_case = 1;
	while (cin >> n >> m && n != 0 || m != 0)
	{
		cnt = 0;
		UnionFind uf{ n };
		while (m--)
		{
			cin >> a >> b;
			uf.Union(a - 1, b - 1);
		}

		for (int i = 0; i < n; ++i)
		{
			if (uf.Find(i) == i && uf.CheckCycle(i) == false)
				++cnt;
		}

		if (cnt == 0)
			cout << "Case " << test_case << ": No trees.\n";
		else if (cnt == 1)
			cout << "Case " << test_case << ": There is one tree.\n";
		else
			cout << "Case " << test_case << ": A forest of " << cnt << " trees.\n";

		++test_case;
	}
}