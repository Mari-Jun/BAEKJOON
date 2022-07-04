#include <iostream>
#include <array>

using namespace std;

array<int, 50> parent_node;
array<bool, 50> is_leaf;

int main()
{
	int n, del, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> parent_node[i];
	is_leaf.fill(true);

	cin >> del;
	parent_node[del] = -2;

	for (int i = 0; i < n; ++i)
	{
		int node = parent_node[i];
		while (node >= 0)
		{
			is_leaf[node] = false;
			node = parent_node[node];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		int node = parent_node[i];
		while (node >= 0)
			node = parent_node[node];

		if (node == -1 && is_leaf[i])
			++cnt;
	}
	
	cout << cnt;
}