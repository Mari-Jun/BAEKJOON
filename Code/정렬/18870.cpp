#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info
{
	int num, index;
};

vector<Info> g_nums;
vector<int> g_result;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, num;
	cin >> n;
	g_nums.reserve(n);
	g_result.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		g_nums.emplace_back(Info{ num, i });
	}

	sort(g_nums.begin(), g_nums.end(), [](const Info& a, const Info& b) {
		return a.num < b.num;
		});

	int cnt = 0, prev_num = g_nums.begin()->num;
	for (auto iter = g_nums.begin(); iter != g_nums.end(); ++iter)
	{
		if (prev_num != iter->num)
		{
			++cnt;
			prev_num = iter->num;
		}

		g_result[iter->index] = cnt;
	}

	for (int i : g_result)
		cout << i << ' ';
}