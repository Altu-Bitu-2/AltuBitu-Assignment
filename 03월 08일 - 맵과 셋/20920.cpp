#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool cmp(pair <string, int> left, pair <string, int> right) {
		if(left.second != right.second)
			return left.second > right.second;
		if (left.first.length() != right.first.length())
			return left.first.length() > right.first.length();
		return left.first < right.first;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	int n, m;
	cin >> n >> m;
	map <string, int> map;
	for (int i = 0; i < n ; i++) {
		cin >> s;
		if (s.length() >= m)
			map[s]++;
	}
	vector <pair<string, int>> v(map.begin(), map.end());
	sort(v.begin(), v.end(), cmp);

	for (auto iter : v) 
		cout << iter.first << '\n';
	
	return 0;
}