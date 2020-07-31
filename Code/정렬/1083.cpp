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
		//끝까지 정렬이 된 상태라면 (더이상 바꿀게 존재하지 않는다면)
		if (start_index == number.size() - 1)
			break;

		//스왑 횟수가 없어지면
		if (swap_count <= 0)
			break;

		//바꿀 위치(앞부분)을 구합니다.
		auto start_iter = number.begin() + start_index;

		//이 값과 바뀔수 있는 가장 먼거리와의 격차를 구합니다.
		int size = number.end() - start_iter - 1;
		size = min(size, swap_count);

		//그 사이즈 안에서의 가장 높은 값을 구합니다.
		auto max_num_iter = max_element(start_iter, start_iter + size + 1);

		//가장 높은 값과 처음 값의 위치 차를 구해서 swap_count를 감소시킵니다.
		swap_count -= (max_num_iter - start_iter);

		//그후 그 사이의 값들을 순서대로 swap 합니다.
		while (max_num_iter != start_iter)
		{
			swap(*max_num_iter, *(max_num_iter - 1));
			max_num_iter--;
		}

		start_index++;
	}

	//벡터를 출력합니다.
	for (auto index : number)
	{
		cout << index << ' ';
	}
	
}