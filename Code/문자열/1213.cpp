#include <iostream>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

array<int, 26> g_count; 

int main()
{
	string text;
	cin >> text;

	for (char c : text)
		++g_count[c - 'A'];

	int count = count_if(g_count.begin(), g_count.end(), [](int cnt) {return cnt >= 1; });
	int odd_count = count_if(g_count.begin(), g_count.end(), [](int cnt) {return cnt % 2 == 1; });

	string result = "I'm Sorry Hansoo";
	if (odd_count <= 1)
	{
		result = "";
		for (int i = 0; i < 26; ++i)
		{
			if (g_count[i] >= 2)
			{
				for (int j = 0; j < g_count[i] / 2; ++j)
					result += 'A' + i;
			}
		}

		for (int i = 0; i < 26; ++i)
		{
			if (g_count[i] % 2 == 1)
				result += 'A' + i;
		}

		for (int i = 25; i >= 0; --i)
		{
			if (g_count[i] >= 2)
			{
				for (int j = 0; j < g_count[i] / 2; ++j)
					result += 'A' + i;
			}
		}
	}

	cout << result;
}