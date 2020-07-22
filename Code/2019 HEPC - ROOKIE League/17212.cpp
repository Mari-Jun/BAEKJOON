#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int Coin[4] = { 1,2,5,7 };
int N;
int Cache[1010];


int Solve(int Count, int HP);

int main() {

	memset(Cache, -1, sizeof(Cache));
	cin >> N;

	int Sum = 0;

	if (N >= 1000) {
		Sum += (N - 1000) / 7;
		N = 1000 + (N - 1000) % 7;
	}

	cout << Sum + Solve(0, N);


	return 0;
}

int Solve(int Count, int HP) {
	
	if (HP == 0) 
		return 0;

		
	int& ret = Cache[HP];

	if (ret != -1)
		return ret;

	ret = 1500;

	for (int i = 3; i >= 0; i--) {
		if (HP - Coin[i] >= 0)
			ret = min(ret, 1 + Solve(Count + 1, HP - Coin[i]));
	}

	return ret;
}