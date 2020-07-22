#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

using r_vector = vector<vector<pair<int, int>>>;
using p_queue = priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

void FindMinLength(p_queue dij_queue, vector<int>& min_length, r_vector route);
void PrintResult(vector<int> min_length);

int main()
{
	int vertex_num, edge_num;
	cin >> vertex_num >> edge_num;

	int start_vertex;
	cin >> start_vertex;

	//route[start_vertex] = <end_vertex, length>
	r_vector route(vertex_num);

	for (auto input = 0; input < edge_num; input++)
	{
		int start_vertex, end_vertex, length;
		cin >> start_vertex >> end_vertex >> length;
		route[start_vertex - 1].push_back(make_pair(end_vertex - 1, length));
	}
	
	//<int, int> = <거리값, 현재 정점>
	p_queue dij_queue;
	vector<int> min_length(vertex_num);

	for (auto index = 0; index < min_length.size(); index++)
	{
		if (index == start_vertex - 1)
		{
			min_length[index] = 0;
			dij_queue.push(make_pair(0, index));
		}
		else
		{
			min_length[index] = INT_MAX / 2;
			dij_queue.push(make_pair(INT_MAX / 2, index));
		}
	}

	FindMinLength(dij_queue, min_length, route);
	PrintResult(min_length);

	return 0;
}

void FindMinLength(p_queue dij_queue, vector<int>& min_length, r_vector route) {

	int vertex_num = min_length.size();

	while (!dij_queue.empty())
	{
		int length = dij_queue.top().first;
		int vertex = dij_queue.top().second;
		dij_queue.pop();

		if (min_length[vertex] >= length)
		{
			for (auto index = 0; index < route[vertex].size(); index++)
			{
				int next_vertex = route[vertex][index].first;
				int route_length = route[vertex][index].second;
				
				if (min_length[next_vertex] > length + route_length) 
				{
					min_length[next_vertex] = length + route_length;
					dij_queue.push(make_pair(length + route_length, next_vertex));
				}
				
			}
		}
	}
}

void PrintResult(vector<int> min_length)
{
	for (vector<int>::iterator iter = min_length.begin(); iter != min_length.end(); iter++)
	{
		if (*iter == INT_MAX / 2)
			cout << "INF" << '\n';
		else
			cout << *iter << '\n';
	}
}