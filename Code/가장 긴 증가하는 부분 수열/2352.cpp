#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g_port_index;

int main()
{
	int num;
	cin >> num;

	while (num--)
	{
		int port;
		cin >> port;

		if (g_port_index.empty() || g_port_index.back() < port)
		{
			g_port_index.push_back(port);
		}
		else
		{
			auto iter = lower_bound(g_port_index.begin(), g_port_index.end(), port);
			*iter = port;
		}
	}

	cout << g_port_index.size() << endl;
}