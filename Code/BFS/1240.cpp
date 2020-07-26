#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

vector<vector<pair<int, int>>> edge(1000);
bool visit[1000];

void InitEdge(int);
int FindLength(int, int);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	InitEdge(n - 1);

	while (m--)
	{
		int start, end;
		cin >> start >> end;
		cout << FindLength(start, end) << '\n';
	}
	return 0;
}

void InitEdge(int n)
{
	while (n--)
	{
		int start, end, length;
		cin >> start >> end >> length;

		edge[start - 1].push_back(make_pair(end - 1, length));
		edge[end - 1].push_back(make_pair(start - 1, length));
	}
}

int FindLength(int start, int end)
{
	if (start == end)
		return 0;

	memset(visit, false, sizeof(visit));

	queue<pair<int, int>> q;
	visit[start - 1] = true;
	for (auto index : edge[start - 1])
	{
		if (index.first == end - 1)
			return index.second;
		q.push(make_pair(index.first, index.second));
		visit[index.first] = true;
	}

	while (1)
	{
		int next = q.front().first;
		int length = q.front().second;
		q.pop();
		for (auto index : edge[next])
		{
			if (!visit[index.first])
			{
				if (index.first == end - 1)
					return length + index.second;
				q.push(make_pair(index.first, length + index.second));
				visit[index.first] = true;
			}
		}
	}
}