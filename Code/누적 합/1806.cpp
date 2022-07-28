#include <iostream>
#include <array>
#include <limits>

using namespace std;

array<int, 100'000> g_nums;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, s;
	cin >> n >> s;

	int start_index = 0, sum = 0, min_length = numeric_limits<int>::max();
	for (int index = 0; index < n; ++index)
	{
		cin >> g_nums[index];
		sum += g_nums[index];

		if (sum >= s)
		{
			min_length = min(min_length, index - start_index + 1);
			//cout << "[" << start_index << " - " << index << "]" << endl;

			while (sum > s)
			{
				sum -= g_nums[start_index++];
				if (sum >= s)
					min_length = min(min_length, index - start_index + 1);
			}
		}
	}
	
	if (min_length == numeric_limits<int>::max())
		min_length = 0;
	cout << min_length;
}