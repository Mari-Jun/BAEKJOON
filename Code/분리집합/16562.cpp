#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class UnionFind
{
public:
	UnionFind()
	{
		m_size.fill(1);
		m_root.fill(-1);
		m_friend_money.fill(numeric_limits<int>::max());
	}

	void PutFriendMoney(int n)
	{
		for (int i = 0; i < n; ++i)
			cin >> m_friend_money[i];
	}

	int Find(int node)
	{
		if (m_root[node] == -1)
			return node;
		else
			return m_root[node] = Find(m_root[node]);
	}

	bool Unite(int node_a, int node_b)
	{
		node_a = Find(node_a);
		node_b = Find(node_b);

		if (node_a == node_b)
			return true;

		if (m_size[node_a] < m_size[node_b])
			swap(node_a, node_b);

		m_root[node_b] = node_a;
		m_size[node_a] += m_size[node_b];
		m_friend_money[node_a] = min(m_friend_money[node_a], m_friend_money[node_b]);
		return false;
	}

	int GetFriendMoney(int node)
	{
		node = Find(node);
		int ret = m_friend_money[node];
		m_friend_money[node] = 0;
		return ret;
	}

private:
	array<int, 10'000> m_size;
	array<int, 10'000> m_root;
	array<int, 10'000> m_friend_money;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	UnionFind uf;
	uf.PutFriendMoney(n);

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		uf.Unite(a - 1, b - 1);
	}

	bool is_good = true;
	int money = 0;
	for (int i = 0; i < n; ++i)
	{
		int ret = uf.GetFriendMoney(i);
		if (ret <= k)
		{
			k -= ret;
			money += ret;
		}
		else
		{
			is_good = false;
			break;
		}
	}

	if (is_good)
		cout << money;
	else
		cout << "Oh no";
}