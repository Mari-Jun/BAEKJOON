#include <iostream>
#include <array>

using namespace std;

array<array<int, 1025>, 1025> map;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int y = 1; y <= n; ++y)
		for (int x = 1; x <= n; ++x)
			cin >> map[y][x];
		
	for (int y = 1; y <= n; ++y)
		for (int x = 1; x <= n; ++x)
			map[y][x] += map[y][x - 1];

	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= n; ++y)
			map[y][x] += map[y - 1][x];

	int y1, x1, y2, x2;
	for (int i = 0; i < m; ++i)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		cout << map[y2][x2] - map[y2][x1 - 1] - map[y1 - 1][x2] + map[y1 - 1][x1 - 1] << '\n';
	}
}