#include <iostream>
#include <climits>

using namespace std;

int n;
bool g_is_team_a[21];
int g_link_point[21][21];
int g_link_sum_point[21][21];

int FindBestTeam(int num, int team_a, int team_b, bool is_team_a)
{
	if (num == n)
	{
		g_is_team_a[num] = is_team_a;

		int team_a = 0, team_b = 0;

		for (int i = 1; i <= n; ++i)
		{
			if (g_is_team_a[i])
			{
				for (int j = i + 1; j <= n; ++j)
				{
					if(g_is_team_a[j])
						team_a += g_link_sum_point[i][j];
				}
			}
			else
			{
				for (int j = i + 1; j <= n; ++j)
				{
					if(g_is_team_a[j] == false)
						team_b += g_link_sum_point[i][j];
				}
			}
		}

		return abs(team_a - team_b);
	}

	g_is_team_a[num] = is_team_a;

	int ret = INT_MAX;
	if (team_a < n / 2)
		ret = min(ret, FindBestTeam(num + 1, team_a + 1, team_b, true));
	if (team_b < n / 2)
		ret = min(ret, FindBestTeam(num + 1, team_a, team_b + 1, false));

	return ret;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> g_link_point[i][j];

	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			g_link_sum_point[i][j] = g_link_sum_point[j][i] = 
				g_link_point[i][j] + g_link_point[j][i];
		}
	}
		
	cout << FindBestTeam(0, 0, 0, true);
}