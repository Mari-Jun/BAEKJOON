#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

array<int, 501> g_line;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int start, end;
	for (int i = 0; i < n; ++i)
	{
		cin >> start >> end;
		g_line[start] = end;
	}

	vector<int> connection;

	for (int i = 1; i <= 500; ++i)
	{
		if (g_line[i] != 0)
		{
			if (connection.empty() || connection.back() < g_line[i])
			{
				connection.push_back(g_line[i]);
			}
			else
			{
				auto iter = lower_bound(connection.begin(), connection.end(), g_line[i]);
				*iter = g_line[i];
			}
		}
	}

	cout << n - connection.size();
}