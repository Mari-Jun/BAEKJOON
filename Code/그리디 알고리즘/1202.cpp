#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <map>

using namespace std;

map<int, priority_queue<int>> g_jewelry;
priority_queue<int, vector<int>, greater<int>> g_backpack;

struct JewelryInfo
{
	int price;
	int weight;
};

bool operator<(const JewelryInfo& a, const JewelryInfo& b)
{
	if (a.price == b.price)
		return a.weight < b.weight;
	else
		return a.price < b.price;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		int weight, price;
		cin >> weight >> price;

		g_jewelry[weight].push(price);
	}

	for (int i = 0; i < k; ++i)
	{
		int weight;
		cin >> weight;
		g_backpack.push(weight);
	}

	long long result = 0;
	priority_queue<JewelryInfo> jewelry;

	auto iter = g_jewelry.begin();

	while (g_backpack.empty() == false)
	{
		int weight = g_backpack.top();
		g_backpack.pop();

		for (iter; iter != g_jewelry.end(); ++iter)
		{
			if (iter->first > weight)
				break;

			if (iter->second.empty() == false)
			{
				jewelry.push({ iter->second.top(), iter->first });
				iter->second.pop();
			}
		}

		if (jewelry.empty() == false)
		{
			auto jewelry_info = jewelry.top();
			jewelry.pop();

			if (g_jewelry[jewelry_info.weight].empty() == false)
			{
				jewelry.push({ g_jewelry[jewelry_info.weight].top(), jewelry_info.weight });
				g_jewelry[jewelry_info.weight].pop();
			}

			result += jewelry_info.price;
		}
	}

	cout << result;
}