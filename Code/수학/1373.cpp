#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str2, str8;
	cin >> str2;

	int Num = 0;
	for (int i = str2.length() - 1; i >= 0; i--) {

		Num += (str2[i] - '0') * (1 << ((str2.length() - 1 - i) % 3));

		if ((str2.length() - 1 - i) % 3 == 2 || i == 0) {
			str8 += Num + '0';
			Num = 0;
		}
	}

	reverse(str8.begin(),str8.end());

	cout << str8;
	
	return 0;
}