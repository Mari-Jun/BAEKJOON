#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

long long GCD(long long, long long);
long long LCM(long long, long long);

int main()
{
	long long gcd, lcm;
	cin >> gcd >> lcm;

	long long mul_num = gcd * lcm;
	long long div_num = lcm / gcd;

	long long a, b;
	int count = 1;
	
	long long min_num = INT_MAX;
	pair<long long, long long> result = make_pair(0, 0);

	while (1)
	{
		a = gcd * count;
		b = mul_num / a;

		if (a > b)
			break;

		if (GCD(b, a) == gcd && LCM(b, a) == lcm)
		{
			if (min_num > a + b)
			{
				min_num = a + b;
				result.first = a;
				result.second = b;
			}
		}
		
		count++;
	}

	cout << result.first << ' ' << result.second;
	
	return 0;
}


long long GCD(long long a, long long b)
{
	while (b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}
long long LCM(long long a, long long b)
{
	return a * b / GCD(a, b);
}