#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> score; // 점수는 최소 힙
	int n, m, p, l, mge, top, sum=0, answer=0;
	cin >> n >> m;

	while (n--) {
		cin >> p >> l; 
		priority_queue<int> mileage; // 마일리지는 최대 힙
		for(int i=0 ; i<p ; i++) {
			cin >> mge;
			mileage.push(mge); 
		}
		if (p < l) { // p가 l보다 작다면 마일리지 1로 신청할 수 있음
			score.push(1);
			continue;
		}
		while (l--) { // mileage에서 l번째 있는 값 알아내기
			top = mileage.top();
			mileage.pop();
		}
		score.push(top);
	}
	while (!score.empty()) {
		top = score.top();
		sum += top;
		if (sum > m) break;
		answer++;
		score.pop();
	}
	cout << answer << '\n';

	return 0;
}