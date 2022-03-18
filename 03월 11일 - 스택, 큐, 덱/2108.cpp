#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
double arr[500001];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first; // 오름차순 정렬
}

double cal_round(double n) {
	int r;
	if (n >= 0) {
		r = n + 0.5;
		return r;
	}
	else {
		r = n - 0.5;
		return r;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	map<int, int> m;

	int n, sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		m[arr[i]]++;
	}

	sort(arr, arr + n);
	vector<pair<int,int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	cout << cal_round(((double)sum / (double)n)) << "\n";

	cout << arr[n / 2] << "\n";

	if (n > 2 && v[0].second == v[1].second) 
		cout << v[1].first << "\n"; // 최빈값이 여러개있을 때
	else 
		cout << v[0].first << "\n";
	
	cout << arr[n - 1] - arr[0] << "\n";

	return 0;
}