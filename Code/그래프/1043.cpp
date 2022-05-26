#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

array<std::vector<int>, 60> m_graph;
array<bool, 60> m_visit;

void SearchGraph(int cur_node)
{
	m_visit[cur_node] = true;

	for (int next_node : m_graph[cur_node])
	{
		if (m_visit[next_node] == false)
			SearchGraph(next_node);
	}
}


int main()
{
	m_visit.fill(false);

	int n, m, true_count;
	cin >> n >> m;
	cin >> true_count;

	vector<int> m_know_people;

	while (true_count--)
	{
		int num;
		cin >> num;
		m_know_people.push_back(num);
	}

	vector<vector<int>> partys;

	//그래프 생성
	while (m--)
	{
		int count;
		cin >> count;

		vector<int> party;

		int previous_num = 0;
		while (count--)
		{
			int num;
			cin >> num;

			if (previous_num != 0)
			{
				m_graph[previous_num].push_back(num);
				m_graph[num].push_back(previous_num);
			}

			previous_num = num;

			party.push_back(num);
		}

		partys.emplace_back(std::move(party));
	}

	//그래프 탐색
	for (int node : m_know_people)
		SearchGraph(node);

	int ret = 0;

	//파티 순회
	for (const auto& party : partys)
	{
		bool lying = true;
		for (int num : party)
		{
			if (m_visit[num])
			{
				lying = false;
				break;
			}
		}

		if (lying)
			++ret;
	}

	cout << ret;
	
}