#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	priority_queue<int> plus_queue;
	priority_queue<int, vector<int>, greater<>> minus_queue;
	queue<int> zero_queue;

	int num;
	while (n--)
	{
		cin >> num;
		if (num > 0) plus_queue.push(num);
		else if (num == 0) zero_queue.push(num);
		else minus_queue.push(num);
	}

	int sum = 0;
	int first, second;

	while (plus_queue.empty() == false)
	{
		first = plus_queue.top();
		plus_queue.pop();
		if (plus_queue.empty())
		{
			sum += first;
			break;
		}
		second = plus_queue.top();
		plus_queue.pop();

		if (first + second < first * second)
			sum += first * second;
		else
			sum += first + second;
	}

	while (minus_queue.empty() == false)
	{
		first = minus_queue.top();
		minus_queue.pop();
		if (minus_queue.empty())
		{
			if (zero_queue.empty())
				sum += first;
			break;
		}
		second = minus_queue.top();
		minus_queue.pop();

		sum += first * second;
	}

	cout << sum;
}