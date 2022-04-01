#include <iostream>
#include <algorithm>
using namespace std;

int visit[16];
char arr[16], input[16];
int l, c;
int checkValid() {
	int vowels=0, constants=0;
	for (int i = 0; i < l; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') vowels++;
		else constants++;
	}
	if (vowels >= 1 && constants >= 2) return 1;
	return 0;
}
void dfs(int num, int cnt) {
	if (cnt == l) {
		// 최소 한 개의 모음과 최소 두 개의 자음으로 이뤄져 있는지 검사
		int flag = checkValid();
		if (flag == 0) return;
		for (int i = 0; i < cnt; i++) cout << arr[i];
		cout << "\n";
		return;
	}
	for (int i = num; i < c; i++)
		if (visit[i] != 1) {
			visit[i] = 1;
			arr[cnt] = input[i];
			dfs(i + 1, cnt + 1);
			visit[i] = 0;
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> input[i];
	sort(input, input + c);
	dfs(0, 0);

	return 0;
}