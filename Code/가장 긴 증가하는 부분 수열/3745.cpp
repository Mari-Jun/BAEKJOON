#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	while (cin >> n)
	{
		vector<int> price;
		int p;

		for (int i = 0; i < n; ++i)
		{
			cin >> p;

			if (price.empty() || price.back() < p)
			{
				price.push_back(p);
			}
			else
			{
				auto iter = lower_bound(price.begin(), price.end(), p);
				*iter = p;
			}
		}

		cout << price.size() << '\n';
	}
}