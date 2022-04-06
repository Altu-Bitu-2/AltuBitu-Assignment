#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, k, tmp;
	char sign;
	cin >> t;
	while (t--) {
		priority_queue<int> max_pq; // 최대힙
		priority_queue<int, vector<int>, greater<>> min_pq; // 최소힙
		cin >> k;
		map<int, int> m;
		while (k--) {
			cin >> sign;
			switch (sign) {
			case 'I': //
				cin >> tmp;
				max_pq.push(tmp);
				min_pq.push(tmp);
				m[tmp]++; // 숫자가 나온 개수 기록
				break;
			case 'D':
				cin >> tmp;
				if (tmp == 1)
				{
					while (!max_pq.empty() && m[max_pq.top()] == 0)
						max_pq.pop(); // 이미 삭제된 숫자라면 지우기
					if (!max_pq.empty()) {
						m[max_pq.top()]--;
						max_pq.pop(); // 최댓값 하나 지우기
					}
				}
				else {
					while (!min_pq.empty() && m[min_pq.top()] == 0) // 이미 삭제된 숫자라면 pop하기
						min_pq.pop();
					if (!min_pq.empty()) {
						m[min_pq.top()]--;
						min_pq.pop(); // 최솟값 하나 지우기
					}
				}
			}
		}
		while (!min_pq.empty() && m[min_pq.top()] == 0) // 이미 삭제된 숫자가 남아 있는 경우 pop해주기
			min_pq.pop();
		while (!max_pq.empty() && m[max_pq.top()] == 0) // 이미 삭제된 숫자가 남아 있는 경우 pop해주기
			max_pq.pop();

		if (min_pq.empty() || max_pq.empty()) {
			cout << "EMPTY\n";
			continue;
		}
		cout << max_pq.top() << ' ' << min_pq.top() << '\n';
	}

	return 0;
}