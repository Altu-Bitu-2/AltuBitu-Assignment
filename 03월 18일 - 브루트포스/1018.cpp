#include <iostream>
#include <algorithm>
using namespace std;

char arr[51][51];

// i, j에서 부터 8x8까지 왼쪽 위가 W로 시작할 때 기준으로 계산 
// num: 다시 칠해야 하는 타일 수
// num과 반대 경우의 수인 64-num 중 작은 수 리턴
int checkWB(int x, int y) {
	int num = 0;
	for (int i = x; i <= x + 7; i++) 
		for (int j = y; j <= y + 7; j++) {
			if (i % 2 == 0 && j % 2 == 0 && arr[i][j] == 'B') num++;	
			else if (i % 2 == 0 && j % 2 != 0 && arr[i][j] == 'W') num++;
			else if (i % 2 != 0 && j % 2 == 0 && arr[i][j] == 'W') num++;
			else if (i % 2 != 0 && j % 2 != 0 && arr[i][j] == 'B') num++;
		}
	num = min(num, 64 - num);
	return num;
}
int main() {

	int n, m, cnt = 100, tmp;
	cin >> n >> m;
	for (int i = 0; i < n;i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i + 7 < n; i++) {
		for (int j = 0; j + 7 < m; j++) {
			tmp = checkWB(i, j);
			cnt = min(cnt, tmp);
		}
	}
	cout << cnt << "\n";
	return 0;
}
