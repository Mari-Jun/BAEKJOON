#include <iostream>
#include <array>
#include <climits>

using namespace std;

array<int, 100'010> g_heights;
array<int, 400'040> g_segment_tree;

int n;

int CreateSegmentTree(int start_index, int end_index, int node)
{
	if (start_index == end_index)
		return g_segment_tree[node] = start_index;

	int mid_index = (start_index + end_index) / 2;

	int left_index = CreateSegmentTree(start_index, mid_index, node * 2);
	int right_index = CreateSegmentTree(mid_index + 1, end_index, node * 2 + 1);

	if (g_heights[left_index] <= g_heights[right_index])
		return g_segment_tree[node] = left_index;
	else
		return g_segment_tree[node] = right_index;
}

int FindMinHeightIndexInHistogram(int start_index, int end_index, int node, int start_range, int end_range)
{
	if (start_index > end_range || end_index < start_range)
		return 0;

	if(start_index >= start_range && end_index <= end_range)
		return g_segment_tree[node];

	int mid_index = (start_index + end_index) / 2;

	int left_index = FindMinHeightIndexInHistogram(start_index, mid_index, node * 2, start_range, end_range);
	int right_index = FindMinHeightIndexInHistogram(mid_index + 1, end_index, node * 2 + 1, start_range, end_range);

	if (g_heights[left_index] <= g_heights[right_index])
		return left_index;
	else
		return right_index;
}

int DivideHistogram(int start_range, int end_range)
{
	if (start_range >= end_range)
		return g_heights[start_range];

	int min_height_index = FindMinHeightIndexInHistogram(1, n, 1, start_range, end_range);

	int area = g_heights[min_height_index] * (end_range - start_range + 1);

	area = max(area, DivideHistogram(start_range, min_height_index - 1));
	area = max(area, DivideHistogram(min_height_index + 1, end_range));

	return area;
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> g_heights[i];
	g_heights[0] = INT_MAX;

	CreateSegmentTree(1, n, 1);

	cout << DivideHistogram(1, n);
}