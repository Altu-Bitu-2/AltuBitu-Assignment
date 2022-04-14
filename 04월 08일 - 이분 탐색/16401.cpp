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

	vector<ll> pepero(m, 0);
	for (int i = 0; i < m; i++)
		cin >> pepero[i];
	
	sort(pepero.begin(), pepero.end()); // 오름차순 정렬

	ll l = 0, r = pepero[m - 1], mid, cnt;
	ll ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		//cout << "mid: " << mid << '\n';
		cnt = 0; // 현재 mid로 나눠줄 수 있는 인원 수
		if (mid != 0) { // mid가 0이 아닐 때만 나눠줄 수 있음
			for (int i = 0; i < m; i++)
				if (mid <= pepero[i])
					cnt += pepero[i] / mid; // 몫 더하기
		}
		if (cnt >= n) { 
			if (ans < mid) ans = mid; // ans 갱신
				l = mid + 1;
				//cout << "mid: " << mid << " cnt : " << ans << "\n";
		} // sum < m 
		else r = mid - 1;
	}
	cout << ans << '\n';


		return 0;
}