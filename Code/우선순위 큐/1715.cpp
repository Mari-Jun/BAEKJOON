#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	long long ret = 0;

	map<long long, int> card_map;

	while (n--)
	{
		int card;
		cin >> card;

		if (card_map.find(card) == card_map.cend())
			card_map[card] = 1;
		else
			++card_map[card];
	}

	while (true)
	{
		long long card_num = card_map.cbegin()->first;
		int card_set = card_map.cbegin()->second;

		if (card_set % 2 == 0)
		{
			int add_set = (card_set / 2);
			long long new_card_num = card_num * 2;
			ret += new_card_num * add_set;
			card_map.erase(card_num);

			if (card_map.find(new_card_num) == card_map.cend())
				card_map[new_card_num] = add_set;
			else
				card_map[new_card_num] += add_set;
		}
		else
		{
			int add_set = ((card_set - 1) / 2);
			long long new_card_num = card_num * 2;
			ret += new_card_num * add_set;
			card_map[card_num] = 1;

			if (add_set != 0)
			{
				if (card_map.find(new_card_num) == card_map.cend())
					card_map[new_card_num] = add_set;
				else
					card_map[new_card_num] += add_set;
			}

			if (card_map.size() == 1)
				break;
			else
			{
				auto iter = card_map.begin();
				++iter;

				add_set = 1;
				new_card_num = card_num + iter->first;
				ret += new_card_num;
				--iter->second;
				card_map.erase(card_num);

				if (card_map.find(new_card_num) == card_map.cend())
					card_map[new_card_num] = add_set;
				else
					card_map[new_card_num] += add_set;

				if (iter->second == 0)
					card_map.erase(iter->first);
			}
		}
	}

	cout << ret;
}