#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>

using namespace std;

vector<int> g_switch_index;
vector<int> g_switch;

vector<int> g_infos;
array<int, 10'001> g_previous_num;

int main()
{
	int n;
	cin >> n;

	g_switch_index.resize(n + 1);
	g_switch.resize(n + 1);
	g_previous_num.fill(-1);

	int num;
	for (int i = 1; i <= n; ++i)
	{
		cin >> num;
		g_switch_index[num] = i;
		g_switch[i] = num;
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> num;

		if (g_infos.empty() || g_infos.back() < g_switch_index[num])
		{
			if (g_infos.empty() == false)
				g_previous_num[g_switch_index[num]] = g_infos.back();

			g_infos.push_back(g_switch_index[num]);
		}
		else
		{

			auto iter = lower_bound(g_infos.begin(), g_infos.end(), g_switch_index[num]);
			if (iter != g_infos.begin())
			{
				auto previous_iter = iter - 1;
				g_previous_num[g_switch_index[num]] = *previous_iter;
			}

			*iter = g_switch_index[num];
		}
	}

	cout << g_infos.size() << endl;

	vector<int> ret;

	int index = g_infos.back();

	while (index != -1)
	{
		ret.push_back(g_switch[index]);
		index = g_previous_num[index];
	}
	
	sort(ret.begin(), ret.end());

	for (int num : ret)
		cout << num << ' ';
}