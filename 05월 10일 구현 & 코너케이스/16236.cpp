#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci& shark, vector<vector<int>>& board) {
    int dr[4] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
    int dc[4] = { 0, 0, -1, 1 };

    int min_dist = INF; // 처음에 큰 값으로 초기화
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> dist(n, vector<int>(n, 0)); //상어의 방문 여부 + 거리
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    dist[shark.first][shark.second] = 1; // 방문 여부 표시
    q.push(shark); // 상어 위치 넣기
    while (!q.empty()) { // 상어가 이동할 곳이 없을 때까지 반복
        int row = q.front().first; // 행
        int col = q.front().second; // 열
        q.pop(); // 하나 지우기

        if (dist[row][col] >= min_dist) { //최단거리 이상은 탐색할 필요 없음
            continue;
        }
        for (int i = 0; i < 4; i++) { // 4방향 탐색
            int nr = row + dr[i]; // 다음 r 위치
            int nc = col + dc[i]; // 다음 c 위치
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) {
                continue; // 갈 수 없는 곳이거나 상어보다 큰 물고기면 넘어가기
            }

            dist[nr][nc] = dist[row][col] + 1; // 거리 갱신하기
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); // list에 물고기 위치 추가하기
                min_dist = dist[nr][nc]; // 최단거리 갱신
                continue;
            }
            q.push({ nr, nc }); // 큐에 상어가 방문할 위치 넣기
        }
    }

    if (list.empty()) { //상어가 갈 수 있는 곳이 없음
        return { min_dist, {-1, -1} };
    }

    sort(list.begin(), list.end(), [](const ci& p1, const ci& p2) { //정렬 (compare 함수를 정의하지 않아도 됨)
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
        });
    return { min_dist - 1, list[0] };
}

int simulation(int n, pair<int, int>& shark, vector<vector<int>>& board) {
    int ans = 0, size = 2, cnt = 0; // 정답, 상어 초기 크기, 
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board); // 다음에 먹을 물고기 위치
        if (result.first == INF) { //더 이상 먹을 수 있는 물고기가 공간에 없다면
            break; // 종료하기
        }
        ans += result.first; // 시간 갱신
        cnt++; // 크기 증가
        if (cnt == size) { //상어 크기 증가
            cnt = 0;
            size++; // 상어 크기 증가
        }

        //상어 이동
        board[shark.first][shark.second] = 0;
        shark = result.second;  // 상어 위치
    }
    return ans; // 정답 반환
}


int main() {
    int n;
    pair<int, int> shark_pos; // 상어 위치

    //입력
    cin >> n; // nxn
    vector<vector<int>> board(n, vector<int>(n)); // 보드
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; // 공간 상태 입력 받기
            if (board[i][j] == 9) { //상어의 초기 위치
                shark_pos = make_pair(i, j); // 상어 초기 위치 따로 입력 받기
            }
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
    return 0;
}