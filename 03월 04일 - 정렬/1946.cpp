#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n, t;
	cin >> t;

	while (t--) {
		cin >> n;
		int a, b;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());
		int cnt = 1; // 첫 번째 한 명 무조건 합격
		int highest_rank = v[0].second;
		for (int i = 1; i < n; i++)
			if (v[i].second < highest_rank) {
				cnt++;
				highest_rank = v[i].second;
			}
		cout << cnt << "\n";
	}
	return 0;
}
