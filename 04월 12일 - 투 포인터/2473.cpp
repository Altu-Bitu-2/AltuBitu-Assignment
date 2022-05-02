#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, liquid;
	cin >> n;
	vector<ll> v;
	for (int i = 0; i < n;i++) {
		cin >> liquid;
		v.push_back(liquid);
	}

	// 용액 오름차순 정렬
	sort(v.begin(), v.end());

	ll ans=1e10, cur=0;
	ll ans_l = 0, ans_r = n-1, ans_i = 0; // 정답 갱신용 인덱스

	// 변수 하나 픽하고 나머지 두 개는 투 포인터로 풀기
	for (int i = 0; i < n - 1 ; i++) {
		ll l = i + 1, r = n - 1;

		while (l < r) { // i , l, r
			cur = v[i] + v[l] + v[r];
			if (cur == 0) { // 바로 출력
				cout << v[i] << " " << v[l] << " " << v[r] << "\n";
				return 0;
			}
			else if (cur > 0) { // r-- 하기 전에 갱신함
				if (ans > abs(cur)) { // cur이 더 0에 가까운 경우 정답 갱신
					ans = abs(cur); // 갱신
					ans_l = l, ans_r = r, ans_i = i;
				}
				r--; // 0보다 크면 값을 줄여야 하므로
			}
			else { 
				if (ans > abs(cur)) {
					ans = abs(cur); // 최솟값 갱신
					ans_l = l, ans_r = r, ans_i = i;
				}
				l++; // 0보다 작으면 l을 늘려야 함 
			}
		}
	}

	cout << v[ans_i] << " " << v[ans_l] << " " << v[ans_r] << "\n";
	return 0;
}