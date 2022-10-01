#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Info
{
	int start, end;
};

bool operator<(const Info& a, const Info& b)
{
	if (a.start == b.start)
		return a.end > b.end;
	return a.start > b.start;
}

int main()
{
	int n;
	cin >> n;

	priority_queue<Info> start_queue;
	priority_queue<int, vector<int>, greater<int>> end_queue;

	int start, end;
	while (n--)
	{
		cin >> start >> end;
		start_queue.emplace(Info{ start, end });
	}

	int time = start_queue.top().start;
	size_t max_value = 0;
	while (true)
	{
		while (end_queue.empty() == false && time >= end_queue.top())
			end_queue.pop();

		while (start_queue.empty() == false && time >= start_queue.top().start)
		{
			end_queue.emplace(start_queue.top().end);
			start_queue.pop();
		}

		max_value = max(max_value, end_queue.size());

		if (start_queue.empty())
			break;
		else
			time = start_queue.top().start;
	}

	cout << max_value;
}