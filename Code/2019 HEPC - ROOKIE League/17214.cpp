#include <iostream>
#include <string>

using namespace std;

string str;

void Solve();

int main() {

	cin >> str;

	Solve();

	return 0;
}

void Solve() {
	int Num1 = 0, Num2 = 0;

	bool Pass = false;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'x') {
			Pass = true;
			Num1 = stoi(str.substr(0, i));
			if (i == str.length() - 1)
				break;
			Num2 = stoi(str.substr(i + 1));
			break;
		}
	}


	if (!Pass) {
		Num2 = stoi(str);
	}


	Num1 /= 2;



	if (Num2 < 0) {
		if (Num1 == 0) {
			if (Num2 == -1)
				cout << "-x+W";
			else
				cout << Num2 << "x+W";
		}
		else if (abs(Num1) != 1) {
			if (Num2 == -1)
				cout << Num1 << "xx" << "-x+W";
			else
				cout << Num1 << "xx" << Num2 << "x+W";
		}
		else if (Num1 == 1) {
			if (Num2 == -1)
				cout << "xx" << "-x+W";
			else
				cout << "xx" << Num2 << "x+W";
		}
		else {
			if (Num2 == -1)
				cout << "-xx" << "-x+W";
			else
				cout << "-xx" << Num2 << "x+W";
		}
	}
	else if (Num2 == 0) {
		if (Num1 == 0)
			cout << "W";
		else if (abs(Num1) != 1)
			cout << Num1 << "xx+W";
		else if (Num1 == 1) 
			cout << "xx+W";
		else
			cout << "-xx+W";
	}
	else {
		if (Num1 == 0) {
			if (Num2 == 1)
				cout << "x+W";
			else
				cout << Num2 << "x+W";
		}
		else if (abs(Num1) != 1) {
			if (Num2 == 1)
				cout << Num1 << "xx+" << "x+W";
			else
				cout << Num1 << "xx+" << Num2 << "x+W";
		}
		else if (Num1 == 1) {
			if (Num2 == 1)
				cout << "xx+" << "x+W";
			else
				cout << "xx+" << Num2 << "x+W";
		}
		else {
			if (Num2 == 1)
				cout << "-xx+" << "x+W";
			else
				cout << "-xx+" << Num2 << "x+W";
		}
	}
	
	

}
