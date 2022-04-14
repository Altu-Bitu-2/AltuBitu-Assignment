#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k, num;
	char letter;
	cin >> n >> k;
	vector<char> wheel(n, 0); // 초기화
	int cur = 0; // 현재 0번 위치에서 시작
	while (k--) {
		cin >> num >> letter; 
		while (num--) { // num 만큼 현재 인덱스 이동
			cur++;
			if (cur == n) cur %= n;
		}
		if (wheel[cur] && wheel[cur] != letter) { // 값이 들어있는데 letter랑 다르다면
			cout << "!\n"; return 0;
		}
		if (wheel[cur] == letter) continue; // 값이 들어있지 않거나, letter랑 같다면 continue (다음으로 넘어가기)
		wheel[cur] = letter; // letter 넣기
	}
	map<char, int> m;
	for (int i = 0; i < n;i++) {
		if (wheel[i]) m[wheel[i]]++;
		if (m[wheel[i]] > 1) { // 같은 값 들어있는 경우는 있을 수 없으므로
			cout << "!"; return 0; // ! 출력
		}
	}

	for (int i = 0; i < n; i++) {
		if (!wheel[cur]) cout << "?"; // 값이 들어있지 않으면 ? 출력
		else cout << wheel[cur];
		cur--;
		if (cur < 0)
			cur +=n;
	}

	return 0;
}