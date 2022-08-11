#include <iostream>
#include <array>

using namespace std;

int n;
array<bool, 15> g_y_check;
array<bool, 30> g_left_check;
array<bool, 30> g_right_check;

int FindQueen(int y)
{
	if (y == n) return 1;

	int ret = 0;

	for (int x = 0; x < n; ++x)
	{
		if (g_y_check[x] == false &&
			g_left_check[n + x - y] == false &&
			g_right_check[x + y] == false)
		{
			g_left_check[n + x - y] = true;
			g_right_check[x + y] = true;
			g_y_check[x] = true;
			ret += FindQueen(y + 1);
			g_y_check[x] = false;
			g_left_check[n + x - y] = false;
			g_right_check[x + y] = false;
		}
	}

	return ret;
}

int main()
{
	cin >> n;
	cout << FindQueen(0);
}