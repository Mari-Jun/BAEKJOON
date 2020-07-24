#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

int cache[20][11];

void InitCache();
string FindNumber(int number);
string Recursion(int number, int length);

int main()
{
	InitCache();

	int number;
	cin >> number;

	cout << FindNumber(number);

}

void InitCache()
{
	memset(cache, 0, sizeof(cache));
	//한자리수는 미리 입력해놓는다.
	for (int number = 0; number < 10; number++)
	{
		cache[0][number] = number + 1;
	}
}

string FindNumber(int number)
{
	if (number < 10)
		return to_string(number);

	int length = 2, cur_number = 10;

	for (length = 2; length <= 10; length++)
	{
		for (int front = length - 1; front < 10; front++)
		{
			if (cache[length - 1][front] == 0)
			{
				if (front == length - 1)
					cache[length - 1][front] = 1;
				else
					cache[length - 1][front] = cache[length - 1][front - 1] + cache[length - 2][front - 1];
			}

			//범위 내에 있는 경우
			if (number >= cur_number && number < cur_number + cache[length - 2][front - 1])
			{
				return to_string(front) + Recursion(number - cur_number + 1, length - 1);
			}
			//범위를 넘어가는 경우
			else
			{
				cur_number += cache[length - 2][front - 1];
			}
			
		}
	}
	return "-1";

}

string Recursion(int number, int length) {

	if (length == 1)
		return to_string(number - 1);

	for (int front = length - 1; front < 10; front++)
	{
		if (number <= cache[length - 1][front])
			return to_string(front) + Recursion(number - cache[length - 1][front - 1], length - 1);
	}
}