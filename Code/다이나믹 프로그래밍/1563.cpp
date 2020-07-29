#include <iostream>
#include <memory.h>

using namespace std;

int cache[1005][3][2][3];

int FindAward(int cur_day, int last_day, int status, int late_time, int absence_time);

int main()
{
	memset(cache, -1, sizeof(cache));

	int number;
	cin >> number;

	cout << FindAward(-1, number, 0, 0, 0);

	return 0;
}


int FindAward(int cur_day, int last_day, int status, int late_time, int absence_time)
{

	//지각 2번인 경우
	if (late_time == 2)
		return 0;

	//연속 3번 결석인 경우
	if (absence_time == 3)
		return 0;

	//개근상 달성!
	if (cur_day == last_day - 1)
		return 1;

	//cur_day에 1을 더해주는 이유는 0일차부터 시작하기 위함이다.
	int& ret = cache[cur_day + 1][status][late_time][absence_time];

	if (ret != -1)
		return ret;

	ret = 0;

	//다음날은 출석을 해야지
	ret += FindAward(cur_day + 1, last_day, 0, late_time, 0);
	ret %= 1000000;
	//다음날은 지각을 해야지
	ret += FindAward(cur_day + 1, last_day, 1, late_time + 1, 0);
	ret %= 1000000;
	//다음날은 결석을 해야지
	ret += FindAward(cur_day + 1, last_day, 2, late_time, absence_time + 1);
	ret %= 1000000;

	return ret;
}