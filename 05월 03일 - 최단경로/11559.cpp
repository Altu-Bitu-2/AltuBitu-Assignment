#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

const int ROW = 6; //행과 열을 바꿔줄 것이므로 ROW를 6, cOL을 12로 설정
const int COL = 12; 

bool bfs(int r, int c, vector<vector<char>> &board) {
    int dr[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q;
    queue<ci> puyo; //포함된 좌표 저장할 큐
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false)); // 

    //시작 초기화
    q.push({r, c});
    puyo.push({r, c}); // 현재 뿌요 좌표 저장
    visited[r][c] = true; // 현재 칸 방문 기록
    int cnt = 1; //모여있는 뿌요의 개수
    while (!q.empty()) { 
        int cr = q.front().first; // 현재 뿌요의 x좌표
        int cc = q.front().second; // 현재 뿌요의 y좌표
        q.pop(); // 뿌요 하나 지우기

        for (int i = 0; i < 4; i++) { // 상, 하, 좌, 우 확인하면서
            int nr = cr + dr[i]; // 다음 좌표 행 위치
            int nc = cc + dc[i]; // 다음 좌표 열 위치
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) {
                continue; // board 인덱스를 초과하거나 방문했다면 넘어가기
            }
            if (board[nr][nc] == board[cr][cc]) { // 이전 칸의 뿌요 색이랑 같아야 방문할 수 있음
                q.push({nr, nc}); // 큐에 뿌요 위치 저장
                puyo.push({nr, nc}); // 뿌요 위치 따로 저장
                visited[nr][nc] = true; // 방문 기록
                cnt++; // 모여있는 뿌요 개수 하나 증가시키기
            }
        }
    }
    if (cnt < 4) { //뿌요 안터짐
        return false; // false 반환
    }
    while (!puyo.empty()) { // 뿌요가 4개 이상 모여있다면 터뜨리기
        int cr = puyo.front().first; // 터뜨릴 뿌요 x좌표
        int cc = puyo.front().second; // 터뜨릴 뿌요 y좌표
        puyo.pop(); // 제거하기

        board[cr][cc] = '.'; // 터뜨린거는 .으로 표시
    }
    return true;
}

//뿌요를 터뜨린 이후의 새 필드를 작성하는 함수
vector<vector<char>> makeNewBoard(vector<vector<char>> &board) {
    vector<vector<char>> new_board(ROW, vector<char>(COL, '.')); // 새로운 필드
    for (int i = 0; i < ROW; i++) { // i: 행
        queue<char> temp; //남아있는 뿌요 모으는 큐
        for (int j = 0; j < COL; j++) { // j: 열
            if (board[i][j] != '.') { // 뿌요가 남아있다면
                temp.push(board[i][j]); // 큐에 넣기
            }
        }
        int index = 0; // 뿌요 이동한 인덱스
        while (!temp.empty()) { // 큐가 빌 때까지
            new_board[i][index++] = temp.front(); // 앞에서부터 큐에 있는 뿌요들 넣어주기
            temp.pop(); // 넣은 뿌요는 제거
        }
    }
    return new_board; // 새 필드 반환
}

int simulation(vector<vector<char>> &board) {
    int answer = 0; // 연쇄 개수
    while (true) { // 뿌요 다 터뜨릴 때까지 반복
        bool flag = false; //뿌요가 터졌는지 확인
        for (int i = 0; i < ROW; i++) { // i: 행
            for (int j = 0; j < COL; j++) { // j: 열
                if (board[i][j] == '.') { // 뿌요 없다면
                    continue; // 넘어가기
                }
                if (bfs(i, j, board)) { //한 번이라도 뿌요 터졌다면
                    flag = true; // flag 변경하기
                }
            }
        }
        if (!flag) { // 터뜨릴 뿌요가 없다면 무한 루프 빠져나오기
            break;
        }
        board = makeNewBoard(board); // 뿌요 터뜨리고 뿌요 떨어뜨린 후 board 갱신
        answer++; // 연쇄 개수 1 증가
    }
    return answer; // 정답 리턴
}


int main() {
    //입력
    char input;
    vector<vector<char>> board(ROW, vector<char>(COL)); // 뿌요들 저장할 board 벡터
    for (int i = 0; i < COL; i++) { // 입력 받기, i: 열
        for (int j = 0; j < ROW; j++) { // j: 행
            cin >> input;
            board[j][COL - i - 1] = input; // 6*12로 입력 받기 위해 행 열을 바꿔서 입력 받기
        }
    }

    //연산 & 출력
    cout << simulation(board);
    return 0;
}