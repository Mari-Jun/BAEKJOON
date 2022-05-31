#include <iostream>

using namespace std;

int n, k;

int SearchNum(int start, int end)
{
	if (start > end)
		return start;

	int mid = (start + end) / 2;
	int count = 0;

	for (int i = 1; i <= n; ++i)
		count += n > mid / i ? mid / i : n;

	if (count >= k)
		return SearchNum(start, mid - 1);
	else
		return SearchNum(mid + 1, end);

}

int main()
{
	cin >> n >> k;

	cout << SearchNum(1, k);
}