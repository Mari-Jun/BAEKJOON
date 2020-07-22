#include <iostream>
#include <stack>

using namespace std;
stack<pair<int, bool>> Num;
string str;

bool Solve();

int main() {
	cin >> str;
	int Sum = 0;
	if (Solve()) {
		while (!Num.empty()) {
			if (Num.top().second) {
				Sum = 0;
				break;
			}
			Sum += Num.top().first;
			Num.pop();
		}
	}
	cout << Sum;

	return 0;
}

bool Solve() {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			if (i == str.size() - 1)
				return false;
			if (str[i + 1] == ')')
				Num.push(make_pair(2, false));
			else if (str[i + 1] == ']')
				return false;
			else
				Num.push(make_pair(2, true));
		}
		else if (str[i] == '[') {
			if (i == str.size() - 1)
				return false;
			if (str[i + 1] == ']')
				Num.push(make_pair(3, false));
			else if (str[i + 1] == ')')
				return false;
			else
				Num.push(make_pair(3, true));
		}
		else if (str[i] == ')') {
			if (i == 0)
				return false;
			if (str[i - 1] == '(')
				continue;
			int Add = 0;
			while (!Num.empty() && !Num.top().second) {
				Add += Num.top().first;
				Num.pop();
			}
			if (Num.empty())
				return false;
			if (Num.top().first == 3)
				return false;
			Add *= Num.top().first;
			Num.pop();
			Num.push(make_pair(Add, false));
		}
		else {
			if (i == 0)
				return false;
			if (str[i - 1] == '[')
				continue;
			int Add = 0;
			while (!Num.empty() && !Num.top().second) {
				Add += Num.top().first;
				Num.pop();
			}
			if (Num.empty())
				return false;
			if (Num.top().first == 2)
				return false;
			Add *= Num.top().first;
			Num.pop();
			Num.push(make_pair(Add, false));
		}
	}
	return true;
}