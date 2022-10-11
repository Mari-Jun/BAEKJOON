#include <iostream>
#include <array>

using namespace std;

struct Info
{
	Info() {}
	Info(int time, int pay)
		: time(time), pay(pay) {}
	int time = 0, pay = 0;
};

int n;
array<Info, 1'500'001> infos;
array<int, 1'500'001> cache;

int FindMax(int day)
{
	if (day > n) return 0;

	int& ret = cache[day];

	if (ret != -1) return ret;

	ret = 0;

	ret = max(ret, FindMax(day + 1));
	
	int new_day = day + infos[day].time;
	if (new_day <= n + 1)
	{
		ret = max(ret, FindMax(day + infos[day].time) + infos[day].pay);
	}

	return ret;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;

	int time, pay;
	for (int i = 1; i <= n; ++i)
	{
		cin >> time >> pay;
		infos[i] = Info(time, pay);
	}

	cache.fill(-1);

	cout << FindMax(0);
}