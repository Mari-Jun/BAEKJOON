#include <iostream>
#include <string>

using namespace std;

int n;
string ret;

void FindGoodSequence(const string& text, size_t size)
{
	if (size == n)
	{
		ret = min(ret, text);
	}
	else
	{
		for (int num = 1; num <= 3; ++num)
		{
			string new_text = text + to_string(num);

			if (ret.substr(0, size + 1) <= new_text)
				break;

			size_t rev = new_text.size() / 2;
			bool equal = true;
			for (int i = 1; i <= rev; ++i)
			{
				equal = true;
				for (int j = 0; j < i; ++j)
				{
					if (new_text[size - j] != new_text[size - i - j])
					{
						equal = false;
						break;
					}
				}

				if (equal)
					break;
			}

			if (equal == false)
				FindGoodSequence(new_text, size + 1);
		}
	}
}

int main()
{
	cin >> n;
	ret.resize(n, '3');
	FindGoodSequence("1", 1);
	cout << ret;
}