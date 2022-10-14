#include <iostream>
#include <array>

using namespace std;

constexpr int MOD = 1'000'000'003;

array<array<array<int, 2>, 1002>, 1002> cache;

int main()
{
	int n, k;
	cin >> n >> k;

	int answer = 0;
	if (n / 2 >= k)
	{
		//하나를 적용한 경우
		for (int index = 1; index <= n; ++index)
		{
			if (index == 1)
				cache[1][index + 1] = { 0, 1 };
			else
				cache[1][index + 1] = { 1, 0 };
		}

		for (int index = 1; index <= n; ++index)
		{
			for (int count = 2; count <= k; ++count)
			{
				cache[count][index + 1][0] += cache[count - 1][index - 1][0] + cache[count][index][0];
				cache[count][index + 1][0] %= MOD;
				cache[count][index + 1][1] += cache[count - 1][index - 1][1] + cache[count][index][1];
				cache[count][index + 1][1] %= MOD;
			}
		}

		for (int index = 1; index <= n; ++index)
		{
			answer += cache[k][index + 1][0];
			answer %= MOD;
			if (index != n)
			{
				answer += cache[k][index + 1][1];
				answer %= MOD;
			}
		}
	}

	/*for (int count = 1; count <= k; ++count)
	{
		for (int index = 1; index <= n; ++index)
		{
			cout << cache[count][index + 1][0] << "," << cache[count][index + 1][1] << ' ';
		}
		cout << endl;
	}*/

	cout << answer;
}