#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int child_node = 0;
	int weight = 0;
};

array<vector<Node>, 10001> g_node_infos;
int max_weight = 0;

int FindRadius(int cur_node)
{
	auto& nodes = g_node_infos[cur_node];

	int ret = 0;

	for (auto& node : nodes)
	{
		node.weight += FindRadius(node.child_node);
		max_weight = max(max_weight, ret + node.weight);
		ret = max(ret, node.weight);
	}

	return ret;
}

int main()
{
	int n;
	cin >> n;

	while (--n)
	{
		int parent_node, child_node, weight;
		cin >> parent_node >> child_node >> weight;

		auto& node = g_node_infos[parent_node];

		node.emplace_back(Node{ child_node, weight });
	}

	FindRadius(1);
	cout << max_weight;
}