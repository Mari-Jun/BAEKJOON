#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	set<string> text_set;

	while (n--)
	{
		string text;
		cin >> text;
		text_set.emplace(std::move(text));
	}

	n = 0;

	while (m--)
	{
		string text;
		cin >> text;
		if (text_set.find(text) != text_set.end())
			++n;
	}

	cout << n;
}