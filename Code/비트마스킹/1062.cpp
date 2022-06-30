#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

vector<bitset<26>> g_text_bitset;
bitset<26> g_check_bitset;

int FindReadable(int count, int index)
{
	int ret = 0;
	if (count == 0)
	{
		for (const auto& bitset : g_text_bitset)
		{
			if (bitset == (bitset & g_check_bitset))
				++ret;
		}
	}
	else
	{
		if (index < 26)
		{
			if (g_check_bitset[index] == false)
			{
				g_check_bitset[index] = true;
				ret = max(ret, FindReadable(count - 1, index + 1));
				g_check_bitset[index] = false;
			}

			ret = max(ret, FindReadable(count, index + 1));
		}
	}

	return ret;
}

int main()
{
	int n, k;
	cin >> n >> k;

	string text;
	bitset<26> bitset;
	while (n--)
	{
		bitset.reset();
		cin >> text;
		for (char c : text)
			bitset[c - 'a'] = true;
		g_text_bitset.push_back(bitset);
	}

	int ret = 0;
	if (k >= 5)
	{
		g_check_bitset['a' - 'a'] = g_check_bitset['c' - 'a'] =
			g_check_bitset['i' - 'a'] = g_check_bitset['n' - 'a'] =
			g_check_bitset['t' - 'a'] = true;

		k -= 5;

		ret = FindReadable(k, 0);
	}

	cout << ret;
}