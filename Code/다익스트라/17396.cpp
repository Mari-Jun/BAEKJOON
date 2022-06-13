#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

struct Info
{
	int next_point;
	int distance;
};

struct QueueInfo
{
	int point;
	long long distance;
};

bool operator<(const QueueInfo& a, const QueueInfo& b)
{
	if (a.distance == b.distance)
		return a.point > b.point;
	else
		return a.distance > b.distance;
}

bool g_visible[100001];
long long g_distance[100001];
std::vector<std::vector<Info>> g_point_infos;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	fill_n(g_distance, 100001, LLONG_MAX);
	g_point_infos.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> g_visible[i];

	for (int i = 0; i < m; ++i)
	{
		int start_point, end_point, distance;
		cin >> start_point >> end_point >> distance;

		if ((g_visible[start_point] == false || start_point == n - 1) 
			&& (g_visible[end_point] == false || end_point == n - 1))
		{
			g_point_infos[start_point].emplace_back(Info{ end_point, distance });
			g_point_infos[end_point].emplace_back(Info{ start_point, distance });
		}
	}

	priority_queue<QueueInfo> queue;
	queue.push(QueueInfo{ 0, 0 });
	g_distance[0] = 0;

	while (queue.empty() == false)
	{
		QueueInfo start_info = queue.top();

		queue.pop();

		if (start_info.distance <= g_distance[start_info.point])
		{
			for (const auto& info : g_point_infos[start_info.point])
			{
				long long& to_distance = g_distance[info.next_point];
				if (to_distance > start_info.distance + info.distance)
				{
					to_distance = start_info.distance + info.distance;
					queue.push(QueueInfo{ info.next_point, to_distance });
				}
			}
		}
	}

	if (g_distance[n - 1] == LLONG_MAX)
		cout << -1;
	else
		cout << g_distance[n - 1];
}