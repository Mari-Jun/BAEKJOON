#include <iostream>
#include <queue>
#include <array>
#include <vector>

using namespace std;

struct UnionFind
{
	UnionFind(int size)
		: root(size + 1, -1), size(size + 1, 1)
	{}

	vector<int> root, size;

	int Find(int x)
	{
		if (root[x] == -1) return x;
		else return root[x] = Find(root[x]);
	}

	bool IsSame(int x, int y) { return Find(x) == Find(y); }

	bool Unite(int x, int y)
	{
		x = Find(x);
		y = Find(y);

		if (x == y)
			return false;

		if (size[x] < size[y])
			swap(x, y);

		root[y] = x;
		size[x] += size[y];
		return true;
	}
};

struct LoadInfo
{
	int house_a;
	int house_b;
	int fee;
};

bool operator<(const LoadInfo& a, const LoadInfo& b)
{
	if (a.fee == b.fee)
	{
		if (a.house_a == b.house_a)
			a.house_b > b.house_b;
		else
			a.house_a > b.house_a;
	}
	return a.fee > b.fee;
}

priority_queue<LoadInfo> g_load_queue;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		g_load_queue.emplace(LoadInfo{ a, b, c });
	}

	int cnt = 0;
	int ret = 0;

	UnionFind union_find(n);

	while (cnt < n - 2)
	{
		LoadInfo info = g_load_queue.top();
		g_load_queue.pop();

		if (union_find.Unite(info.house_a, info.house_b))
		{
			++cnt;
			ret += info.fee;
		}
	}

	cout << ret;
}