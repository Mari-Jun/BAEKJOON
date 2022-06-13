#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long k, c;
	cin >> k >> c;

	long double pow_c = powf(10, c);

	cout << static_cast<long long>(roundf(static_cast<long double>(k) / pow_c) * pow_c);

}