#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <limits>

using namespace std;

int n, m;

struct Node
{
	Node(int node, int fee)
		: next_node(node), route_fee(fee) {}
	int next_node;
	int route_fee;
};

bool operator<(const Node& a, const Node& b)
{
	if (a.route_fee == b.route_fee)
		return a.next_node > b.next_node;
	else
		return a.route_fee > b.route_fee;
}

array<vector<Node>, 50'001> g_route;
array<int, 50'001> g_min_route_fee;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	int a, b, c;
	while (m--)
	{
		cin >> a >> b >> c;
		g_route[a].emplace_back(b, c);
		g_route[b].emplace_back(a, c);
	}

	g_min_route_fee.fill(numeric_limits<int>::max());

	priority_queue<Node> queue;
	queue.emplace(1, 0);

	while (queue.empty() == false)
	{
		Node cur_node = queue.top();
		queue.pop();

		if (g_min_route_fee[cur_node.next_node] > cur_node.route_fee)
		{
			g_min_route_fee[cur_node.next_node] = cur_node.route_fee;

			for (const auto& node : g_route[cur_node.next_node])
			{
				int new_fee = cur_node.route_fee + node.route_fee;
				queue.emplace(node.next_node, new_fee);
			}
		}
	}
	
	cout << g_min_route_fee[n];
}