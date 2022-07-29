#include <iostream>
#include <cmath>
#include <vector>
#include <array>

using namespace std;

vector<int> g_prime_numbers;
array<bool, 4'000'001> g_check_prime_numbers;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 2; i <= sqrt(4'000'000); ++i)
	{
		for (int j = 2; j * i <= 4'000'000; ++j)
			g_check_prime_numbers[i * j] = true;
	}

	int n;
	cin >> n;

	for (int i = 2; i <= n; ++i)
		if (g_check_prime_numbers[i] == false)
			g_prime_numbers.push_back(i);

	int count = 0, sum = 0;
	int start = 0, end = 0;

	for (end; end < g_prime_numbers.size(); ++end)
	{
		sum += g_prime_numbers[end];

		while (sum > n)
			sum -= g_prime_numbers[start++];
		
		if (sum == n)
			++count;
	}

	cout << count;
}
