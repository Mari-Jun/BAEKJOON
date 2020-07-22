#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;
void Input(string& str);
void Solve(string& str);

int main() {

	string str;

	Input(str);
	Solve(str);

	return 0;
}

void Input(string& str) {
	//str을 입력받는다.
	getline(cin, str);
}

void Solve(string& str) {
	int Start = 0, End = 0;
	int Sum = 0;
	bool Minus = false;

	while (End <= str.length()) {

		if (str[End] == '+' || str[End] == '-' || End == str.length()) {
			if (!Minus)
				q.push(stoi(str.substr(Start, End - Start)));
			else
				q.push((-1) * stoi(str.substr(Start, End - Start)));

			Start = End + 1;

			if (str[End] == '-')
				Minus = true;
		}
		End++;
	}

	while (!q.empty()) {
		Sum += q.front();
		q.pop();
	}
	
	cout << Sum << endl;
}