#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct TeleInfo
{
	map<char, TeleInfo> child_info;
	bool is_prefix = false;
};

bool IsPrefix(TeleInfo& info, string& num, size_t index)
{
	if (info.is_prefix)
		return true;

	if (index == num.size())
	{
		info.is_prefix = true;
		return !info.child_info.empty();
	}

	return IsPrefix(info.child_info[num[index]], num, index + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		TeleInfo info;

		bool is_prefix = false;

		while (n--)
		{
			string num;
			cin >> num;

			if (is_prefix == false)
				is_prefix = IsPrefix(info, num, 0);
		}

		if (is_prefix)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}