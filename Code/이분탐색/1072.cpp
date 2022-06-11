#include <iostream>

using namespace std;

long long x, y, rate;

long long FindGame(long long start, long long end)
{
	if (start >= end)
		return start;

	long long mid = (start + end) / 2;
	long long new_rate = static_cast<long long>(static_cast<long double>(y + mid) * 100 / static_cast<long double>(x + mid));

	if (new_rate == rate)
		return FindGame(mid + 1, end);
	else
		return FindGame(start, mid);
}

int main()
{
	cin >> x >> y;

	rate = static_cast<long long>(static_cast<long double>(y) / static_cast<long double>(x) * 100);

	if (rate < 99)
		cout << FindGame(1, x);
	else
		cout << -1;
}