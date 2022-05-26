#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

array<array<int, 1002>, 1002> g_cache;

int main()
{
	string text1, text2;
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

	int length = g_cache[text1.size()][text2.size()];

	cout << length << endl;

	string result;
	int i = text1.size();
	int j = text2.size();

	while (length)
	{
		if (g_cache[i - 1][j] == g_cache[i][j])
			--i;
		else if (g_cache[i][j - 1] == g_cache[i][j])
			--j;
		else
		{
			result.push_back(text1[i - 1]);
			--i;
			--j;
			--length;
		}
	}

	reverse(result.begin(), result.end());

	cout << result << endl;

}