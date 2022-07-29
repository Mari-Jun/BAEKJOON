#include <iostream>
#include <array>
#include <vector>

using namespace std;

array<int, 100'000> g_in_order;
array<int, 100'000> g_post_order;
vector<int> g_pre_order;
int n;

int FindPreOrder(int i_start, int i_end, int p, int depth)
{
	if (i_start > i_end || p < 0)
		return p;

	for (int i = i_start; i <= i_end; ++i)
	{
		if (g_in_order[i] == g_post_order[p])
		{
			p = FindPreOrder(i + 1, i_end, p - 1, depth + 1);
			p = FindPreOrder(i_start, i - 1, p, depth + 1);
			g_pre_order.push_back(g_in_order[i]);
			break;
		}
	}

	return p;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> g_in_order[i];
	for (int i = 0; i < n; ++i)
		cin >> g_post_order[i];

	FindPreOrder(0, n - 1, n - 1, 0);

	for (auto iter = g_pre_order.crbegin(); iter != g_pre_order.crend(); ++iter)
		cout << *iter << ' ';
}
