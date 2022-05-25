#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

std::string GetText(std::string& text)
{
	std::string ret;
	std::deque<string> alphabet;
	std::deque<string> expression;

	bool escape = false;
	bool create_new = false;
	while (escape == false && text.empty() == false)
	{
		char t = text.back();
		text.pop_back();
		switch (t)
		{
		case '+':
		case '-':
			expression.push_back(string(1, t));
			break;
		case '*':
		case '/':
			create_new = true;
			expression.push_back(string(1, t));
			break;
		case '(':
			if (create_new)
			{
				string new_text = alphabet.back() + GetText(text) + expression.back();
				alphabet.pop_back();
				expression.pop_back();
				alphabet.push_back(new_text);
				create_new = false;
			}
			else
			{
				alphabet.push_back(GetText(text));
			}
			break;
		case ')':
			escape = true;
			break;
		default:
			if (create_new)
			{
				string new_text = alphabet.back() + string(1, t) + expression.back();
				alphabet.pop_back();
				expression.pop_back();
				alphabet.push_back(new_text);
				create_new = false;
			}
			else
			{
				alphabet.push_back(string(1, t));
			}
			break;
		}

	
	}

	ret = alphabet.front();
	alphabet.pop_front();

	while (expression.empty() == false)
	{
		ret += alphabet.front() + expression.front();
		alphabet.pop_front();
		expression.pop_front();
	}

	return ret;
}

int main()
{
	std::string text;
	cin >> text;

	reverse(text.begin(), text.end());

	cout << GetText(text);
}