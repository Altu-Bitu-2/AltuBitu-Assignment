#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, tip[100001];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> tip[i];
	sort(tip, tip + n, greater<>());

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int tmp = tip[i] - i;
		if (tmp <= 0) break;
		sum += tmp;
	}

	cout << sum << "\n";

	return 0;
}
