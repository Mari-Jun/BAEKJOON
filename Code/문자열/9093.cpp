#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	cin.ignore();
	while (T--) {
		string str, Answer;
		getline(cin, str);

		int Start = 0;
		for (int i = 0; i < str.length(); i++)
			if (str[i] == ' ') {
				reverse(str.begin() + Start, str.begin() + i);
				Start = i + 1;
			}

		reverse(str.begin() + Start, str.end());

		cout << str << '\n';
	}
}