#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19; // 줄 개수

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>>& board) {
    // 범위가 유효하고 이어지는 돌이 있으면 true 리턴
    return r >= 0 && r < SIZE&& c >= 0 && c < SIZE&& board[r][c] == stone;
}

// 현재 위치(r,c), 방향, 바둑알색상, 보드판
bool validDir(int r, int c, int d, int stone, vector<vector<int>>& board) {
    int dr[4] = { 0, 1, 1, -1 }; //가로, 세로, 우하향 대각선, 우상향 대각선
    int dc[4] = { 1, 0, 1, 1 };

    //(r, c) 이전에 위치한 이어지는 돌이 있는지 확인
    if (promising(r - dr[d], c - dc[d], stone, board)) {
        return false; // 있다면 false 리턴
    }
    int cnt = 0; // 돌의 개수
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++; // 돌 개수 하나 증가시키기
        r += dr[d]; // 다음 칸으로 이동
        c += dc[d]; // 다음 칸으로 이동
    }
    return cnt == 5; // 다섯 개라면 true 리턴하기
}

bool isEnd(int r, int c, vector<vector<int>>& board) {
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) { // 현재 위치(r,c), 방향, 바둑알색상, 보드판
            return true; // 5개라면 끝났다는 거니까 true 리턴
        }
    }
    return false; // 아직 안 끝났으면 false 리턴
}


int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); // 보드판

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j]; //입력
        }
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) { //돌이 없음
                continue;
            }
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; // 가로줄 번호, 세로줄 번호
                return 0;
            }
        }
    }
    cout << 0; // 승부 결정 안되면 0 출력
    return 0;
}