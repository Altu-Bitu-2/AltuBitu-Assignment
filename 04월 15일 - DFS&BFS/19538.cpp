#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &people, vector<int> &init, int n) {
    vector<int> rest(n + 1, 0); //각 사람이 루머를 믿기 위해 필요한 최소 주변인 수
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q; // 큐 선언

    for (int i = 0; i < init.size(); i++) {
        ans[init[i]] = 0; //시작 정점 초기화
        q.push(init[i]); // 큐에 최초 유포자 넣기
    }

    for (int i = 1; i <= n; i++) { // n명까지 반복문을 돌면서
        rest[i] = (people[i].size() + 1) / 2; //루머 믿어야 하는 주변인 수 초기화
    }

    while (!q.empty()) { // 큐가 빌 때까지 반복
        int curr = q.front(); //현재 사람
        int t = ans[curr]; //루머 믿은 시간
        q.pop(); // 큐 하나 pop하기

        for (int i = 0; i < people[curr].size(); i++) { // 현재 사람의 주변 관계들 방문하면서
            int next = people[curr][i]; // 다음 사람
            if (ans[next] > -1) { //이미 루머를 믿는 다면
                continue; // 다음 사람으로 넘어가기
            }
            rest[next]--; // 루머 믿는 주변인 수 하나 줄이기
            if (!rest[next]) { //주변인들 중 절반 이상이 루머를 믿으면
                ans[next] = t + 1; // t+1분 부터 루머 믿기 시작
                q.push(next); // 다음 사람 큐에 넣기
            }
        }
    }
    return ans; // 각 사람이 몇 분 후에 믿는지 저장한 벡터 반환
}


int main() {
    int n, m, input;

    //루머 퍼뜨리는 관계 입력
    cin >> n;
    vector<vector<int>> people(n + 1, vector<int>()); //주변인 관계 저장할 2차원 벡터
    for (int i = 1; i <= n; i++) {
        while (true) { // 0이 나올때까지 무한 루프 돌면서
            cin >> input; // 입력 받기
            if (!input) { // 0이면 마지막이므로 종료
                break;
            }
            people[i].push_back(input); // i번째 사람 주변인들의 번호 입력하기
        }
    }

    //최초 유포자 입력
    cin >> m;
    vector<int> init(m, 0); // 최초 유포자 저장할 벡터
    for (int i = 0; i < m; i++) { // 최초 유포자 번호 벡터에 입력하기
        cin >> init[i];
    }

    vector<int> ans = bfs(people, init, n); //연산

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' '; //출력
    }
    return 0;
}