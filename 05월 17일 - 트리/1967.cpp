#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>> &graph) {
    int pos = node, len = 0; //지름을 구성하는 노드 중 하나, 그 노드까지의 거리
    for (int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i].first; // 다음 노드
        if (next_node == parent) { // 다음 노드가 부모 노드라면
            continue; // 넘어가기
        }

        ci dfs_search = dfs(next_node, node, graph); //자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.second > len) { //기존 거리보다 길다면 갱신
            len = graph[node][i].second + dfs_search.second; // 거리 갱신
            pos = dfs_search.first; // 위치 갱신
        }
    }
    return {pos, len}; // 위치랑 길이 리턴
}


int main() {
    int n, p, c, w;

    cin >> n; //입력
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); // 0으로 초기화
    for (int i = 1; i < n; i++) { //무방향 그래프로 만들기
        cin >> p >> c >> w; // 입력
        graph[p].push_back({c, w}); // p-c의 가중치는 w 저장
        graph[c].push_back({p, w}); // c-p의 가중치는 w 저장
    }

    //연산
    ci first_node = dfs(1, -1, graph); //지름을 구성하는 노드 하나 찾기
    ci second_node = dfs(first_node.first, -1, graph); //지름을 구성하는 다른 노드 찾기

    //출력
    cout << second_node.second;
    return 0;
}