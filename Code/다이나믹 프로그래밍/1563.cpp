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

	//���� 2���� ���
	if (late_time == 2)
		return 0;

	//���� 3�� �Ἦ�� ���
	if (absence_time == 3)
		return 0;

	//���ٻ� �޼�!
	if (cur_day == last_day - 1)
		return 1;

	//cur_day�� 1�� �����ִ� ������ 0�������� �����ϱ� �����̴�.
	int& ret = cache[cur_day + 1][status][late_time][absence_time];

	if (ret != -1)
		return ret;

	ret = 0;

	//�������� �⼮�� �ؾ���
	ret += FindAward(cur_day + 1, last_day, 0, late_time, 0);
	ret %= 1000000;
	//�������� ������ �ؾ���
	ret += FindAward(cur_day + 1, last_day, 1, late_time + 1, 0);
	ret %= 1000000;
	//�������� �Ἦ�� �ؾ���
	ret += FindAward(cur_day + 1, last_day, 2, late_time, absence_time + 1);
	ret %= 1000000;

	return ret;
}