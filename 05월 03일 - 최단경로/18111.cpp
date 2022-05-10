#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, b;

vector<int> flattenLand(vector<vector<int>>& field, int minHeight, int maxHeight) { 
    // 브루트포스로 최대 높이~최소 높이까지 반복문 돌면서 땅 고르게 하는데 걸리는 최소 시간과 높이 구하는 함수
	int time = 99999999, height = 0;
	vector <int> answer(2); 

	for (int curHeight = maxHeight; curHeight >= minHeight; curHeight--) { 
		int cnt1 = 0, cnt2 = 0, cur_time = 0; // cnt1: 인벤토리에서 꺼내는 개수, cnt2: 인벤토리에 넣는 개수

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] < curHeight) cnt1 += curHeight - field[i][j]; // 인벤토리에서 꺼내와서 쌓는 경우
				else cnt2 += field[i][j] - curHeight; // 인벤토리에 넣는 경우
			}
		}
		if (cnt1 <= b + cnt2) { // 재고 + 인벤토리에 넣는 개수가 꺼내는 개수보다 커야함
			cur_time = cnt1 + cnt2 * 2; // 현재 높이에서 걸리는 시간 계산
			if (cur_time < time) { // 최소 시간, 높이 갱신
				time = cur_time;
				height = curHeight;
			}
		}
	}

	answer[0] = time;
	answer[1] = height;

	return answer;
}

int main() {
	cin >> n >> m >> b;
	vector<vector<int>> field(n + 1, vector<int>(m, 0)); // 0으로 초기화
	int minHeight = 300, maxHeight = -1; // 최소 높이, 최대 높이

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			minHeight = min(minHeight, field[i][j]);
			maxHeight = max(maxHeight, field[i][j]);
		}
	}
	vector<int> answer = flattenLand(field, minHeight, maxHeight);
	cout << answer[0] << ' ' << answer[1];

	return 0;
}