#include <iostream>
#include <memory>
#include <algorithm>
#include <set>
#include <array>
#include <numeric>

using namespace std;

set<int, std::greater<int>> coins;
array<int, 10005> cache;

int DP(int money);

int main()
{
	int n, k;
	cin >> n >> k;

	while (n--)
	{
		int num;
		cin >> num;
		coins.emplace(num);
	}

	cache.fill(-1);

	int result = DP(k);
	if (result >= numeric_limits<int>::max() / 2)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}

	return 0;
}

int DP(int money)
{
	if (money == 0)
	{
		return 0;
	}

	int& ret = cache[money];

	if (ret != -1)
	{
		return ret;
	}

	ret = numeric_limits<int>::max() / 2;

	for (int coin : coins)
	{
		if (money >= coin)
		{
			ret = min(ret, 1 + DP(money - coin));
		}
	}

	return ret;
}