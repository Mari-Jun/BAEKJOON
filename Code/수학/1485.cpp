#include <iostream>

using namespace std;

int T;
long long XPos[4], YPos[4];

void Setting();
bool RectCheck();


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		Setting();
		cout << RectCheck() << '\n';
	}

	return 0;
}

void Setting() {
	for (int i = 0; i < 4; i++) 
		cin >> XPos[i] >> YPos[i];
}

bool RectCheck() {

	if (XPos[0] == XPos[1] && XPos[1] == XPos[2] && XPos[2] == XPos[3])
		return false;
	if (YPos[0] == YPos[1] && YPos[1] == YPos[2] && YPos[2] == YPos[3])
		return false;

	long long a, b, c, d, e, f;

	a = (XPos[0] - XPos[1]) * (XPos[0] - XPos[1]) + (YPos[0] - YPos[1]) * (YPos[0] - YPos[1]);
	b = (XPos[0] - XPos[2]) * (XPos[0] - XPos[2]) + (YPos[0] - YPos[2]) * (YPos[0] - YPos[2]);
	c = (XPos[1] - XPos[3]) * (XPos[1] - XPos[3]) + (YPos[1] - YPos[3]) * (YPos[1] - YPos[3]);
	d = (XPos[2] - XPos[3]) * (XPos[2] - XPos[3]) + (YPos[2] - YPos[3]) * (YPos[2] - YPos[3]);
	e = (XPos[0] - XPos[3]) * (XPos[0] - XPos[3]) + (YPos[0] - YPos[3]) * (YPos[0] - YPos[3]);
	f = (XPos[2] - XPos[1]) * (XPos[2] - XPos[1]) + (YPos[2] - YPos[1]) * (YPos[2] - YPos[1]);


	if (a == b && a == c && a == d && e == f)
		return true;
	
	a = (XPos[0] - XPos[1]) * (XPos[0] - XPos[1]) + (YPos[0] - YPos[1]) * (YPos[0] - YPos[1]);
	b = (XPos[0] - XPos[3]) * (XPos[0] - XPos[3]) + (YPos[0] - YPos[3]) * (YPos[0] - YPos[3]);
	c = (XPos[2] - XPos[3]) * (XPos[2] - XPos[3]) + (YPos[2] - YPos[3]) * (YPos[2] - YPos[3]);
	d = (XPos[2] - XPos[1]) * (XPos[2] - XPos[1]) + (YPos[2] - YPos[1]) * (YPos[2] - YPos[1]);
	e = (XPos[0] - XPos[2]) * (XPos[0] - XPos[2]) + (YPos[0] - YPos[2]) * (YPos[0] - YPos[2]);
	f = (XPos[1] - XPos[3]) * (XPos[1] - XPos[3]) + (YPos[1] - YPos[3]) * (YPos[1] - YPos[3]);


	if (a == b && a == c && a == d && e == f)
		return true;

	a = (XPos[0] - XPos[3]) * (XPos[0] - XPos[3]) + (YPos[0] - YPos[3]) * (YPos[0] - YPos[3]);
	b = (XPos[0] - XPos[2]) * (XPos[0] - XPos[2]) + (YPos[0] - YPos[2]) * (YPos[0] - YPos[2]);
	c = (XPos[1] - XPos[3]) * (XPos[1] - XPos[3]) + (YPos[1] - YPos[3]) * (YPos[1] - YPos[3]);
	d = (XPos[2] - XPos[1]) * (XPos[2] - XPos[1]) + (YPos[2] - YPos[1]) * (YPos[2] - YPos[1]);
	e = (XPos[0] - XPos[1]) * (XPos[0] - XPos[1]) + (YPos[0] - YPos[1]) * (YPos[0] - YPos[1]);
	f = (XPos[2] - XPos[3]) * (XPos[2] - XPos[3]) + (YPos[2] - YPos[3]) * (YPos[2] - YPos[3]);

	if (a == b && a == c && a == d && e == f)
		return true;

	return false;
}