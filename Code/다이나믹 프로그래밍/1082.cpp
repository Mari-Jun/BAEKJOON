#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <string>

using namespace std;

string cache[51];

vector<int> InitPrice(int);
string Compare(string, string);
string FindMaxNumber(int, int, vector<int>);

int main()
{
	int number, money;
	cin >> number;
	vector<int> price = InitPrice(number);
	cin >> money;
	
	string result = FindMaxNumber(money, money, price);
	if (result.length() == 0)
	{
		cout << "0";
	}
	else
	{
		cout << result;
	}

	return 0;
}

vector<int> InitPrice(int money)
{
	vector<int> price(money);

	for (auto& index : price)
	{
		cin >> index;
	}

	return price;
}

string Compare(string str1, string str2)
{
	if (str1.length() == str2.length())
	{
		return max(str1, str2);
	}
	else
	{
		return (str1.length() > str2.length()) ? str1 : str2;
	}
}

string FindMaxNumber(int money, int max_money, vector<int> price)
{
	string& ret = cache[money];

	if (ret.length() != 0)
	{
		return ret;
	}
	
	for (auto index = (money == max_money) ? 1 : 0; index < price.size(); index++)
	{
		//�� ���ڸ� �����ص� ���� ���� ���
		if (money - price[index] >= 0)
		{
			//�ƹ��͵� ����Ǿ����� ���� ���
			if (ret.length() == 0)
			{
				ret = to_string(index) + FindMaxNumber(money - price[index], max_money, price);
			}
			//����Ǿ� �ִ� ������ ��� �񱳸� �ؼ� �� ū���� �������ش�.
			else
			{
				ret = Compare(ret, to_string(index) + FindMaxNumber(money - price[index], max_money, price));
			}
		}
	}

	return ret;
}