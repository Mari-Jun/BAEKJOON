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
		
		//ex : wall_break[0] = 9 -> 1�� ����� 10�� ������� ����Ǿ��ִ�. 
		//�ߺ��� �����ϱ� ���� ���� ũ�� ���� �μ��� ��츦 �����Ѵ�.
		wall_break[start - 1] = max(wall_break[start - 1], end - 1);
	}

	int room = 0;
	bool breaking = false;
	int last_wall = 0;
	for (int index = 0; index < n; index++)
	{
		//���� �μ��� ���̶��
		if (breaking)
		{
			if (index == last_wall)
			{
				//�� ������ �μ� ���� ���ٸ�
				if (wall_break[index] == 0)
				{
					room++;
					breaking = false;
				}
				//�μ� ���� �� �ִٸ�
				else
				{
					//������ ���� �ֽ�ȭ �����ش�.
					last_wall = max(last_wall, wall_break[index]);
				}
			}
			//���� index�� ������ ���� �ƴ϶��
			else
			{
				//������ ���� ������ ���� �ִٸ�
				if (wall_break[index] != 0)
				{
					//������ ���� �ֽ�ȭ �����ش�.
					last_wall = max(last_wall, wall_break[index]);
				}
			}
		}
		//�μ��� ���� �ƴ϶��
		else
		{
			//���� ��ġ���� �μ� ���� �������� �ʴٸ�
			if (wall_break[index] == 0)
			{
				room++;
			}
			//�μ� ���� �����Ѵٸ�
			else
			{
				breaking = true;
				//������ ���� �ֽ�ȭ �����ش�.
				last_wall = max(last_wall, wall_break[index]);
			}
		}
	}

	cout << room;


	return 0;
}