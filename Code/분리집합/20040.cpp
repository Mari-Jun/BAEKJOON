#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
public:
	UnionFind(int size)
		: m_root(size, -1), m_size(size, 1)
	{}

	int Find(int node)
	{
		if (m_root[node] == -1) return node;
		else return m_root[node] = Find(m_root[node]);
	}

	bool Unite(int node_a, int node_b)
	{
		node_a = Find(node_a);
		node_b = Find(node_b);

		if (node_a == node_b) return false;

		if (m_size[node_a] < m_size[node_b])
			swap(node_a, node_b);

		m_root[node_b] = node_a;
		m_size[node_a] += m_size[node_b];

		return true;
	}

private:
	vector<int> m_root, m_size;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	UnionFind uf{ n };

	int cnt = 0;
	for (int i = 1; i <= m; ++i)
	{
		int node_a, node_b;
		cin >> node_a >> node_b;

		if (uf.Unite(node_a, node_b) == false)
		{
			cnt = i;
			break;
		}
	}

	cout << cnt;
}