#include <iostream>
#include <array>
#include <limits>
#include <queue>

using namespace std;

struct Bus
{
	int arrive_point;
	int fee;
};

bool operator<(const Bus& a, const Bus& b)
{
	if (a.fee == b.fee)
		return a.arrive_point <= b.arrive_point;
	else
		return a.fee < b.fee;
}


int n;
array<vector<Bus>, 1001> g_connect_bus;
array<int, 1001> g_fee;
array<int, 1001> g_route;
array<int, 1001> g_visit;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, start, end, fee;
	cin >> n >> m;
	while (m--)
	{
		cin >> start >> end >> fee;
		g_connect_bus[start].push_back(Bus{ end, fee });
		g_connect_bus[end].push_back(Bus{ end, fee });
	}

	g_fee.fill(numeric_limits<int>::max());
	priority_queue<Bus> queue;

	cin >> start >> end;
	g_fee[start] = 0;
	g_route[start] = 0;
	queue.push(Bus{ start, 0 });

	while (queue.empty() == false)
	{
		Bus bus = queue.top();
		queue.pop();

		if (bus.fee > g_fee[bus.arrive_point])
			continue;

		for (const auto& next_bus : g_connect_bus[bus.arrive_point])
		{
			int new_fee = next_bus.fee + bus.fee;
			if (new_fee < g_fee[next_bus.arrive_point])
			{
				queue.push(Bus{ next_bus.arrive_point, new_fee });
				g_fee[next_bus.arrive_point] = new_fee;
				g_route[next_bus.arrive_point] = bus.arrive_point;
			}
		}
	}
	
	vector<int> route;
	int next_route = end;
	while (next_route != 0)
	{
		route.push_back(next_route);
		next_route = g_route[next_route];
	}

	cout << g_fee[end] << endl;
	cout << route.size() << endl;
	for (auto iter = route.crbegin(); iter != route.crend(); ++iter)
		cout << *iter << ' ';
}