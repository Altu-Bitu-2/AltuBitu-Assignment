#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; // pair<int, int> 대신 ci 사용

vector<vector<int>> board, visited; // 땅, 방문 체크할 2차원 벡터
queue<ci> countries; // 나라 좌표 저장할 큐


//각 연합의 인구 수만큼 인구 이동하는 함수
void movePeople(int population, vector<ci> &union_cord) {
    for (int i = 0; i < union_cord.size(); i++) { // 연합 수만큼 반복문을 돌면서
        int row = union_cord[i].first, col = union_cord[i].second; // 연합국의 r, c 좌표 획득하기
        board[row][col] = population; // 새로운 인구 수 넣어주기
        countries.push({row, col}); //인구 이동이 있는 나라는 다음에도 인구 이동 가능성 있음
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<ci> union_cord; //연합 저장할 벡터
    union_cord.push_back({cr, cc}); // 처음엔 연합에 cr, cc 저장함
    queue<ci> q; // 큐 선언
    q.push({cr, cc}); // 큐에도 cr, cc 넣어줌
    int sum = board[cr][cc], cnt = 1; // sum 초깃값은 board[cr][cc]의 인구 수, 연합 하나니까 1로 초기화
    while (!q.empty()) { // 큐가 빌 때까지 반복
        cr = q.front().first; // 제일 앞 원소의 r값
        cc = q.front().second; // 제일 앞 원소의 c 값
        q.pop(); // 하나 pop하기 

        for (int i = 0; i < 4; i++) { // 4번 for문 돌면서 상, 하, 좌, 우 검사
            int nr = cr + dr[i]; // 다음 행 위치 (현재 r값 + 다음 방향)
            int nc = cc + dc[i]; // 다음 열 위치 (현재 c값 + 다음 방향)
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) { // 인덱스가 board 크기를 벗어나거나 방문했다면
                continue; // 다음으로 넘어가기
            }
            int diff = abs(board[nr][nc] - board[cr][cc]); // 인접한 국가와 인구 차이 계산
            if (diff >= l && diff <= r) { //국경선 열림
                q.push({nr, nc}); // 연합인 국가 좌표 큐에 넣기
                visited[nr][nc] = day; // 일 수로 방문 표시
                union_cord.push_back({nr, nc}); //연합에 추가
                sum += board[nr][nc]; // sum에 연합국가 인구 수 추가
                cnt++; // 연합 국가 개수 추가
            }
        }
    }
    if (cnt > 1) { //연합이 생겼다면
        movePeople(sum / cnt, union_cord); //인구 이동
        return true; // 연합이 생겼다면 true 리턴
    }
    return false; // 연합이 생기지 않은 경우 false 리턴
}

int simulation(int n, int l, int r) {
    int day = 0; //방문 체크로도 사용
    while (true) { // 무한 반복하면서
        day++; // 일 수 하루 증가시키기
        bool is_move = false; //인구 이동 했는지 체크
        int size = countries.size(); //이번 시간에 탐색할 수 있는 나라의 수
        while (size--) { // 
            int row = countries.front().first; // 큐의 제일 앞에 있는 원소의 행 좌표
            int col = countries.front().second;  // 큐의 제일 앞에 있는 원소의 열 좌표
            countries.pop(); // 제일 앞 원소 제거하기
            if (visited[row][col] == day) { //이미 탐색한 나라라면
                continue; // 다음으로 넘어가기
            }
            visited[row][col] = day;
            if (bfs(n, l, r, row, col, day)) {
                is_move = true;
            }
        }
        if (!is_move) {// 인구 이동하지 않은 경우
            return day - 1; // day-1 리턴
        }
    }
}

int main() {
    int n, l, r; // 땅 크기, 인구 차이 하한선, 상한선

    cin >> n >> l >> r; // 입력 받기
    board.assign(n, vector<int>(n, 0)); // 2차원 벡터 board nxn 0으로 초기화
    visited.assign(n, vector<int>(n, 0)); // 2차원 벡터 visited nxn 0으로 초기화
    for (int i = 0; i < n; i++) { // nxn크기의 board를 이중 for문 돌면서
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; // 인구 수 입력받기
            countries.push({i, j}); // 처음에는 모든 나라의 좌표를 큐에 저장하기
        }
    }

    cout << simulation(n, l, r); //연산 & 출력
    return 0;
}