#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int r, b;
	cin >> r >> b;

	for (int i = 1; i * i <= b; i++) {
		if (b % i == 0) {
			int n1 = i; // 작은 수
			int n2 = b / i; // 큰 수
			if ((n1 + 2) * (n2 + 2) == r + b) {
				cout << n2 + 2 << " " << n1 + 2;
				return 0;
			}
		}
	}
	return 0;
}