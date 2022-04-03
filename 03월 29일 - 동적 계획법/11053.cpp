#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int arr[1001], dp[1001];
	int n, answer=0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j <= i; j++) {
			// arr[i]보다 값이 작은 것 중에서 dp[i]가 가장 큰 것 선택
			if (arr[j] < arr[i] && dp[j] > tmp)
				tmp = dp[j]; // 갱신
		}
		dp[i] = tmp + 1;
	}
	for (int i = 0; i < n; i++)
		answer = max(answer, dp[i]);

	cout << answer << '\n';

	return 0;
}
