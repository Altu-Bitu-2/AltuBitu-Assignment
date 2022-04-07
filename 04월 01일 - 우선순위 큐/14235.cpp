#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int n, a, tmp;
	cin >> n;
	priority_queue<int> pq;
	while (n--) {
		cin >> a;
		if (a == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else cout << "-1\n";
		}
		else {
			for (int i = 0; i < a; i++) {
				cin >> tmp;
				pq.push(tmp);
			}
		}
	}

	return 0;
}
