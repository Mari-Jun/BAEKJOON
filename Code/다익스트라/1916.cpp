#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

struct City {
	int Start;
	int Cost;
};

int N, M, S, E;
vector<vector<pair<int, int>>> v(1000, vector<pair<int, int>>());
int Cost[1000];
priority_queue<City> q;

bool operator<(City A, City B) {
	return A.Cost > B.Cost;
}

void Setting();
void Dij();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Setting();
	while (!q.empty()) 
		Dij();	
	cout << Cost[E - 1];
	return 0;
}

void Setting() {
	cin >> N >> M;

	while (M--) {
		int Start, End, Money;
		cin >> Start >> End >> Money;
		v[Start - 1].push_back(make_pair(End - 1, Money));
	}

	cin >> S >> E;

	for (int i = 0; i < N; i++)
		Cost[i] = INT_MAX;

	Cost[S - 1] = 0;

	q.push({ S - 1,Cost[S - 1] });
}

void Dij() {
	City ret = q.top();
	q.pop();

	for (int i = 0; i < v[ret.Start].size(); i++) {
		Cost[v[ret.Start][i].first] = min(ret.Cost + v[ret.Start][i].second, Cost[v[ret.Start][i].first]);
		if (Cost[v[ret.Start][i].first] == ret.Cost + v[ret.Start][i].second) {
			q.push({ v[ret.Start][i].first,Cost[v[ret.Start][i].first] });
		}
	}
}