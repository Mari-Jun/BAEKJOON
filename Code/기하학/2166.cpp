#include <iostream>
#include <array>
#include <cmath>

using namespace std;

int main()
{
	array<long long, 3> x_pos;
	array<long long, 3> y_pos;

	int n;
	cin >> n;

	for (int i = 0; i < 2; ++i)
		cin >> x_pos[i] >> y_pos[i];

	long double area = 0.0;

	n -= 2;

	while (n--)
	{
		cin >> x_pos[2] >> y_pos[2];

		long long a = 0.0, b = 0.0;
		a = (x_pos[1] - x_pos[0]) * (y_pos[2] - y_pos[0]);
		b = (x_pos[2] - x_pos[0]) * (y_pos[1] - y_pos[0]);

		area += 0.5 * (a - b);

		x_pos[1] = x_pos[2];
		y_pos[1] = y_pos[2];
	}

	cout << fixed;
	cout.precision(1);
	cout << roundl(abs(area) * 10.0) / 10.0;
}