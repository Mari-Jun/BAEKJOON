#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> labtops;
vector<bool> visit;
vector<int> selects;


bool Select(int num);

int main()
{
	int n, m;
	cin >> n >> m;

	labtops.resize(n + 10);
	visit.resize(n + 10, false);
	selects.resize(n + 10, -1);

	while (m--)
	{
		int num, labtop;
		cin >> num >> labtop;
		labtops[num - 1].push_back(labtop - 1);
	}

	int count = 0;
	for (int num = 0; num < n; ++num)
	{
		fill(visit.begin(), visit.end(), false);
		if (Select(num))
			count++;
	}

	cout << count;
}

bool Select(int num)
{
	int index = 0;

	for (int index = 0; index < labtops[num].size(); ++index)
	{
		if (visit[labtops[num][index]])
			continue;

		visit[labtops[num][index]] = true;

		if (selects[labtops[num][index]] == -1 || Select(selects[labtops[num][index]]))
		{
			selects[labtops[num][index]] = num;
			return true;
		}
	}

	return false;
}