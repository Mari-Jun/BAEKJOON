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

	int Find(int x)
	{
		if (root[x] == -1) return x;
		else return root[x] = Find(root[x]);
	}

	bool Unite(int x, int y)
	{
		x = Find(x);
		y = Find(y);

		if (x == y) return false;

		if (size[x] < size[y])
			swap(x, y);

		root[y] = x;
		size[x] += size[y];
		return true;
	}

private:
	vector<int> root, size;
};

struct EdgeInfo
{
	int node_a;
	int node_b;
	long long weight;
};

bool operator<(const EdgeInfo& a, const EdgeInfo& b)
{
	if (a.weight == b.weight)
	{
		if (a.node_a == b.node_a)
			return a.node_b > b.node_b;
		else
			return a.node_a > b.node_a;
	}
	return a.weight > b.weight;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<EdgeInfo> edge_queue;

	int v, e;
	cin >> v >> e;

	while (e--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edge_queue.emplace(EdgeInfo{ a, b, c });
	}

	UnionFind union_find{ v };

	int cnt = 0;
	long long weight = 0;
	while (cnt < v - 1)
	{
		EdgeInfo info = edge_queue.top();
		edge_queue.pop();

		if (union_find.Unite(info.node_a, info.node_b))
		{
			weight += info.weight;
			++cnt;
		}
	}

	cout << weight;
}