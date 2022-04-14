#include <iostream>
#include <vector>

using namespace std;
typedef pair<string, int> ci;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<ci> nickname;
	int n, m, num;
	string s;
	cin >> n >> m;
	vector<int> power(m);
	
	for (int i = 0; i < n; i++) {
		cin >> s >> num;
		if (i == 0) nickname.push_back({ s, 0 }); // 처음에 0도 넣어줌
		nickname.push_back({ s, num });
	}
	for (int i = 0; i < m; i++)
		cin >> power[i];
	
	int l, r, mid;
	int i = 0;
	while(i < m){
		l = 0, r = n; // 초기화
		while (l + 1 < r) {
			mid = (l + r) / 2;
			if (nickname[mid].second >= power[i]) 
				r = mid;
			else  l = mid; 
			
		}
		cout << nickname[r].first << '\n';
		i++;
	}
	return 0;
}