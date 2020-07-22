#include <iostream>
#include <memory.h>

using namespace std;

int cache[42][2];

void InitCache();
pair<int, int> Fibonacci(int number);

int main()
{
	int test_case;
	cin >> test_case;

	InitCache();

	while (test_case--)
	{
		int number;
		cin >> number;
		pair<int, int> result = Fibonacci(number);
		cout << result.first << ' ' << result.second << '\n';
	}
}

void InitCache()
{
	memset(cache, -1, sizeof(cache));
}

pair<int,int> Fibonacci(int number)
{

	if (number == 0)
		return make_pair(1, 0);
	else if (number == 1)
		return make_pair(0, 1);
	else
	{
		int& zero = cache[number][0];
		int& one = cache[number][1];

		if (zero != -1 && one != -1)
			return make_pair(zero, one);

		zero = one = 0;

		pair<int, int> ret1 = Fibonacci(number - 1);
		pair<int, int> ret2 = Fibonacci(number - 2);
		
		zero = ret1.first + ret2.first;
		one = ret1.second + ret2.second;

		return make_pair(zero, one);
	}
}