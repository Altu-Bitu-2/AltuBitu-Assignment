#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Question{
	string x;
	int strike, ball;
};

vector <Question> v;

int checkStrike(string s) {
	int flag = 0;
	for (auto i : v) {
		int strike = 0;
		for (int j = 0; j < 3; j++)
			if (i.x[j] == s[j])
				strike++;
		if (strike != i.strike) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) return 0;
	return 1;
}

int checkBall(string s) {
	int flag = 0;
	for (auto i : v) {
		int ball = 0;
		for (int j = 0; j < 3; j++) {
			if (s.find(i.x[j]) != string::npos && s.find(i.x[j]) != j)
				ball++;
		}
		if (ball != i.ball) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) return 0;
	return 1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string tmp;
	int n, cnt = 0;
	cin >> n;

	for(int i=0 ; i<n ; i++) {
		Question tmp;
		cin >> tmp.x >> tmp.strike >> tmp.ball;
		v.push_back({ tmp.x, tmp.strike, tmp.ball });
	}

	for (int i = 123; i <= 987; i++) {
		string tmp = to_string(i);
		if (tmp.find('0') != string::npos) // i를 문자열로 바꿨을 때 0이 있는지 검사
			continue;
		int flag = 0;
		for (int j = 0; j < 2; j++)
			for (int l = j + 1; l < 3; l++)
				if (tmp[l] == tmp[j]) { // 같은 문자 있는지 검사
					flag = 1;
					break;
				}
		if (flag == 1) continue;
		int strike = checkStrike(tmp);
		int ball = checkBall(tmp);
		if (strike && ball) cnt++;
	}
	cout << cnt << "\n";

	return 0;
}