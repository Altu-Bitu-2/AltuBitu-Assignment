#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	int n;
	int dp[1000];
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		dp[i] %= 10007;
	}

	cout << dp[n];
	return 0;
}
