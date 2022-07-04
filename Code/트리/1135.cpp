#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <queue>

using namespace std;

vector<vector<int>> g_connect_vector;

int Find(int node)
{
	int size = static_cast<int>(g_connect_vector[node].size());
	int ret = 0;

	priority_queue<int, vector<int>, greater<int>> child_order;

	for (int child_node : g_connect_vector[node])
		child_order.push(Find(child_node));

	while (child_order.empty() == false)
	{
		ret = max(ret, child_order.top() + size--);
		child_order.pop();
	}

	return ret;
}

int main()
{
	int n;
	cin >> n;
	g_connect_vector.resize(n);

	int num;
	cin >> num;
	for (int i = 1; i < n; ++i)
	{
		cin >> num;
		g_connect_vector[num].push_back(i);
	}

	cout << Find(0);
}