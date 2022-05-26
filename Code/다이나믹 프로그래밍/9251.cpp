#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

array<array<int, 1002>, 1002> g_cache;

string text1, text2;

int main()
{
	cin >> text1 >> text2;

	for (int i = 0; i < text1.size(); ++i)
	{
		for (int j = 0; j < text2.size(); ++j)
		{
			if (text1[i] == text2[j])
			{
				g_cache[i + 1][j + 1] = g_cache[i][j] + 1;
			}
			else
			{
				g_cache[i + 1][j + 1] = max(g_cache[i][j + 1], g_cache[i + 1][j]);
			}
		}
	}

	cout << g_cache[text1.size()][text2.size()];
}