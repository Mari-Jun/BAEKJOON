#include <iostream>
#include <set>

using namespace std;

int T, N;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		cin >> N;

		set<pair<int, int>> s;

		while (N--) {
			int X, Y;
			cin >> X >> Y;
			s.insert(make_pair(X, Y));
		}

		int Min = 1000000;
		int Count = 0;

		for (set<pair<int, int>>::iterator iter = s.begin(); iter != s.end(); iter++) {
			if (Min > iter->second) {
				Min = iter->second;
				Count++;
			}
		}

		cout << Count << '\n';
	}

	return 0;
}