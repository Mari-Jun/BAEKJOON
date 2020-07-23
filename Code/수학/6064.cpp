#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a, int b);
int LCM(int a, int b);
int FindYear(int m, int n, int x, int y, int lcm);

int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		if (m < n)
			cout << FindYear(m, n, x, y, LCM(m, n)) << '\n';
		else
			cout << FindYear(n, m, y, x, LCM(m, n)) << '\n';
	}

	return 0;
}

int GCD(int a, int b)
{
	while (b != 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int LCM(int a, int b)
{
	return a * b / GCD(max(a, b), min(a, b));
}

int FindYear(int m, int n, int x, int y, int lcm)
{
	for (auto i = 0; i * m <= lcm; i++)
	{
		if ((m * i + x) % n == y || ((m * i + x) % n == 0 && (m * i + x - y) % n == 0))
			return m * i + x;
	}
	return -1;
}