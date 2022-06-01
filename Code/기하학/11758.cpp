#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<array<int, 2>, 2> directions;
	array<array<int, 2>, 3> positions;

	for (int i = 0; i < 3; ++i)
		cin >> positions[i][0] >> positions[i][1];

	for (int i = 0; i < 2; ++i)
	{
		directions[i][0] = positions[i + 1][0] - positions[i][0];
		directions[i][1] = positions[i + 1][1] - positions[i][1];
	}

	int y = directions[0][1] * directions[1][0] - directions[0][0] * directions[1][1];

	if (y > 0)
		cout << -1;
	else if (y == 0)
		cout << 0;
	else
		cout << 1;
}