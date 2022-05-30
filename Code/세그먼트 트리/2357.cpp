#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Node
{
	int max_num;
	int min_num;
};

array<int, 100010> g_numbers;
array<Node, 400040> g_segment_tree;

Node CreateSegmentTree(int start_index, int end_index, int node_index)
{
	if (start_index == end_index)
		return g_segment_tree[node_index] = Node{ g_numbers[start_index], g_numbers[start_index] };

	int mid_index = (start_index + end_index) / 2;

	Node left_node = CreateSegmentTree(start_index, mid_index, node_index * 2);
	Node right_node = CreateSegmentTree(mid_index + 1, end_index, node_index * 2 + 1);

	return g_segment_tree[node_index] = Node{ max(left_node.max_num, right_node.max_num), min(left_node.min_num, right_node.min_num) };
}

Node GetMaxMinValue(int start_index, int end_index, int node_index, int start_range, int end_range)
{
	if (start_range > end_index || end_range < start_index)
		return Node{ 0, INT_MAX };

	if (start_range <= start_index && end_index <= end_range)
		return g_segment_tree[node_index];

	int mid_index = (start_index + end_index) / 2;

	Node left_node = GetMaxMinValue(start_index, mid_index, node_index * 2, start_range, end_range);
	Node right_node = GetMaxMinValue(mid_index + 1, end_index, node_index * 2 + 1, start_range, end_range);

	return Node{ max(left_node.max_num, right_node.max_num), min(left_node.min_num, right_node.min_num) };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> g_numbers[i];

	CreateSegmentTree(1, n, 1);

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		
		Node node = GetMaxMinValue(1, n, 1, a, b);
		cout << node.min_num << ' ' << node.max_num << '\n';
	}
}