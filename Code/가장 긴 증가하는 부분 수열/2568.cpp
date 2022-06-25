#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>

using namespace std;

struct Line
{
	int start;
	int end;
};

bool operator<(const Line& a, const Line& b)
{
	return a.start > b.start;
}

int n;
priority_queue<Line> g_lines;
vector<Line> g_trash;
vector<Line> g_cache;
array<int, 500'001> g_previous_num;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	g_previous_num.fill(-1);
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int start, end;
		cin >> start >> end;
		g_lines.emplace(Line{ start, end });
	}

	while (g_lines.empty() == false)
	{
		Line line = g_lines.top();
		g_lines.pop();

		g_trash.emplace_back(line);

		if (g_cache.empty() || g_cache.back().end < line.end)
		{
			if (g_cache.empty() == false)
				g_previous_num[line.start] = g_cache.back().start;
			g_cache.push_back(line);
		}
		else
		{
			auto iter = lower_bound(g_cache.begin(), g_cache.end(), line,
				[](const Line& line_a, const Line& line_b) {
					return line_a.end < line_b.end;
				});

			if (iter != g_cache.begin())
			{
				auto previous_iter = iter - 1;
				g_previous_num[line.start] = previous_iter->start;
			}
			*iter = line;
		}
	}

	int num = g_cache.back().start;
	while (num != -1)
	{
		int new_num = g_previous_num[num];
		g_previous_num[num] = -2;
		num = new_num;
	}

	cout << n - g_cache.size() << '\n';

	for (const auto& line : g_trash)
	{
		if (g_previous_num[line.start] != -2)
			cout << line.start << '\n';
	}
}