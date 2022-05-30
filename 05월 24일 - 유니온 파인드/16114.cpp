#include <iostream>
using namespace std;

int main() {
	int x, n;
	cin >> x >> n; // x 초깃값, 화살표 길이

	if (n == 0 && x > 0) {
		cout << "INFINITE";
		return 0;
	}
	if(n == 0 && x <= 0) {
		cout << "0";
		return 0;
	}
	if(n==1 && x < 0) {
		cout << "INFINITE";
		return 0;
	}
	if(n==1 && x >=0) {
		cout << "0";
		return 0;
	}
	if (n % 2 == 1) {
		cout << "ERROR";
		return 0;
	}
	int cnt = 0;
	while ( (x-(n/2)) > 0) {
		x -= (n / 2);
		cnt++;
	}
	cout << cnt << '\n';

	return 0;
}