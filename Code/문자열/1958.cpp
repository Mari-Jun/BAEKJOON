#include <iostream>
#include <array>

using namespace std;

array<array<array<int, 101>, 101>, 101> g_lcs;

int main()
{
	string a, b, c;
	cin >> a >> b >> c;

	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < b.size(); ++j)
		{
			for (int k = 0; k < c.size(); ++k)
			{
				if (a[i] == b[j] && b[j] == c[k])
				{
					g_lcs[i + 1][j + 1][k + 1] = g_lcs[i][j][k] + 1;
				}
				else
				{
					g_lcs[i + 1][j + 1][k + 1] = max(g_lcs[i + 1][j + 1][k], max(g_lcs[i][j + 1][k + 1], g_lcs[i + 1][j][k + 1]));
				}
			}
		}
	}

	cout << g_lcs[a.size()][b.size()][c.size()];
}