#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> InputNumber(int);
void SwapNumber(vector<int>, int);

int main()
{
	int num;
	cin >> num;

	auto number = InputNumber(num);

	int swap_count;
	cin >> swap_count;

	SwapNumber(number, swap_count);
	
	return 0;
}

vector<int> InputNumber(int num)
{
	vector<int> number(num);
	for (auto& index : number)
	{
		cin >> index;
	}
	return number;
}

void SwapNumber(vector<int> number, int swap_count)
{
	int start_index = 0;

	while (1)
	{
		//������ ������ �� ���¶�� (���̻� �ٲܰ� �������� �ʴ´ٸ�)
		if (start_index == number.size() - 1)
			break;

		//���� Ƚ���� ��������
		if (swap_count <= 0)
			break;

		//�ٲ� ��ġ(�պκ�)�� ���մϴ�.
		auto start_iter = number.begin() + start_index;

		//�� ���� �ٲ�� �ִ� ���� �հŸ����� ������ ���մϴ�.
		int size = number.end() - start_iter - 1;
		size = min(size, swap_count);

		//�� ������ �ȿ����� ���� ���� ���� ���մϴ�.
		auto max_num_iter = max_element(start_iter, start_iter + size + 1);

		//���� ���� ���� ó�� ���� ��ġ ���� ���ؼ� swap_count�� ���ҽ�ŵ�ϴ�.
		swap_count -= (max_num_iter - start_iter);

		//���� �� ������ ������ ������� swap �մϴ�.
		while (max_num_iter != start_iter)
		{
			swap(*max_num_iter, *(max_num_iter - 1));
			max_num_iter--;
		}

		start_index++;
	}

	//���͸� ����մϴ�.
	for (auto index : number)
	{
		cout << index << ' ';
	}
	
}