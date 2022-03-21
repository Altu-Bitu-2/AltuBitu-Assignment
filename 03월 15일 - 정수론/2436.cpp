#include <iostream>
using namespace std;

int gcdIter(int a, int b) {
	if (a < b) swap(a, b);
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;

	cin >> a >> b; 
	int num = b / a;
	int tmp;

	for (int i = 1 ; i * i <= num; i++) {
		if (num % i == 0) {
			if (gcdIter(i, num / i) == 1) tmp = i;
		}
	}
	cout << a * tmp << " " << a * (num/ tmp) << "\n";
	
	return 0;
}