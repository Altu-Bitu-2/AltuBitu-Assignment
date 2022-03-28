#include <iostream>
#include <map>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, cnt = 0;
	string s;
	cin >> n;

	while (n--) {
		map<char, int> m;
		int flag = 1;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (!m[s[i]]) m[s[i]]++; //처음 등장하는 단어면 문제 없음
			else if (s[i] == s[i - 1]) continue;
			else { flag = 0; break; }
		}
		if (flag == 1) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}
