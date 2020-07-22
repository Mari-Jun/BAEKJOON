#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int Cache[1001];
vector<int> Score;

void Setting();
int FindMaxGap(int Start);

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Setting();

	cout << FindMaxGap(0);

	return 0;
}

void Setting() {
	cin >> N;

	//N만큼 점수를 입력받는다.
	for (int i = 0; i < N; i++) {
		int Num;
		cin >> Num;
		Score.push_back(Num);
	}

	memset(Cache, -1, sizeof(Cache));
}

int FindMaxGap(int Start) {

	if (Start == N)
		return 0;

	int& ret = Cache[Start];

	if (ret != -1)
		return ret;

	vector<int>::iterator MaxNum;
	vector<int>::iterator MinNum;

	ret = 0;

	for (int End = Start+1; End < N; End++) {

		//Start와 End사이의 최대값과 최소값을 찾아줍니다.
		MaxNum = max_element(Score.begin() + Start, Score.begin() + End + 1);
		MinNum = min_element(Score.begin() + Start, Score.begin() + End + 1);

		//임시값에 그들의 차가 더 크다면 저장한다.
		ret = max(ret, (*MaxNum - *MinNum) + FindMaxGap(End + 1));
	}

	return ret;
}