#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int FindResult(string&, const string&, int);
string FindMax(string, const string&, int, int);

int main()
{
	string number, max_number;
	int swap_count;
	cin >> number >> swap_count;

	max_number = number;
	sort(max_number.begin(), max_number.end(), greater<>());

	cout << FindResult(number, max_number, swap_count);
	return 0;
}


int FindResult(string& number, const string& max_number, int count)
{
	//���ٲٴ� ��� 1�ڸ���, 2�ڸ����ε� ���ڸ��� 0�ΰ��
	if (number.length() == 1)
		return -1;
	if (number.length() == 2 && number[number.length() - 1] == '0')
		return -1;

	return stoi(FindMax(number, max_number, 0, count));
}

string FindMax(string number, const string& max_number, int index, int count)
{
	//��� ��ȯ�� ������ ��쿡��
	if (count == 0)
	{
		return number;
	}

	//���� ���� �ִ� ������ �˻��մϴ�.
	if (number == max_number)
	{
		//���� ��ȯ Ƚ���� ¦���ΰ��
		if (count % 2 == 0)
		{
			return number;
		}
		//��ȯ ȸ���� Ȧ���� ���
		else
		{
			//�����ϴ� �μ��� ��ȯ�� ���߿� ���� ū���� ��ȯ�մϴ�.
			string max_string;
			
			for (auto iter = number.begin(); iter != number.cend() - 1; iter++)
			{
				swap(*iter, *(iter + 1));
				max_string = max(max_string, number);
				swap(*iter, *(iter + 1));
			}
			
			return max_string;
		}
	}

	//number����(index ������ ��) ���� ū ���� ã���ϴ�.
	auto max_num = max_element(number.begin() + index + 1, number.end());

	string max_string;

	//���� �۴ٸ�
	if (number[index] < *max_num)
	{
		//�� ������ ������ ���� ���ڰ� �ִ��� Ȯ���� �մϴ�.
		for (int plus = 0; max_num + plus != number.end(); plus++)
		{
			if (*max_num == *(max_num + plus))
			{
				//�ִٸ� swap�� ���� ���ȣ��� �Ѱ��ݴϴ�.
				swap(number[index], *(max_num + plus));
				max_string = max(max_string, FindMax(number, max_number, index + 1, count - 1));
				swap(number[index], *(max_num + plus));
			}
		}
	}
	//���� ũ�ų� ���ٸ� ���� index�� �Ѿ�ϴ�.
	else
	{
		max_string = max(max_string, FindMax(number, max_number, index + 1, count));
	}
	return max_string;
}