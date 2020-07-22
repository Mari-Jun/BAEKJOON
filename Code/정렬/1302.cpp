#include <iostream>
#include <set>

using namespace std;

multiset<string> Book;
set<string> Name;

void Input(string BN);
string FindMax();

int main() {
	int N;
	cin >> N;

	string BookName;
	while (N--) {
		cin >> BookName;
		Input(BookName);
	}

	cout << FindMax();
}

void Input(string BN) {
	Book.insert(BN);
	Name.insert(BN);
}

string FindMax() {
	//�̸��� ���ؼ� Book�� ������ ����Ѵ�.

	int Max = 0;

	string Answer;

	for (set<string>::iterator iter = Name.begin(); iter != Name.end(); iter++) {
		int N = Book.count(*iter);
		if (Max < N) {
			Max = N;
			Answer = *iter;
		}
	}

	return Answer;
}