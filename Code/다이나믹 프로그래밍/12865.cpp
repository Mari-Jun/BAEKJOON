#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>

using namespace std;

struct Info
{
	int value;
	int weight;
};

bool operator<(const Info& a, const Info& b)
{
	if (a.value == b.value)
		return a.weight < b.weight;
	else
		return a.value < b.value;
}

array<array<int, 101>, 100001> cache;
priority_queue<Info> q;
vector<Info> v_info;

int n, k;

int FindMaxPack(int index, int packed)
{
	if (index > n)
		return 0;

	int& ret = cache[packed][index];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = index; i < n; ++i)
	{
		if (packed + v_info[i].weight <= k)
		{
			ret = max(ret, v_info[i].value + FindMaxPack(i + 1, packed + v_info[i].weight));
		}
	}

	return ret;
}

int main()
{
	cin >> n >> k;

	array<int, 101> ar;
	ar.fill(-1);

	cache.fill(ar);

	for (int i = 0; i < n; ++i)
	{
		int w, v;
		cin >> w >> v;

		v_info.push_back(Info{ v, w });
	}

	int max_pack = FindMaxPack(0, 0);
	cout << max_pack;
}