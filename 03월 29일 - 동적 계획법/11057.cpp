#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;
vector<vector<int>> dp(1001, vector<int>(10, 1));
int main() {

	int n, answer=0;
	cin >> n;

	// dp[i][j]: 길이가 i고 j로 끝나는 오르막 수의 개수
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= 9; j++) {
			// dp[i][j] = 길이가 i고 j-1로 끝나는 오르막 수 개수 + 길이가 i-1이고 j로 끝나는 오르막 수 개수
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			dp[i][j] %= MOD;
		}
	for (int i = 0; i < 10; i++)
		answer += dp[n][i];
	cout << answer % MOD << "\n";

	return 0;
}
