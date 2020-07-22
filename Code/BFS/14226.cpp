#include <iostream>
#include <queue>

using namespace std;

int S;
bool Visit[1001][1001];
queue<pair<int,int>> q;

int Solve();
void BFS(int Num, int Copy);

int main() {
	cin >> S;
	cout << Solve();
	return 0;
}

int Solve() {

	//처음 이모티콘 1개가 기본으로 있으므로
	Visit[1][0] = true;

	//make_pair(이모티콘 개수, 클립보드에 복사된 이모티콘 수)
	q.push(make_pair(1, 0));

	int Time = 0, Size = 0;

	while (!q.empty()) {

		//현재 queue의 사이즈를 저장한다.
		Size = q.size();

		//각 시간마다의 경우의 수를 모두 계산한다.
		while (Size--) {
			BFS(q.front().first, q.front().second);

			//만약 원하는 이모티콘만큼 생성했다면
			if (q.empty())
				break;

			q.pop();
		}
		if (q.empty())
			break;

		//한 Size만큼을 Roop할때마다 시간이 1초씩 증가합니다.
		Time++;
	}

	//최소 시간을 반환한다.
	return Time;
}

void BFS(int Num, int Copy) {
	if (Num == S) {
		//가장 빨리 도달한 경우
		while (!q.empty())
			q.pop();
		return;
	}

	if (Num == 1) {
		//처음할수 있는 연산은 1번 복사밖에 없으므로
		if (Copy == 0) {
			q.push(make_pair(Num, Num));
		}
		//두번째로 할수 있는 연산은 2번 붙여넣기 입니다.
		else {
			q.push(make_pair(Num + Copy, Copy));
			//2개의 이모티콘은 생성한적이 있으므로 방문을 체크한다.
			Visit[Num + Copy][Copy] = true;
		}
	}
	else {
		//1번 연산을 실행한다.
		q.push(make_pair(Num, Num));

		//2번 연산을 실행한다.
		if (Num + Copy < 1001 && !Visit[Num + Copy][Copy]) {
			//아직 방문한 적이 없다면 //붙여넣기를 실행합니다.
			q.push(make_pair(Num + Copy, Copy));
			Visit[Num + Copy][Copy] = true;
		}

		//3번 연산을 실행한다.
		if (Num > 1 && !Visit[Num - 1][Copy]) {
			//아직 방문한 적이 없다면 이모티콘 1개를 삭제합니다.
			q.push(make_pair(Num - 1, Copy));
			Visit[Num - 1][Copy] = true;
		}
		
	}
}