#include <iostream>
#include <stack>

using namespace std;

stack<char> Convert(int m, int n);
void ShowResult(stack<char> result);

int main() {

	int m, n;
	cin >> m >> n;

	stack<char> result = Convert(m, n);
	ShowResult(result);

	return 0;
}

stack<char> Convert(int m, int n) {
	stack<char> result;

	if (m == 0)
		result.push('0');
	else
		while (m != 0) {
			int k = m % n;
			m /= n;

			if (k < 10)
				result.push(k + '0');
			else
				result.push('A' + k - 10);
		}
	
	return result;
}

void ShowResult(stack<char> result) {
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}
}