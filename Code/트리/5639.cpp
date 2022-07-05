#include <iostream>
#include <array>

using namespace std;

array<int, 10'001> g_nodes;

void PostOrder(int start, int end)
{
	if (start >= end)
	{
		if (start == end)
			cout << g_nodes[start] << '\n';
		return;
	}

	int mid = start;
	while (g_nodes[start] > g_nodes[++mid] && mid <= end);

	PostOrder(start + 1, mid - 1);
	PostOrder(mid, end);

	cout << g_nodes[start] << '\n';
}

int main()
{
	int index = 0;
	while (cin >> g_nodes[index++]);

	PostOrder(0, index - 2);
}