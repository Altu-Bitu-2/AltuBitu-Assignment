#include <iostream>
#include <queue>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
    // <절댓값 x, 원본 x> 저장
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << '\n'; // 원래 x 출력
				pq.pop();
			}
			else
				cout << "0\n";
			continue;
		}
		pq.push(make_pair(abs(x), x)); 
	
	
	}
	return 0;
}
