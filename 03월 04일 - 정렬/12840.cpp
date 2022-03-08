#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int DAY = 86400;

tuple<int, int, int> secondToTime(int sec) {
	return make_tuple(sec / 3600, sec / 60 % 60, sec % 60);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int h, m, s, q, t, c;
	cin >> h >> m >> s >> q;
	int cur_sec = h * 3600 + m * 60 + s;
	while (q--) {
		cin >> t;
		switch (t) {
		case 1: 
				cin >> c;
				cur_sec += c;
				cur_sec %= DAY;
				break;
			
		case 2:
				cin >> c;
				cur_sec -= c;
				cur_sec %= DAY;
				if (cur_sec < 0) cur_sec += DAY;
				break;
			
		case 3:
				tuple<int, int, int> time = secondToTime(cur_sec);
				cout << get<0>(time) << " " << get<1>(time) << " " << get<2>(time) << "\n";
				break;
		}
	}


	return 0;
}
