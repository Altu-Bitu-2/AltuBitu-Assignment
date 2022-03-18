#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int arr[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	deque <int> dq;
	int n;
	cin >> n;
	for (int i = 0; i < n;i++)
		cin >> arr[i];

	reverse(arr, arr + n);
	for (int i = 1; i <= n; i++) {
		switch (arr[i-1]) {
			case 1:
				dq.push_front(i); // 1
				break;
			case 2: {
				int front = dq.front();
				dq.pop_front(); // 앞 하나 빼기
				dq.push_front(i); // 두번째에 넣기
				dq.push_front(front); // 첫번째꺼 다시 넣기	
				break;
			}
			case 3:
				dq.push_back(i);
				break;
		}
	}
	while(!dq.empty()) {
		cout << dq.front() << " ";
		dq.pop_front();
	}

	return 0;
}