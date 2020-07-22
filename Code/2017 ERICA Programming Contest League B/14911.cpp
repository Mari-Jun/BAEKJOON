#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

vector<int> SubString(string& str);
set<pair<int, int>> FindNumber(vector<int> number, int sum);
void ShowResult(set<pair<int, int>> result);

int main() {

	string first_line;
	int second_line;

	getline(cin, first_line);
	cin >> second_line;

	vector<int> number = SubString(first_line);

	set<pair<int, int>> find_number = FindNumber(number, second_line);

	ShowResult(find_number);

	return 0;
}

vector<int> SubString(string& str) {
	vector<int> number;
	int start = 0, end = 0;

	//입력받은 문자열을 분리합니다.
	for (end = 0; end < str.length(); end++) {
		if (str[end] == ' ') {
			string ret = str.substr(start, end - start);
			number.push_back(stoi(ret));
			start = end + 1;
		}
	}
	string ret = str.substr(start, end - start);
	number.push_back(stoi(ret));

	sort(number.begin(), number.end());
	return number;
}

set<pair<int, int>> FindNumber(vector<int> number, int sum) {

	set<pair<int, int>> find_number;

	for (auto first = 0; first < number.size() - 1; first++) {
		for (auto second = first + 1; second < number.size(); second++) {
			if (number[first] + number[second] == sum) {
				find_number.insert(make_pair(number[first], number[second]));
			}
		}
	}

	return find_number;
}

void ShowResult(set<pair<int, int>> result) {

	for (set<pair<int, int>>::iterator iter = result.begin(); iter != result.end(); iter++)
		cout << (*iter).first << ' ' << (*iter).second << '\n';

	cout << result.size();
}