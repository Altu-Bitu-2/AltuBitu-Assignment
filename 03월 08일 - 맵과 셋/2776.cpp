#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n, num, m;
	cin >> t;

	while (t--) {
		cin >> n;
		map<int, int> note;
		for (int i = 0; i < n; i++) {
			cin >> num;
			note[num] = 1;
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> num;
			if (note[num])
				cout << "1\n";
			else cout << "0\n";
		}
	}
	return 0;
}