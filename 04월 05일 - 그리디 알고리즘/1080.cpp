#include <iostream>
#include <queue>
using namespace std;

int a[51][51], b[51][51];
int n, m, answer;

void computeDiff() {

	// 3x3에서 a, b값 다르면 바꿔주기
	for (int i = 0; i < n -2; i++) {
		for (int j = 0; j < m-2; j++) {
			if (a[i][j] != b[i][j]) {
				for (int k = i; k < i + 3; k++) {
					for (int t = j; t < j + 3; t++) {
						a[k][t] = (a[k][t] ? 0 : 1);
					}
				}
				answer++;
			}
			else continue;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int flag = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) { // a 입력받기
		cin >> s;
		for (int j = 0; j < m; j++)
			a[i][j] = s[j]-'0';
	}

	for (int i = 0; i < n; i++) { // b 입력받기
		cin >> s;
		for (int j = 0; j < m; j++)
			b[i][j] = s[j]-'0';
	}

	// a와 b의 모든 값이 같은지 검사, 하나라도 다르면 flag=1 처리
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (flag == 0) {
		cout << "0\n"; return 0;
	}
	if (flag == 1 && (n < 3 || m < 3)) { // 값이 다른게 있고 n, m이 3보다 작다면
		cout << "-1\n"; // 바꿀 수 없으므로 -1 출력
		return 0;
	}

	computeDiff();
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (a[i][j] != b[i][j]) { // 연산 후에도 값이 다른게 있다면 -1 출력
				cout << "-1\n";
				return 0;
			}

	cout << answer << '\n';


	return 0;
}