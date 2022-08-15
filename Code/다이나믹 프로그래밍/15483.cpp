#include <iostream>
#include <array>
#include <limits>

using namespace std;

string text1, text2;
array<array<int, 1001>, 1001> map;

int main()
{
	cin >> text1 >> text2;
	
	for (auto& line : map)
		line.fill(numeric_limits<int>::max());
	
	map[0][0] = 0;

	for (size_t y = 0; y <= text1.size(); ++y)
	{
		for (size_t x = 0; x <= text2.size(); ++x)
		{
			if (y > 0 && x > 0)
			{
				if (text1[y - 1] == text2[x - 1])
				{
					map[y][x] = min(map[y][x], map[y - 1][x - 1]);
				}
				else
				{
					map[y][x] = min(map[y][x], map[y - 1][x - 1] + 1);
				}
			}

			if (y > 0)
			{
				map[y][x] = min(map[y][x], map[y - 1][x] + 1);
			}

			if (x > 0)
			{
				map[y][x] = min(map[y][x], map[y][x - 1] + 1);
			}
		}
	}

	cout << map[text1.size()][text2.size()];
}