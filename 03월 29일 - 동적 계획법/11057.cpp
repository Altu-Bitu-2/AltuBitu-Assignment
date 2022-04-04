#include <iostream>

using namespace std;

const int MOD = 10007;
int dp[1001][10];
int main() {

	int n, answer=0;
	cin >> n;

	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= 9; j++) {
			if (i == 1) dp[i][j] = 1;

			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= MOD;

			}
		}
	

	for (int i = 0; i <= 9; i++)
		answer += dp[n][i];

	cout << answer % MOD << "\n";

	return 0;
}
