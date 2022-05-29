#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g_pole_index;

int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		int pole;
		cin >> pole;

		if (g_pole_index.empty() || g_pole_index.back() < pole)
		{
			g_pole_index.push_back(pole);
		}
		else
		{
			auto iter = lower_bound(g_pole_index.begin(), g_pole_index.end(), pole);
			*iter = pole;
		}
	}

	cout << num - g_pole_index.size() << endl;
}