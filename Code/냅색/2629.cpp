#include <iostream>
#include <array>

using namespace std;

int cube_count, sphere_count;
array<int, 31> cube_weight;
array<int, 7> sphere_weight;

array<array<bool, 15001>, 31> cache;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int cube_sum = 0;

	cin >> cube_count;
	for (int i = 1; i <= cube_count; ++i)
	{
		cin >> cube_weight[i];
		cube_sum += cube_weight[i];
	}
	cin >> sphere_count;
	for (int i = 1; i <= sphere_count; ++i)
		cin >> sphere_weight[i];

	cache[0][0] = true;
	
	for (int cube = 1; cube <= cube_count; ++cube)
	{
		for (int w = 0; w <= cube_sum; ++w)
		{
			if (cache[cube - 1][w])
			{
				cache[cube][w] = true;
				cache[cube][w + cube_weight[cube]] = true;
				cache[cube][abs(cube_weight[cube] - w)] = true;
			}
		}
	}

	for (int sphere = 1; sphere <= sphere_count; ++sphere)
	{
		if (sphere_weight[sphere] <= cube_sum && cache[cube_count][sphere_weight[sphere]])
			cout << "Y ";
		else
			cout << "N ";
	}
}
