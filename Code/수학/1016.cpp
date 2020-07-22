#include <iostream>

using namespace std;

long long Max, Min;
long long Start, End;
bool C[1000001];

int main() {
	cin >> Min >> Max;

	for (long long i = 2; i * i <= Max; i++) {
		Start = Min / (i * i);
		End = Max / (i * i);
		if (Start * i * i != Min)
			Start++;
		
		for (Start; Start <= End; Start++) 
			C[Start * i * i - Min] = true;
	}
	
	int Count = 0;
	for (int i = 0; i <= Max - Min; i++)
		if (!C[i])
			Count++;

	cout << Count;
	return 0;
}