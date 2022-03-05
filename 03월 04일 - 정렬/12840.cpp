#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int DAY = 86400;

int timeToSecond(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}

pair<pair<int, int>, int> secondToTime(int sec) {
	pair<pair<int, int>,int> p;
	p.first.first = sec / 3600;
	p.first.second = sec / 60 % 60;
	p.second = sec % 60;
	return p;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int h, m, s, q, t, c;
	cin >> h >> m >> s >> q;
	int cur_sec = timeToSecond(h, m, s);
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> c; 
			cur_sec += c; 
			cur_sec %= DAY;
		}
		else if (t == 2) {
			cin >> c;  
			cur_sec -= c;
			cur_sec %= DAY;
			if (cur_sec < 0) cur_sec += DAY;
		}
		else {
			pair<pair<int, int>, int> time = secondToTime(cur_sec);
			cout << time.first.first << " " << time.first.second << " " << time.second << "\n";
		}
	}


	return 0;
}