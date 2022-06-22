#include <iostream>
#include <stack>
#include <array>
#include <vector>

using namespace std;

array<bool, 100'001> g_is_docking;
array<int, 100'001> g_airplane_gate;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int g, p;
	cin >> g >> p;

	int gate, max_gate = p - 1;
	int ret = 0;
	for (int i = 1; i <= p; ++i)
	{
		cin >> gate;

		if (i > g)
			continue;

		bool is_docking = false;

		for (int j = min(max_gate, gate - 1); j >= 0; --j)
		{
			if (g_is_docking[j] == false)
			{
				is_docking = g_is_docking[j] = true;
				if (j == max_gate)
				{
					for (int k = j; k >= 0; --k)
					{
						if (g_is_docking[k] == false)
						{
							max_gate = k;
							break;
						}
					}
				}
				++ret;
				break;
			}
		}

		if (is_docking == false)
			break;
	}

	cout << ret;
}