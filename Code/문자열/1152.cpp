#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	int Sum = 0;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		if ((i==0 && str[i] == ' ') || (i==str.size()-1 && str[i] == ' '))
			continue;
		if (str[i] == ' ')
			Sum++;
	}
	if (str[0] == ' ' && str.size() == 1)
		Sum = -1;
	cout << Sum + 1;
	return 0;
}
