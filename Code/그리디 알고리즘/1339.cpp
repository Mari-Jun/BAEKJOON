#include <iostream>
#include <queue>
#include <map>

using namespace std;

map<char, int> g_number_map;
priority_queue<int> g_number_queue;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string text;
		cin >> text;

		int num = 1;

		for (int j = text.size() - 1; j >= 0; --j)
		{
			g_number_map[text[j]] += num;
			num *= 10;
		}
	}

	for (const auto& [c, num] : g_number_map)
		g_number_queue.push(num);

	int num = 9;
	int ret = 0;
	while (g_number_queue.empty() == false)
	{
		ret += g_number_queue.top() * num--;
		g_number_queue.pop();
	}
	
	cout << ret;
}
