#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 1e5; // 최대 사이즈

int bfs(int n, int k) {
    vector<int> check(SIZE + 1, 0); // 최대 사이즈만큼 0으로 초기화한 벡터, 방문체크 + 시간 체크할 때 사용
    queue<int> q; //큐에 좌표값 저장
    int ans = 0; // 시간 0으로 초기화

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    q.push(n); // 수빈 현재 위치 넣기
    while (!q.empty()) { // 큐가 빌 때까지 반복
        int x = q.front(); // 큐 제일 앞 원소의 위치
        q.pop(); // 하나 pop 하기

        if (x == k) { // x가 동생 위치라면
            ans = check[x] - 1; // 정답은 check[x]에 저장된 시간 -1
            break; // 정답 찾았으므로 종료
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //자식 노드
        for (int i = 0; i < 3; i++) { // 이동할 수 있는 세 위치에 대해
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) { // 방문할 수 있는 위치이고, 방문하지 않았다면
                check[child[i]] = check[x] + 1; // (방문) + (현재위치까지 걸린 시간+1) 표시
                q.push(child[i]); // 다음 위치 큐에 넣어주기
            }
        }
    }
    return ans; // 가장 빠른 시간 리턴
}


int main() {
    int n, k; // 수빈 위치, 동생 위치

    //입력
    cin >> n >> k;

    //연산 & 출력
    cout << bfs(n, k);
    return 0;
}