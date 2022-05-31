#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> matrix;
int n, ans = 0;

// 종료 시점일 때, 블록값 계산하는 ㅎ마수?


// 가장 큰 블록 값 리턴하는 함수
int getMaxBlock(matrix& board) {
	int max_block = 0; // 선언 및 초기화
	for (int i = 0; i < n; i++) { // n x n 반복문 돌면서
		for (int j = 0; j < n; j++) {
			max_block = max(max_block, board[i][j]); // 가장 큰 값 갱신
		}
	}
	return max_block; // 가장 큰 값 리턴
}

matrix transposeMatrix(matrix &board) {
	matrix board_t(n, vector<int>(n, 0)); // 상->좌 변환한 후의 배열
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board_t[i][j] = board[j][i]; // 행, 열을 바꿔서 저장

		}
	}
	return board_t; // 변환한 배열 리턴
}


// 상으로 이동하는 함수
// 한 열씩 검사하면서 위의 행부터 2개씩 같은거 있으면 합치기
// 이때 블록 없는 부분은 넘어가고, 블록이 존재했던 값을 비교하는 것이 중요
matrix upMove(matrix board) {
	matrix temp(n, vector<int>(n, 0)); // 새롭게 블록 저장할 배열
	for (int j = 0; j < n; j++) { // 위에서 아래로 세로 방향으로 내려옴
		int idx = 0; // 행 기록
		int prev = 0; // 이전 값 기록
		for (int i = 0; i < n; i++) {
			if (!board[i][j]) { // 값이 없다면 다음 블록으로 넘어가기
				continue;
			}
			if (board[i][j] == prev) { // 현재 값이랑 이전 값이랑 같다면
				temp[idx - 1][j] *= 2;// 이전 값에 곱하기2 한 값 기록
				prev = 0; // 초기화
			}
			else {
				temp[idx++][j] = board[i][j]; // 이전 블록이랑 값이 다르면, 현재 값 그대로 옮기기
				prev = board[i][j]; // prev 현재 값으로 갱신하기
			}
		}
	}
	return temp; // 위로 움직인 새로운 배열 리턴
}


void backtracking(int cnt, matrix board) {
	if (cnt == 5) { // 5번 움직이면 종료
		ans = max(ans, getMaxBlock(board));
		return;
	}
	// Transpose matrix 구하기 (상 -> 좌)
	matrix board_t = transposeMatrix(board);

	// 상
	backtracking(cnt + 1, upMove(board)); // 몇 번 움직였는지 횟수랑, 위로 움직인 보드 전달

	// 하
	reverse(board.begin(), board.end()); // 위 아래를 뒤집은 다음
	backtracking(cnt + 1, upMove(board)); // 상으로 움직이는 함수 실행

	// 좌
	backtracking(cnt + 1, upMove(board_t)); // 전치 행렬을 구한 후, 상으로 움직이는 함수 실행
	
	// 우
	reverse(board_t.begin(), board_t.end()); // 전치 행렬 구하고 위 아래를 뒤집고
	backtracking(cnt + 1, upMove(board_t)); // 상으로 움직인 함수 실행 

}

int main() {

	cin >> n;
	matrix board(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j]; // 입력받기

	backtracking(0, board);

	cout << ans;
	return 0;
}