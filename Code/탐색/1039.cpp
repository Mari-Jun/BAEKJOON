#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int FindResult(string&, const string&, int);
string FindMax(string, const string&, int, int);

int main()
{
	string number, max_number;
	int swap_count;
	cin >> number >> swap_count;

	max_number = number;
	sort(max_number.begin(), max_number.end(), greater<>());

	cout << FindResult(number, max_number, swap_count);
	return 0;
}


int FindResult(string& number, const string& max_number, int count)
{
	//못바꾸는 경우 1자리수, 2자리수인데 뒷자리가 0인경우
	if (number.length() == 1)
		return -1;
	if (number.length() == 2 && number[number.length() - 1] == '0')
		return -1;

	return stoi(FindMax(number, max_number, 0, count));
}

string FindMax(string number, const string& max_number, int index, int count)
{
	//모든 교환을 소진한 경우에는
	if (count == 0)
	{
		return number;
	}

	//현재 값이 최대 값인지 검사합니다.
	if (number == max_number)
	{
		//남은 교환 횟수가 짝수인경우
		if (count % 2 == 0)
		{
			return number;
		}
		//교환 회수가 홀수인 경우
		else
		{
			//연속하는 두수를 교환한 값중에 가장 큰값을 반환합니다.
			string max_string;
			
			for (auto iter = number.begin(); iter != number.cend() - 1; iter++)
			{
				swap(*iter, *(iter + 1));
				max_string = max(max_string, number);
				swap(*iter, *(iter + 1));
			}
			
			return max_string;
		}
	}

	//number에서(index 다음의 값) 가장 큰 값을 찾습니다.
	auto max_num = max_element(number.begin() + index + 1, number.end());

	string max_string;

	//값이 작다면
	if (number[index] < *max_num)
	{
		//이 값부터 끝까지 같은 숫자가 있는지 확인을 합니다.
		for (int plus = 0; max_num + plus != number.end(); plus++)
		{
			if (*max_num == *(max_num + plus))
			{
				//있다면 swap한 값을 재귀호출로 넘겨줍니다.
				swap(number[index], *(max_num + plus));
				max_string = max(max_string, FindMax(number, max_number, index + 1, count - 1));
				swap(number[index], *(max_num + plus));
			}
		}
	}
	//값이 크거나 같다면 다음 index로 넘어갑니다.
	else
	{
		max_string = max(max_string, FindMax(number, max_number, index + 1, count));
	}
	return max_string;
}