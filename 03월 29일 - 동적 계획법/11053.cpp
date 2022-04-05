#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int arr[1001], dp[1001];
	int n, answer=0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		answer = max(answer, dp[i]);
	}
	

	cout << answer << '\n';

	return 0;
}
