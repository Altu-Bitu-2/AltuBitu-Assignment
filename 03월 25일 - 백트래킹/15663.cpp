#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[10], answer[10];
int visit[10];
void dfs(int x, int cnt) {

	if (cnt == m) {
		for (int i = 0; i < m  ; i++) 
			cout << answer[i] << ' ';
		cout << '\n';
		return;	
	}
	int tmp = 0;
	
	for (int i = 0; i < n; i++) {
		if (visit[i] == 0 && tmp != arr[i]) {
			tmp = arr[i];
			answer[cnt] = arr[i];
			visit[i] = 1;
			dfs(i, cnt + 1); // cnt +1 까지 더 깊게 들어가자
			visit[i] = 0;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n); // 2 4 4
	dfs(0, 0);
	return 0;
}
