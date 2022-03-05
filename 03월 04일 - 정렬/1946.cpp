#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}
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
		sort(v.begin(), v.end(), cmp);
		int cnt = 1; // 첫 번째 한 명 무조건 합격
		int min_num = v[0].second;
		for (int i = 1; i < n; i++)
			if (v[i].second < min_num) {
				cnt++;
				min_num = v[i].second;
			}
		cout << cnt << "\n";
	}
	return 0;
}