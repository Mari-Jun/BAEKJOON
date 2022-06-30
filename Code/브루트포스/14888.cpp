#include <iostream>
#include <array>
#include <limits>

using namespace std;

int n;
array<int, 11> g_nums;

void ConvertMinMax(pair<int, int>& lhs, pair<int, int>&& rhs)
{
	lhs.first = min(lhs.first, rhs.first);
	lhs.second = max(lhs.second, rhs.second);
}

pair<int, int> FindMinMax(int num, int index, int add, int sub, int mul, int div)
{
	if (index == n)
		return { num, num };

	pair<int, int> ret = { numeric_limits<int>::max(), numeric_limits<int>::min() };

	if (add > 0)
		ConvertMinMax(ret, FindMinMax(num + g_nums[index], index + 1, add - 1, sub, mul, div));
	if (sub > 0)
		ConvertMinMax(ret, FindMinMax(num - g_nums[index], index + 1, add, sub - 1, mul, div));
	if (mul > 0)
		ConvertMinMax(ret, FindMinMax(num * g_nums[index], index + 1, add, sub, mul - 1, div));
	if (div > 0)
		ConvertMinMax(ret, FindMinMax(num / g_nums[index], index + 1, add, sub, mul, div - 1));
		
	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> g_nums[i];

	int add, sub, mul, div;
	cin >> add >> sub >> mul >> div;

	auto ret = FindMinMax(g_nums[0], 1, add, sub, mul, div);

	cout << ret.second << endl;
	cout << ret.first << endl;
}