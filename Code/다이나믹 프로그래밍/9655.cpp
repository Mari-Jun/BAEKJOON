#include <iostream>
#include <functional>
#include <memory>

using namespace std;


int main()
{
	int cache[1010];
	std::fill_n(cache, 1010, -1);

	int n;
	cin >> n;

	std::function<bool(int, int)> DP = [&](int nokori, int turn)->bool
	{
		if (nokori == 0)
			return (turn % 2 == 0);

		int& ret = cache[nokori];

		if (ret != -1)
			return ret;

		if (turn % 2 == 0)
		{
			ret = DP(nokori - 1, turn + 1);
			if(nokori > 3)
				ret = min(ret, static_cast<int>(DP(nokori - 3, turn + 1)));
		}
		else
		{
			ret = DP(nokori - 1, turn + 1);
			if (nokori > 3)
				ret = max(ret, static_cast<int>(DP(nokori - 3, turn + 1)));
		}

		return ret;
	};

	bool result = DP(n, 0);

	if (result)
		cout << "CY";
	else
		cout << "SK";

}