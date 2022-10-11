#include <iostream>
#include <array>
#include <limits>

using namespace std;

int main()
{
	int n;
	cin >> n;

	array<array<int, 2>, 100'001> cache;
	cache.fill({0, 0});

	int answer = numeric_limits<int>::min();

	int val;
	for (int i = 1; i <= n; ++i)
	{
		cin >> val;

		if (i == 1)
		{
			cache[i][0] = cache[i][1] = val;
			answer = max(answer, max(cache[i][0], cache[i][1]));
			continue;
		}

		//계속 더하는 경우와 이번부터 시작하는 경우중 큰 값
		cache[i][0] = max(cache[i - 1][0] + val, val);

		//한번 쉬는 경우와 이미 한번 쉰 경우
		cache[i][1] = max(cache[i - 1][0], cache[i - 1][1] + val);

		answer = max(answer, max(cache[i][0], cache[i][1]));
	}

	cout << answer;
}