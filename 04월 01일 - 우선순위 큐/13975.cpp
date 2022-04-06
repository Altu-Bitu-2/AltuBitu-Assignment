#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, tmp;
	cin >> t;
	while (t--) {
		cin >> n;
		long long answer = 0; // k:1000000이고 파일 크기가 10000이므로 longlong
		priority_queue<long long, vector<long long>, greater<long long>> pq; // 최소 힙으로 구현
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			pq.push(tmp); // 입력
		} 
		while (pq.size()>1) { // 한 개 남을 때까지 반복
			long long n1 = pq.top();
			pq.pop();
			long long n2 = pq.top();
			pq.pop();
			answer += (n1 + n2); // 최솟값 두 개 pop해서 더하고 다시 pq에 넣기
			pq.push(n1 + n2);
		} 
		cout << answer << '\n';
	}

	return 0;
}
