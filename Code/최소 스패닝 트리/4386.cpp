#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class UnionFind
{
public:
	UnionFind(int size)
	{
		roots.resize(size, -1);
		sizes.resize(size, 1);
	}

	int Find(int node)
	{
		if (roots[node] != -1)
			return roots[node] = Find(roots[node]);
		else
			return node;
	}

	bool Unite(int node_a, int node_b)
	{
		node_a = Find(node_a);
		node_b = Find(node_b);

		if (node_a == node_b) return false;

		if (sizes[node_a] < sizes[node_b])
		{
			swap(node_a, node_b);
		}

		roots[node_b] = node_a;
		sizes[node_a] += sizes[node_b];

		return true;
	}

private:
	vector<int> roots;
	vector<int> sizes;
};

struct Point
{
	Point(float x, float y) : x(x), y(y) {}
	float x, y;
};

bool operator<(const Point& a, const Point& b)
{
	if (a.x == b.x) return a.y > b.y;
	return a.x > b.x;
}

struct QueuePoint
{
	QueuePoint(int s, int e, float d) : start(s), end(e), distance(d) {}
	int start = -1, end = -1;
	float distance = 0.0f;
};

bool operator<(const QueuePoint& a, const QueuePoint& b)
{
	if (a.distance == b.distance)
	{
		if (a.start == b.start)
			return a.end > b.end;
		return a.start > b.start;
	}
	return a.distance > b.distance;
}

int main()
{
	int n;
	cin >> n;

	vector<Point> points;
	map<Point, int> index_map;

	float x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		points.emplace_back(x, y);
		index_map.emplace(Point{ x, y }, i);
	}

	priority_queue<QueuePoint> queue;

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			float dist = 0.0f;
			const Point& a = points[i];
			const Point& b = points[j];

			dist = sqrtf(powf(a.x - b.x, 2.0f) + powf(a.y - b.y, 2.0f));
			queue.emplace(index_map[a], index_map[b], dist);
		}
	}

	UnionFind uf{ n };

	float answer = 0.f;
	while (queue.empty() == false)
	{
		const QueuePoint& top = queue.top();

		if (uf.Unite(top.start, top.end))
			answer += top.distance;

		queue.pop();
	}

	cout.precision(3);
	cout << answer;
}