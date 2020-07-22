#include <iostream>
#include <set>

using namespace std;

int N;
multiset<pair<int, int>> s;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	while (N--) {
		int X, Y;
		cin >> X >> Y;
		s.insert(make_pair(X, Y));
	}
	for (multiset<pair<int, int>>::iterator iter = s.begin(); iter != s.end(); iter++)
		cout << iter->first << ' ' << iter->second << '\n';
}