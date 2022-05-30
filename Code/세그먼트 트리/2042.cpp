#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

array<long long, 1'000'010> g_init_data;
array<long long, 4'000'010> g_segment_tree;

long long CreateSegmentTree(int index_start, int index_end, int node)
{
	if (index_start == index_end)
	{
		g_segment_tree[node] = g_init_data[index_start];
		return g_segment_tree[node];
	}

	int mid = (index_start + index_end) / 2;
	g_segment_tree[node] = CreateSegmentTree(index_start, mid, node * 2) + CreateSegmentTree(mid + 1, index_end, node * 2 + 1);

	return g_segment_tree[node];
}

void UpdateSegmentTree(int index_start, int index_end, int node, int index, long long diff)
{
	if (index_start > index || index_end < index)
		return;

	g_segment_tree[node] += diff;

	if (index_start == index_end)
		return;

	int mid = (index_start + index_end) / 2;

	UpdateSegmentTree(index_start, mid, node * 2, index, diff);
	UpdateSegmentTree(mid + 1, index_end, node * 2 + 1, index, diff);
}

long long GetPrefixSum(int index_start, int index_end, int node, int prefix_start, int prefix_end)
{
	if (prefix_start > index_end || prefix_end < index_start)
		return 0;

	if (prefix_start <= index_start && index_end <= prefix_end)
		return g_segment_tree[node];

	int mid = (index_start + index_end) / 2;
	return GetPrefixSum(index_start, mid, node * 2, prefix_start, prefix_end) +
		GetPrefixSum(mid + 1, index_end, node * 2 + 1, prefix_start, prefix_end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		cin >> g_init_data[i];

	CreateSegmentTree(1, n, 1);

	for (int i = 0; i < m + k; ++i)
	{
		int a;
		cin >> a;

		if (a == 1)
		{
			int b;
			long long c;
			cin >> b >> c;
			long long diff = c - g_init_data[b];
			g_init_data[b] = c;
			UpdateSegmentTree(1, n, 1, b, diff);
		}
		else
		{
			int b, c;
			cin >> b >> c;
			cout << GetPrefixSum(1, n, 1, b, c) << endl;
		}
	}
}