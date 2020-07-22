#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str8, str2;
	cin >> str8;



	for (int i = 0; i < str8.length(); i++) {

		//처음일 경우
		int Num = str8[i] - '0';
		if (i == 0) {
			if (Num / 4 == 1)
				str2 += '1';
			Num %= 4;
			if (Num / 2 == 1)
				str2 += '1';
			else
				if (!str2.empty())
					str2 += '0';
			Num %= 2;
			if (Num == 1)
				str2 += '1';
			else
				str2 += '0';
		}

		//다음 글자일 경우
		if (i != 0) {
			str2 += (Num / 4) + '0';
			Num %= 4;
			str2 += (Num / 2) + '0';
			Num %= 2;
			str2 += Num + '0';
		}
	}
	cout << str2;

	return 0;
}