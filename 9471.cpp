#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int n, m;
		cin >> n >> m;

		int p1 = 1, p2 = 1;
		int cycle = 0;

		do
		{
			int p1_temp = p1;
			p1 = p2;
			p2 = (p1_temp + p2) % m;
			cycle++;
		} while (!(p1 == 1 && p2 == 1));

		cout << n << ' ' << cycle << '\n';
	}

	return 0;
}