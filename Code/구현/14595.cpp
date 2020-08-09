#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector<int> wall_break(1000000, 0);

	while (m--)
	{
		int start, end;
		cin >> start >> end;
		
		//ex : wall_break[0] = 9 -> 1번 방부터 10번 방까지가 연결되어있다. 
		//중복을 제거하기 위해 가장 크게 벽을 부수는 경우를 선택한다.
		wall_break[start - 1] = max(wall_break[start - 1], end - 1);
	}

	int room = 0;
	bool breaking = false;
	int last_wall = 0;
	for (int index = 0; index < n; index++)
	{
		//현재 부수는 중이라면
		if (breaking)
		{
			if (index == last_wall)
			{
				//이 벽에서 부술 벽은 없다면
				if (wall_break[index] == 0)
				{
					room++;
					breaking = false;
				}
				//부술 벽이 더 있다면
				else
				{
					//마지막 벽을 최신화 시켜준다.
					last_wall = max(last_wall, wall_break[index]);
				}
			}
			//현재 index가 마지막 벽이 아니라면
			else
			{
				//마지막 벽을 저장한 값이 있다면
				if (wall_break[index] != 0)
				{
					//마지막 벽을 최신화 시켜준다.
					last_wall = max(last_wall, wall_break[index]);
				}
			}
		}
		//부수는 중이 아니라면
		else
		{
			//현재 위치에서 부술 벽이 존재하지 않다면
			if (wall_break[index] == 0)
			{
				room++;
			}
			//부술 벽이 존재한다면
			else
			{
				breaking = true;
				//마지막 벽을 최신화 시켜준다.
				last_wall = max(last_wall, wall_break[index]);
			}
		}
	}

	cout << room;


	return 0;
}