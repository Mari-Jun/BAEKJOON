#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);

	for (int& p : v)
		cin >> p;

	int answer = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		if (v[i] > v[i + 1])
			answer = i + 1;
	}

	cout << answer;
}