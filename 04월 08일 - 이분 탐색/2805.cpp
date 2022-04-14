#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	cin >> n >> m;

	vector<ll> tree(n, 0);
	for (int i = 0; i < n; i++)
		cin >> tree[i];
	sort(tree.begin(), tree.end()); // 오름차순 정렬

	ll l = 0, r = tree[n - 1], mid, sum;
	ll ans=0;
	while (l <= r) {
		mid = (l+r) / 2;
		sum = 0;
		for (int i = 0; i < n; i++)
			if (mid < tree[i])
				sum += tree[i] - mid;
		// cout << "mid: " << mid << " sum : " << sum << "\n";
		if (sum >= m) { // 너무 많이 캤다면, l을 높여서 mid(자르는 높이) 올라가게 함
			if (ans < mid) ans = mid; // ans 갱신
			l = mid + 1;
		} // sum < m 
		else r = mid - 1;
	}
	cout << ans << '\n';

	
	return 0;
}