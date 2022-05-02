#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int n, tmp=0, ans=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n ; i++) { // i: 현재 검사할 수
		int l = 0, r = n-1;
		while (l < r) {
			if (i == l) { l++; continue; } // 자기 자신은 더해지는 수에서 제외
			if (i == r) { r--; continue; } // 자기 자신은 더해지는 수에서 제외
			if (v[l] + v[r] == v[i]) {
				ans++;
				break;
			}
			if (v[l] + v[r] <= v[i]) l++;
			else r--; // i보다 크면 값을 줄여줘야 하므로
		}
	}
	cout << ans << "\n";


	return 0;
}
