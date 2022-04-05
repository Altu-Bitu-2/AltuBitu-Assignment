#include <iostream>
#include <vector>
using namespace std;


int knapsack(int n, int m, vector<int>& coin) {
	vector <int> dp(m + 1, 0);

	dp[0] = 1; // 0원을 만드는 가짓수는 1개
	for (int i = 0; i < n; i++) { // 동전 개수만큼 반복문 돌면서
		for (int j = coin[i]; j <= m; j++) // 각 동전에 대해 m원까지 만드는 경우의 수 구하기
			dp[j] += dp[j - coin[i]]; // 각 동전을 마지막으로 사용하는 경우의 수는 dp[j-coin[i]]가 됨
	}
	return dp[m];
}


int main() {


	int t, n, m;

	cin >> t;
	while (t--) {
		cin >> n;
		vector <int> coin(n, 0);
		for (int i = 0; i < n;i++)
			cin >> coin[i];
		cin >> m;

		cout << knapsack(n, m, coin) << '\n';
	
	}

	return 0;
}
