#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class UnionFind
{
public:
	UnionFind(int size)
		: root(size + 1, -1), size(size + 1, 1)
	{}

	int Find(int node)
	{
		if (root[node] == -1) return node;
		else return root[node] = Find(root[node]);
	}

	bool Unite(int node_a, int node_b)
	{
		node_a = Find(node_a);
		node_b = Find(node_b);

		if (node_a == node_b) return false;

		if (size[node_a] < size[node_b])
			swap(node_a, node_b);

		root[node_b] = node_a;
		size[node_a] += size[node_b];
		return true;
	}

private:
	vector<int> root, size;
};

struct EdgeInfo
{
	int node_a;
	int node_b;
	int distance;
};

bool operator<(const EdgeInfo& a, const EdgeInfo& b)
{
	if (a.distance == b.distance)
	{
		if (a.node_a == b.node_a)
			return a.node_b > b.node_b;
		return a.node_a > b.node_a;
	}
	return a.distance > b.distance;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<char> school_type(n);
	priority_queue<EdgeInfo> edge_queue;

	for (auto& type : school_type)
		cin >> type;

	while (m--)
	{
		int u, v, d;
		cin >> u >> v >> d;

		if (school_type[u - 1] != school_type[v - 1])
			edge_queue.emplace(EdgeInfo{ u, v, d });
	}

	UnionFind union_find(n);
	int cnt = 0;
	int distance = 0;
	while (edge_queue.empty() == false && cnt < n - 1)
	{
		EdgeInfo info = edge_queue.top();
		edge_queue.pop();

		if (union_find.Unite(info.node_a, info.node_b))
		{
			++cnt;
			distance += info.distance;
		}
	}

	if (cnt == n - 1)
		cout << distance;
	else
		cout << -1;

}