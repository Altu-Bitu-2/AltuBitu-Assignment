#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci; // pair<int, int> 대신 ci 사용

int bfs(int n, int r, int c, vector<vector<bool>> &board) { //단지 내 집 개수 탐색하는 bfs
    int dr[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q; // 좌표를 저장할 큐 선언

    //큐 초기화
    q.push({r, c});
    board[r][c] = false; // 지도 표기를 1->0으로 바꾸어 방문 표시
    int cnt = 1; // 처음 시작점 방문했으므로 cnt=1에서 시작(cnt 초기화)
    while (!q.empty()) { // q에 원소가 남아 있는 동안 반복
        int cr = q.front().first; // 큐의 제일 앞에 있는 원소의 r(행)좌표
        int cc = q.front().second; // 큐의 제일 앞에 있는 원소의 c(열)좌표
        q.pop(); // 큐의 제일 앞에 있는 원소 제거하기

        for (int i = 0; i < 4; i++) { // 상, 하, 좌, 우 네 방향에 대해 검사하면서 연결된 곳이 있으면 queue에 넣어줌
            int nr = cr + dr[i]; // 다음 행 위치 = 현재 행 위치 + (상, 하, 좌, 우) 중 하나
            int nc = cc + dc[i]; // 다음 열 위치 = 현재 열 위치 + (상, 하, 좌, 우) 중 하나
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || !board[nr][nc]) { // 인덱스가 board 범위를 벗어나면
                continue; // 다음 방향으로 넘어가기
            }
            q.push({nr, nc}); // 큐에 다음으로 방문할 곳의 좌표 push하기
            board[nr][nc] = false; // 방문 표시하기
            cnt++; // 집 개수 1 더하기
        }
    }
    return cnt; // 단지 내 집 개수 반환
}

vector<int> cntComplex(int n, vector<vector<bool>> &board) { //단지 수와 단지 내 집 개수 구하는 함수
    vector<int> complex; // 단지 수를 저장할 벡터
    for (int i = 0; i < n; i++) { // 이중 for문으로 board[i][j]를 방문하면서
        for (int j = 0; j < n; j++) {
            if (board[i][j]) { // 만약 방문하지 않았다면
                int cnt = bfs(n, i, j, board); // bfs로 탐색하기
                complex.push_back(cnt); // complex에 단지 내 집수 삽입하기
            }
        }
    }
    return complex; // 단지 내 집 수 반환
}

int main() {
    int n; // 지도의 크기
    string s; // 입력 받을 때 사용할 string

    cin >> n; // n 입력받기
    vector<vector<bool>> board(n, vector<bool>(n, false)); // 2차원 벡터 board 선언 및 초기화
    for (int i = 0; i < n; i++) { // n까지 반복문을 돌면서
        cin >> s; // string 입력받기
        for (int j = 0; j < n; j++) { 
            board[i][j] = s[j] - '0'; // string의 각 원소를 board[i][j]에 저장하기 
        }
    }

    //연산
    vector<int> ans = cntComplex(n, board);
    sort(ans.begin(), ans.end()); // ans 오름차순 정렬

    //출력
    cout << ans.size() << '\n'; // 총 단지 수 출력
    for (int i = 0; i < ans.size(); i++) { // ans.size()까지 반복문을 돌면서
        cout << ans[i] << '\n'; // 각 단지내 집의 수 출력
    }
    return 0; // 종료
}