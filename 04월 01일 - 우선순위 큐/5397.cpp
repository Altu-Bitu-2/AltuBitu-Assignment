#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<char> cursor_front, cursor_back; // 문자열 커서 앞부분, 커서 뒷부분
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
			case '<':
				if (!cursor_front.empty()) {
					char top = cursor_front.front();
					cursor_front.pop_front();
					cursor_back.push_back(top);
				}
				break;
			case '>':
				if (!cursor_back.empty()) { // 덱2(커서 뒷부분)에서 덱1(커서 앞부분)로 이동
					char back = cursor_back.back();
					cursor_back.pop_back();
					cursor_front.push_front(back);
				}
				break;
			case '-':
				if (!cursor_front.empty()) {
					cursor_front.pop_front();
				}
				break;
			default: // 디폴트는 커서 앞 부분에 s[i] 추가하는 것
				cursor_front.push_front(s[i]);
			}	
		}
		while (!cursor_front.empty()) { // 커서 앞 부분 출력
			cout << cursor_front.back();
			cursor_front.pop_back();
		}

		while (!cursor_back.empty()) { // 커서 뒷 부분 출력
			cout << cursor_back.back();
			cursor_back.pop_back();
		}
		cout << "\n";

	}

	return 0;
}