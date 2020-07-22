#include <iostream>
#include <stack>

using namespace std;

int T;
string S;
stack<char> st;

bool Solve(stack<char>& st);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		stack<char> st;
		cin >> S;
		if (Solve(st))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}

bool Solve(stack<char>& st) {
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(')
			st.push(S[i]);
		else {
			if (st.empty())
				return false;
			if (st.top() == '(')
				st.pop();
		}
	}
	if (st.empty())
		return true;
	return false;
}