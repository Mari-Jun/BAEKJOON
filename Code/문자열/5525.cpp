#include <iostream>
#include <string>

using namespace std;

int main()
{
	int number, length;
	cin >> number >> length;

	string str;
	cin >> str;

	int count = 0, sum = 0;
	for (auto index = 0; index < length; index++)
	{
		if (str[index] == 'I')
		{
			for (auto oi = index + 1; oi < length; oi += 2)
			{
				//다음 2개 문자가 OI가 아니라면
				if (oi + 1 == length || str[oi] != 'O' || str[oi + 1] != 'I')
				{
					if (count - number >= 0)
						sum += count - number + 1;
					count = 0;
					index = oi - 1;
					break;
				}
				//2개 문자가 OI이라면
				count++;

				//마지막 문자라면
				if (oi + 2 == length)
				{
					if (count - number >= 0)
						sum += count - number + 1;
					count = 0;
					index = oi + 2;
					break;
				}
			}

		}
	}
	if (count - number >= 0)
		sum += count - number + 1;
	cout << sum;

	return 0;
}