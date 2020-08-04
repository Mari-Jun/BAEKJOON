#include <iostream>

using namespace std;

//주기는 피사노 주기에 의하여 15x(10의 6-1승) = 1,500,000

int fibo[1500010];

int main()
{
	fibo[1] = fibo[2] = 1;

	for (int index = 3; index <= 1500000; index++)
	{
		fibo[index] = fibo[index - 1] + fibo[index - 2];
		fibo[index] %= 1000000;
	}

	long long n;
	cin >> n;

	cout << fibo[n % 1500000];
}