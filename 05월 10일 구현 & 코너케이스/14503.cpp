#include <iostream>
#include <vector>

using namespace std;

// 파라미터: 현재 위치(r,c), 방향, 보드판
int cntCleanRobot(int r, int c, int d, vector<vector<int>>& board) {
    
    int dr[4] = { -1, 0, 1, 0 }; //상, 우, 하, 좌
    int dc[4] = { 0, 1, 0, -1 };

    int step = 0, ans = 0; // step: ans: 청소하는 칸 개수
    while (true) { // 계속 반복하면서 
        if (board[r][c] == 0) { // 현재 위치가 빈 칸이라면
            board[r][c] = 2; // 방문 표시
            ans++; // 칸 개수 증가
        }

        if (step == 4) { // 만약 네 번 실행되면
            if (board[r - dr[d]][c - dc[d]] == 1) { // 바로 뒤가 벽이라면
                return ans; // 작동 멈추고 정답 반환하기
            }
            r -= dr[d]; // 한 칸 후진
            c -= dc[d]; // 한 칸 후진
            step = 0; // 초기화
        }
        else { // 네 번이 아니라면 
            d = (d + 3) % 4; // 왼쪽 방향으로 바꾸기
            if (board[r + dr[d]][c + dc[d]]) { // 갈 수 있는지 확인
                step++; // 갈 수 없다면 
                continue; // 다음으로 넘어가기 
            }
            r += dr[d]; // 갈 수 있다면 이동
            c += dc[d]; // 갈 수 있다면 이동 
            step = 0; // 초기화
        }
    }
}


int main() {
    int n, m, r, c, d; // 세로, 가로, 현재 칸의 좌표(r,c), 바라보는 방향

    //입력
    cin >> n >> m >> r >> c >> d;
    vector<vector<int>> board(n, vector<int>(m, 0)); // board에 장소 상태 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j]; // 장소 상태 입력
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0;
}