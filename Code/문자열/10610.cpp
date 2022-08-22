#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string num;
	cin >> num;

	long long sum = 0;
	for (char c : num)
		sum += c - '0';

	sort(num.begin(), num.end(), [](char a, char b) {return a > b; });

	string result = "-1";
	if (sum % 3 == 0 && num.back() == '0')
	{
		result = num;
	}
	
	cout << result;
}