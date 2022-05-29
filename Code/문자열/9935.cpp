#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string text, bomb;
	cin >> text >> bomb;

	stack<char> char_stack;

	for (char c : text)
	{
		char_stack.push(c);
		
		if (c == bomb[bomb.size() - 1])
		{
			stack<char> temp_stack;
			for (int i = 0; i < bomb.size(); ++i)
			{
				if (char_stack.empty())
				{
					while (temp_stack.empty() == false)
					{
						char_stack.push(temp_stack.top());
						temp_stack.pop();
					}
					break;
				}

				char temp_c = char_stack.top();
				if (temp_c == bomb[bomb.size() - 1 - i])
				{
					temp_stack.push(temp_c);
					char_stack.pop();
				}
				else
				{
					while (temp_stack.empty() == false)
					{
						char_stack.push(temp_stack.top());
						temp_stack.pop();
					}
				}
			}
		}
	}

	string ret;

	while (char_stack.empty() == false)
	{
		ret += char_stack.top();
		char_stack.pop();
	}

	reverse(ret.begin(), ret.end());

	if (ret.empty())
		ret = "FRULA";

	cout << ret;
}