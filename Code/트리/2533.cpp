#include <iostream>
#include <vector>
#include <array>

using namespace std;

constexpr int MAX_FRIEND = 1'000'001;

int n;
array<vector<int>, MAX_FRIEND> friend_node;
array<array<int, MAX_FRIEND>, 2> cache;

int FindEarlyAdapter(int prev_node, int current_node, bool prev_early)
{
	int& ret = cache[prev_early][current_node];

	if (ret != -1) return ret;

	bool is_last_node = true;
	

	//자신이 Early인 경우
	int early_fee = 1;
	for (int next_node : friend_node[current_node])
	{
		if (next_node != prev_node)
		{
			is_last_node = false;
			early_fee += FindEarlyAdapter(current_node, next_node, true);
		}
	}

	int not_early_fee = MAX_FRIEND;
	if (prev_early)
	{
		not_early_fee = 0;
		for (int next_node : friend_node[current_node])
		{
			if (next_node != prev_node)
			{
				is_last_node = false;

				not_early_fee += FindEarlyAdapter(current_node, next_node, false);
			}
		}
	}

	if (is_last_node)
	{
		prev_early == true ? ret = 0 : ret = 1;
		//cout << "current node : " << current_node << " early count : " << early_count << " / " << ret << endl;
	}
	else
	{
		ret = min(early_fee, not_early_fee);
		//cout << "current node : " << current_node << " early count : " << early_count << " / " << early_fee << ", " << not_early_fee << endl;
	}

	return ret;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
		
	cin >> n;

	int node_a, node_b;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> node_a >> node_b;
		friend_node[node_a].push_back(node_b);
		friend_node[node_b].push_back(node_a);
	}

	friend_node[0].push_back(1);

	for (int i = 0; i < 2; ++i)
		cache[i].fill(-1);

	cout << FindEarlyAdapter(0, 1, true);
}