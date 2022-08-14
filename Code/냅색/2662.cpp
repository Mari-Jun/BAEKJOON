#include <iostream>
#include <array>

using namespace std;

struct Info
{
	int fee;
	int money;
};

int n, m;
array<array<int, 301>, 21> g_data;
array<array<Info, 301>, 21> g_cache;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		int money;
		cin >> money;
		for (int j = 1; j <= m; ++j)
		{
			cin >> g_data[j][money];
		}
	}

	// 회사까지 money만큼의 돈을 썼을때의 값을 저장한다.
	for (int comp = 1; comp <= m; ++comp)
	{
		for (int money = 0; money <= n; ++money)
		{
			for (int pre_money = 0; pre_money <= money; ++pre_money)
			{
				if (g_cache[comp][money].fee < g_cache[comp - 1][pre_money].fee + g_data[comp][money - pre_money])
				{
					g_cache[comp][money].fee = g_cache[comp - 1][pre_money].fee + g_data[comp][money - pre_money];
					g_cache[comp][money].money = money - pre_money;
				}
			}
		}
	}

	int select_money = n;
	array<int, 21> selects;

	for (int comp = m; comp > 0; --comp)
	{
		selects[comp] = g_cache[comp][select_money].money;
		select_money -= selects[comp];
	}

	cout << g_cache[m][n].fee << '\n';
	for (int comp = 1; comp <= m; ++comp)
		cout << selects[comp] << ' ';
}