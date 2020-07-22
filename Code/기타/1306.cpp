#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> GetLight(int block);
void FindMaxLight(vector<int> light, int range);

int main()
{
	int block, range;
	cin >> block >> range;

	vector<int> light = GetLight(block);
	FindMaxLight(light, range);

	return 0;
}

vector<int> GetLight(int block)
{
	vector<int> light;
	while (block--)
	{
		int number;
		cin >> number;
		light.push_back(number);
	}
	return light;
}

void FindMaxLight(vector<int> light, int range) {
	vector<int>::iterator iter = light.begin() + range - 1;
	int max_light = *max_element(iter + 1 - range, iter + range);

	cout << max_light << ' ';
	iter++;

	for (iter; iter != light.end() - range + 1; iter++)
	{
		if (*(iter - range) == max_light)
		{
			if (*(iter + range - 1) < max_light)
			{
				max_light = *max_element(iter + 1 - range, iter + range - 1);
			}
		}
		max_light = max(max_light, *(iter + range - 1));
		cout << max_light << ' ';
	}
}

