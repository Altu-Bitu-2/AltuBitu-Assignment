#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	queue <int> q;

	for (int i = 1; i <= n;i++)
		q.push(i);

	cout << "<";
	while (!q.empty()){
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front()); // 제일 앞에거를 제일 뒤에 넣기
			q.pop();
		}
		cout << q.front();
		q.pop();

		if (!q.empty())
			cout << ", ";
	}
	cout << ">" << endl;

	return 0;
}