#include <iostream>
#include <array>

using namespace std;

array<int, 100'001> g_teams;
array<int, 100'001> g_select;

int no_team_count = 0;

int FindTeam(int index, int team)
{
	if (g_teams[index] == 0)
		return 0;

	if (g_teams[index] == team)
		return index;

	g_teams[index] = team;

	int cycle_index = FindTeam(g_select[index], team);

	if (cycle_index == 0)
	{
		++no_team_count;
		g_teams[index] = 0;
	}
	else
	{
		g_teams[index] = g_teams[cycle_index];
	}

	if (cycle_index == index)
		cycle_index = 0;

	return cycle_index;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_case;
	cin >> test_case;
	int n;

	while (test_case--)
	{
		no_team_count = 0;
		g_teams.fill(-1);

		cin >> n;

		for (int i = 1; i <= n; ++i)
			cin >> g_select[i];

		for (int i = 1; i <= n; ++i)
		{
			if (g_teams[i] == -1)
				FindTeam(i, i);
		}
		cout << no_team_count << '\n';
	}
}