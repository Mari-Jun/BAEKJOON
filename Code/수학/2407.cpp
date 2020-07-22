#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string Cache[101][101];

int N, M;

void Setting();
string Sum(string A, string B);
string Solve(int n, int m);

int main() {
	Setting();		
	cout << Solve(N, M);
	return 0;
}

void Setting() {
	for (int i = 0; i <= 100; i++)
		Cache[i][0] = Cache[i][i] = "1";

	cin >> N >> M;
}

string Sum(string A, string B) {

	int AL = A.length();
	int BL = B.length();

	//CNum은 올림 자리 표현
	int ANum, BNum, CNum = 0;
	string Sum;

	while (AL != 0 && BL != 0) {

		ANum = A[AL - 1] - '0';
		BNum = B[BL - 1] - '0';

		CNum += ANum + BNum;

		Sum += CNum % 10 + '0';

		CNum /= 10;

		AL--;
		BL--;
	}

	while (AL != 0) {
		//A가 더 길다면
		ANum = A[AL - 1] - '0';

		CNum += ANum;

		Sum += CNum % 10 + '0';

		CNum /= 10;

		AL--;
	}
	while (BL != 0) {
		//B가 더 길다면
		BNum = B[BL - 1] - '0';

		CNum += BNum;

		Sum += CNum % 10 + '0';

		CNum /= 10;

		BL--;
	}

	if (CNum != 0)
		Sum += CNum + '0';

	reverse(Sum.begin(), Sum.end());

	return Sum;
}

string Solve(int n, int m) {

	string& ret = Cache[n][m];

	if (!ret.empty())
		return ret;

	return ret = Sum(Solve(n - 1, m - 1), Solve(n - 1, m));
}