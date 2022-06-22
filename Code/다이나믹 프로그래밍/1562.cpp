#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

long long g_cache[100][10][1 << 10];

long long Find(int cur_num, int index, int bit)
{
	long long& ret = g_cache[index][cur_num][bit];
	
	if (ret != -1) return ret;

	ret = 0;

	if (index == 0)
	{
		if (bit == 1023)
			ret = 1;
	}
	else
	{
		if (cur_num + 1 <= 9)
		{
			int new_bit = bit;
			if ((bit & (1 << (cur_num + 1))) != (1 << (cur_num + 1)))
				new_bit += 1 << (cur_num + 1);
			ret += Find(cur_num + 1, index - 1, new_bit);
			ret %= 1'000'000'000;
		}
		if (cur_num - 1 >= 0)
		{
			int new_bit = bit;
			if ((bit & (1 << (cur_num - 1))) != (1 << (cur_num - 1)))
				new_bit += 1 << (cur_num - 1);
			ret += Find(cur_num - 1, index - 1, new_bit);
			ret %= 1'000'000'000;
		}
	}

	return ret;
}

int main()
{
	int n;
	cin >> n;	

	fill(&g_cache[0][0][0], &g_cache[99][9][1 << 10], -1);

	long long ret = 0;

	for (int num = 1; num < 10; ++num)
	{
		ret += Find(num, n - 1, 1 << num);
		ret %= 1'000'000'000;
	}

	cout << ret;
}