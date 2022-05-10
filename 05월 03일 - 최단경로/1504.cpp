#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; // 거리(가중치), 노드 번호
const int INF = 1e5 * 8 * 3; //최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

//다익스트라
vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) { // 시작 노드, 정점 개수, 그래프
    vector<int> dist(v + 1, INF); // 가중치 INF로 초기화
    priority_queue<ci, vector<ci>, greater<>> pq; // 다음에 방문할 곳 저장, (거리, 노드)
    // 작은 값을 먼저 방문해야하므로 최소힙으로 구현

    dist[start] = 0; // 시작 노드 0으로 초기화
    pq.push({0, start}); // 
    while (!pq.empty()) { // pq가 빌 때까지 반복
        int weight = pq.top().first; // 첫번째 값은 비용
        int node = pq.top().second; // 두 번째 값은 node 정점 번호
        pq.pop(); // 하나 제거하기

        if (weight > dist[node]) { // 기존 비용이 더 작다면 갱신할 필요가 없으므로
            continue; // 다음으로 넘어가기
        }
        for (int i = 0; i < graph[node].size(); i++) { // 연결된 노드들을 모두 확인하며
            int next_node = graph[node][i].first; // 다음 노드
            int next_weight = weight + graph[node][i].second; // 다음 노드 가중치
            if (next_weight < dist[next_node]) { // 기존 비용보다 작다면 갱신
                dist[next_node] = next_weight; // 거리 갱신
                pq.push({next_weight, next_node}); // pq에 저장
            }
        }
    }
    return dist; // 거리 배열 반환
}


int main() {
    int n, e, a, b, c, v1, v2; // 정점, 간선, 정점 a, 정점 b, 비용, 지나갈 정점 v1, v2

    //입력
    cin >> n >> e;

    vector<vector<ci>> graph(n + 1, vector<ci>(0)); // 정점
    vector<vector<int>> dist(3, vector<int>(n + 1, 0)); // 거리
    while (e--) { //무방향 그래프
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c); // a->b :c 저장
        graph[b].emplace_back(a, c); // b->a :c 저장
    }
    cin >> v1 >> v2; // 지나갈 정점 입력

    //연산
    vector<int> start_nodes = {1, v1, v2};
    for (int i = 0; i < 3; i++) { //1, v1, v2에서 시작한 다익스트라 결과 저장
        dist[i] = dijkstra(start_nodes[i], n, graph);
    }

    //1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
    //무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값!
    int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

    //출력
    cout << ((ans >= INF) ? -1 : ans); // 불가능하면 -1 출력
    return 0;
}