#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string OctalToBinary(long long);
long long BinaryToOctal(string);
string FindResult(string, string);

int main()
{
	long long x, k;
	cin >> x >> k;

	string binary_to_x = OctalToBinary(x);
	string binary_to_k = OctalToBinary(k);
	cout << BinaryToOctal(FindResult(binary_to_x, binary_to_k)) - x;

	return 0;
}

string OctalToBinary(long long number)
{
	string binary;

	while (number != 0)
	{
		binary = to_string(number % 2) + binary;
		number /= 2;
	}
	return binary;
}

long long BinaryToOctal(string number)
{
	long long sum = 0;
	for (int index = number.length() - 1; index >= 0; index--)
	{
		if (number[index] == '1')
		{
			int count = number.length() - index - 1;
			long long plus = 1;
			while (count != 0)
			{
				plus *= 2;
				count--;
			}
			sum += plus;
		}
		
	}
	return sum;
}

string FindResult(string x, string k)
{
	string result;

	int k_index = k.length() - 1;

	for (int x_index = x.length() - 1; x_index >= 0; x_index--)
	{
		//원본이 0이면
		if (x[x_index] == '0')
		{
			if (k_index >= 0)
			{
				result = k[k_index--] + result;
			}
			else
			{
				result = x[x_index] + result;
			}
		}
		//원본이 1이면
		else
		{
			result = x[x_index] + result;
		}
	}

	while (k_index >= 0)
	{
		result = k[k_index--] + result;
	}

	return result;

}