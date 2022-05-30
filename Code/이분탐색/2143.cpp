#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> g_first_data;
vector<int> g_second_data;

map<int, int> g_first_map_data;
map<int, int> g_second_map_data;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n, m;

	cin >> t;

	cin >> n;
	g_first_data.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		g_first_data.push_back(num);
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; ++j)
		{
			sum += g_first_data[j];
			++g_first_map_data[sum];
		}
	}

	cin >> m;
	g_second_data.reserve(m);
	for (int i = 0; i < m; ++i)
	{
		int num;
		cin >> num;
		g_second_data.push_back(num);
	}

	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j = i; j < m; ++j)
		{
			sum += g_second_data[j];
			++g_second_map_data[sum];
		}
	}

	long long ret = 0;

	for (const auto& [num, count] : g_first_map_data)
		ret += static_cast<long long>(count) * g_second_map_data[t - num];

	cout << ret;
}