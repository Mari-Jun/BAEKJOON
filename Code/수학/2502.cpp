#include <iostream>

using namespace std;

int main()
{
	int d, k;
	cin >> d >> k;

	int bx = 0, x = 1;
	int by = 1, y = 1;

	for (int i = 3; i < d; ++i)
	{
		int new_x = x + bx;
		bx = x; x = new_x;
		int new_y = y + by;
		by = y; y = new_y;
	}

	int cnt = k / x;

	for (int i = 1; i <= cnt; ++i)
	{
		if ((k - i * x) % y == 0)
		{
			cout << i << endl;
			cout << (k - i * x) / y;
			break;
		}
	}
}