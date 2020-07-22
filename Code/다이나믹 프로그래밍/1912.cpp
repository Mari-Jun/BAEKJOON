#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, Max = INT_MIN;
int Cache[100001], Num[100000];

void Input();
int DP(int Start);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Input();
	for (int i = 0; i < N; i++)
		Max = max(Max, DP(i));
	cout << Max;
	return 0;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Num[i];
		Cache[i] = INT_MIN;
	}
}

int DP(int Start) {
	int& ret = Cache[Start];
	if (Start == N-1)
		return Num[Start];
	if (ret != INT_MIN)
		return ret;
	ret = Num[Start];
	ret = max(ret, DP(Start+1) + ret);
	return ret;
}