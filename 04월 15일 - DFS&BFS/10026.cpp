#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;// pair<int, int> 대신 ci 사용

// G를 R로 변경하는 함수
void greenToRed(int n, vector<vector<char>> &board) {
    for (int i = 0; i < n; i++) { // 이중 for문을 돌면서
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G') { // G이면
                board[i][j] = 'R'; // R로 변경하기
            }
        }
    }
}

void bfs(int n, int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &board) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q; // 좌표 저장할 큐 선언

    //큐 초기화
    q.push({r, c});
    visited[r][c] = true; // 방문 표시
    while (!q.empty()) { // q에 남아있는 원소가 없을 때까지 반복
        int cr = q.front().first; // 큐의 제일 앞에 있는 원소의 r(행)좌표
        int cc = q.front().second; // 큐의 제일 앞에 있는 원소의 c(열)좌표
        q.pop(); // 큐의 제일 앞에 있는 원소 제거하기

        for (int i = 0; i < 4; i++) { // 상, 하, 좌, 우 네 방향에 대해 검사하면서 연결된 곳이 있으면 queue에 넣어줌
            int nr = cr + dr[i]; // 다음 행 위치 = 현재 행 위치 + (상, 하, 좌, 우) 중 하나
            int nc = cc + dc[i];// 다음 열 위치 = 현재 열 위치 + (상, 하, 좌, 우) 중 하나
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) {// 인덱스가 board 범위를 벗어나면
                continue; // 다음 방향으로 넘어가기
            }
            if (board[nr][nc] != board[cr][cc]) { // 다른 구역이라면 (알파벳 값이 다르다면)
                continue; // 다음으로 넘어가기
            }
            q.push({nr, nc}); // 큐에 다음으로 방문할 곳의 좌표 push하기
            visited[nr][nc] = true; // 방문 표시하기
        }
    }
}

int countArea(int n, vector<vector<char>> &board) { // 적록색약이 아닌 사람이 봤을 때 구역의 개수
    vector<vector<bool>> visited(n, vector<bool>(n, false)); // 방문 표시할 2차원 배열 false로 초기화
    int area = 0; // 구역 개수 0으로 초기화

    for (int i = 0; i < n; i++) { // 이중 for문을 돌면서
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) { // 방문했으면
                continue; // 다음으로 넘어가기
            }
            bfs(n, i, j, visited, board); // 방문하지 않았다면 bfs로 탐색하기
            area++; // 구역 개수 하나 증가
        }
    }
    return area; // 구역 개수 반환
}


int main() {
    int n; // 가로, 세로 길이(nxn)
    string s; // 입력받을 때 사용할 string 선언

    //입력
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, ' ')); // 2차원 char 벡터 ' '로 초기화
    for (int i = 0; i < n; i++) { // n번 반복문을 돌면서
        cin >> s; // string 입력받기
        for (int j = 0; j < n; j++) { // 각 string에 대해 반복문을 돌면서
            board[i][j] = s[j]; // board[i][j]에 char 넣어주기
        }
    }

    //연산 & 출력
    cout << countArea(n, board) << ' '; // 적록색약이 아닌 사람이 봤을 때 구역 개수 출력
    greenToRed(n, board); // 적록색약인 사람 시야로 변경
    cout << countArea(n, board); // 적록색약인 사람이 봤을 때 구역 개수 출력
    return 0;
}