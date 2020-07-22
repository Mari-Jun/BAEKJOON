#include <iostream>
#include <memory.h>
using namespace std;

int N;
int Base[10000];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	memset(Base, 0, sizeof(Base));
	cin >> N;
	while (N--) {
		int Num;
		cin >> Num;
		Base[Num - 1]++;
	}
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < Base[i]; j++)
			cout << i + 1 << '\n';
	}
	return 0;
}