#include <iostream>
#include <vector>
#include <map>

using namespace std;

class UnionFind
{
public:
	UnionFind() {}

	string Find(string name)
	{
		if (m_root[name].empty()) return name;
		else return m_root[name] = Find(m_root[name]);
	}

	bool Unite(string name_a, string name_b)
	{
		if (m_size[name_a] == 0)
			m_size[name_a] = 1;
		if (m_size[name_b] == 0)
			m_size[name_b] = 1;

		name_a = Find(name_a);
		name_b = Find(name_b);

		if (name_a == name_b) return false;

		if (m_size[name_a] < m_size[name_b])
			swap(name_a, name_b);

		m_root[name_b] = name_a;
		m_size[name_a] += m_size[name_b];
		return true;
	}

	int GetSize(string name)
	{
		return m_size[Find(name)];
	}

private:
	map<string, string> m_root;
	map<string, int> m_size;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_case, f;

	cin >> test_case;

	while (test_case--)
	{
		cin >> f;
		UnionFind uf;
		string a, b;

		while (f--)
		{
			cin >> a >> b;

			uf.Unite(a, b);
			cout << uf.GetSize(a) << '\n';
		}
	}
}
