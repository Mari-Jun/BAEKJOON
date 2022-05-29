#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		multiset<int> queue;
		int k;
		cin >> k;

		while (k--)
		{
			char text;
			int n;
			cin >> text >> n;

			if (text == 'I')
			{
				queue.emplace(std::move(n));
			}
			else
			{
				if (queue.empty() == false)
				{
					if (n == -1)
						queue.erase(queue.begin());
					else
						queue.erase(--queue.end());
				}
			}
		}

		if (queue.empty())
			cout << "EMPTY" << endl;
		else
			cout << *queue.crbegin() << ' ' << *queue.cbegin() << endl;

	}
}