#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int N;
	int Max = 0, Sum = 0;

	cin >> N;

	int BNum = 1001, CNum;
	while (N--) {
		cin >> CNum;
		if (BNum < CNum) {
			//오르막인 경우
			Sum += CNum - BNum;
			Max = max(Max, Sum);
		}
		else {
			Sum = 0;
		}
		BNum = CNum;
	}

	cout << Max;

	return 0;
}