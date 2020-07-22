#include <iostream>
#include <stack>

using namespace std;

int Calcul(stack<int>& s);

int main() {
	int N, Num;
	stack<int> s;

	cin >> N;
	while (N--) {
		cin >> Num;
		s.push(Num);
	}
	
	cout << Calcul(s);

	return 0;
}

int Calcul(stack<int>& s) {
	int Sum = 0, Num = 20001;
	while (!s.empty()) {

		if (Num > s.top()) {
			Num = s.top();
		}
		else {
			Sum += (s.top() - Num + 1);
			Num = Num - 1;
		}
		s.pop();
	}
	return Sum;
}